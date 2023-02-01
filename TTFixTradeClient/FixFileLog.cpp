#include "stdafx.h"
#include <cassert>
#include <filesystem>
#include "FixFileLog.h"
#include "FixMessage.h"

namespace StringUtils
{
    inline std::wstring& Utf8ToStd(std::wstring& dest, const std::string& src)
    {
        if (!src.length())
        {
            dest = L"";
            return dest;
        }

        int result = MultiByteToWideChar(CP_UTF8, 0, src.data(), src.length(), 0, 0);

        if (!result)
            throw std::logic_error("Invalid string to convert from UTF-8");

        dest.resize(result);

        result = MultiByteToWideChar(CP_UTF8, 0, src.data(), src.length(), const_cast<wchar_t*>(dest.data()), dest.length());

        if (!result)
            throw std::logic_error("Invalid string to convert from UTF-8");

        return dest;
    }

    inline std::wstring StringToWString(const std::string& s)
    {
        std::wstring utf8String;
        std::wstring result = Utf8ToStd(utf8String, s);

        return result;
    }

    std::wstring generatePrefix(const FIX::SessionID& s)
    {
        const std::wstring& begin =
            StringToWString(s.getBeginString().getString());
        const std::wstring& sender =
            StringToWString(s.getSenderCompID().getString());
        const std::wstring& target =
            StringToWString(s.getTargetCompID().getString());
        const std::wstring& qualifier =
            StringToWString(s.getSessionQualifier());

        std::wstring prefix = begin + L"-" + sender + L"-" + target;
        if (qualifier.size())
            prefix += L"-" + qualifier;

        return prefix;
    }

    std::wstring CombinePath(const std::wstring& directory, const std::wstring& pathPart)
    {
        //wchar_t buffer[MAX_PATH] = L"";
        //const wchar_t* result = PathCombineW(buffer, directory.c_str(), path.c_str());
        //if (nullptr == result)
        //{
        //    std::string message = std::string("Couldn't combine path!");
        //    throw std::runtime_error(message);
        //}
        std::wstring result = directory + L"\\" + pathPart;
        return result;
    }
}

namespace TTFixTradeClient
{
    FIX::Log* FixFileLogFactory::create()
    {
        FIX::Log* result = new FIX::NullLog();
        return result;
    }

    FIX::Log* FixFileLogFactory::create(const FIX::SessionID& s)
    {
        std::wstring eventsPath;
        std::wstring messagesPath;

        std::wstring eventsFileName = m_eventsFileName;
        std::wstring messagesFileName = m_messagesFileName;

        if (!m_path.empty())
        {
            if (eventsFileName.empty())
            {
                eventsFileName = StringUtils::generatePrefix(s) + L".events.log";
            }
            if (messagesFileName.empty())
            {
                messagesFileName = StringUtils::generatePrefix(s) + L".messages.log";
            }
        }
        if (!eventsFileName.empty())
        {
            eventsPath = StringUtils::CombinePath(m_path, eventsFileName);
        }
        if (!messagesFileName.empty())
        {
            messagesPath = StringUtils::CombinePath(m_path, messagesFileName);
        }
        return new FixFileLog(eventsPath, messagesPath, m_excludeMessagesFromLogs, m_decodeFixMessages);
    }

    void FixFileLogFactory::destroy(FIX::Log* pLog)
    {
        delete pLog;
    }

    LogEntry::LogEntry(const LogEntryType type, const std::string& value) : Type(type), Value(value)
    {
    }

    FixFileLog::FixFileLog(const std::wstring& eventsPath, const std::wstring& messagesPath, const std::string& excludeMessagesFromLogs, bool decodeFixMessages)
        : m_eventsEnabled()
        , m_messagesEnabled()
        , m_decodeFixMessages(decodeFixMessages)
        , m_pattern(nullptr)
        , m_thread()
        , m_semaphore()
        , m_continue()
        , m_passwordFieldRegex("(\\cA)(554|925)=[^\\cA]+(\\cA)")
        , m_passwordReplacement("$1$2=*****$3")
    {
        if (!eventsPath.empty())
        {
            m_event.open(eventsPath.c_str(), std::ios::out | std::ios::app);
            if (!m_event.is_open())
            {
                throw FIX::ConfigError("Could not open event file!");
            }
        }
        if (!messagesPath.empty())
        {
            m_messages.open(messagesPath.c_str(), std::ios::out | std::ios::app);
            if (!m_messages.is_open())
            {
                throw FIX::ConfigError("Could not open messages file!");
            }
        }

        if (!excludeMessagesFromLogs.empty())
        {
            m_pattern = new std::regex(excludeMessagesFromLogs);
        }

        m_eventsEnabled = !eventsPath.empty();
        m_messagesEnabled = !messagesPath.empty();

        Construct();
    }

    void FixFileLog::Construct()
    {
        m_continue = true;
        m_semaphore = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        if (nullptr == m_semaphore)
        {
            throw std::runtime_error("Couldn't create new event");
        }
        if (!thread_spawn(&FixFileLog::ThreadMethod, this, m_thread))
        {
            CloseHandle(m_semaphore);
            throw std::runtime_error("Couldn't spawn new thread");
        }

    }

    THREAD_PROC FixFileLog::ThreadMethod(void* p)
    {
        try
        {
            FixFileLog* pThis = reinterpret_cast<FixFileLog*>(p);
            pThis->Loop();
            return 0;
        }
        catch (...)
        {
            return 1;
        }
    }

    void FixFileLog::Loop()
    {
        for (WaitForSingleObject(m_semaphore, INFINITE); m_continue; WaitForSingleObject(m_semaphore, INFINITE))
        {
            Step();
        }
        Step();
    }

    void FixFileLog::Step()
    {
        m_second.clear();

        {
            FIX::Locker lock(m_synchronizer);
            std::swap(m_first, m_second);
        }

        for each (const auto & element in m_second)
        {
            if (LogEntryType_Incomming == element.Type)
            {
                m_messages << FIX::UtcTimeStampConvertor::convert(element.TimeStamp, true).c_str() << " : incoming> ";
                if (m_decodeFixMessages)
                {
                    m_messages << FixMessage(element.Value);
                }
                else
                {
                    m_messages << element.Value.c_str();
                }
                m_messages << std::endl << std::endl;
            }
            else if (LogEntryType_Outgoing == element.Type)
            {
                m_messages << FIX::UtcTimeStampConvertor::convert(element.TimeStamp, true).c_str() << " : outgoing> ";
                if (m_decodeFixMessages)
                {
                    m_messages << FixMessage(element.Value);
                }
                else
                {
                    m_messages << element.Value.c_str();
                }
                m_messages << std::endl << std::endl;
            }
            else
            {
                assert(LogEntryType_Event == element.Type);
                m_event << FIX::UtcTimeStampConvertor::convert(element.TimeStamp, true).c_str() << " : event> " << element.Value.c_str() << std::endl;
            }
        }
        m_second.clear();
    }

    FixFileLog::~FixFileLog()
    {
        m_continue = false;
        SetEvent(m_semaphore);

        FIX::thread_join(m_thread);

        m_messages.close();
        m_event.close();
        if (nullptr != m_pattern)
        {
            delete m_pattern;
            m_pattern = nullptr;
        }
    }

    void FixFileLog::clear()
    {
    }

    void FixFileLog::backup()
    {
    }

    void FixFileLog::onIncoming(const std::string& value)
    {
        if (m_messagesEnabled)
        {
            if (ExcludeFromLogs(value))
            {
                return;
            }
            Add(LogEntryType_Incomming, value);
        }
    }

    void FixFileLog::onOutgoing(const std::string& value)
    {
        if (m_messagesEnabled)
        {
            if (ExcludeFromLogs(value))
            {
                return;
            }
            // Neat solution would be adding configurable regex for removing / replacing specific fields like it's done for messages
            Add(LogEntryType_Outgoing, RemovePasswordValue(value));
        }
    }

    void FixFileLog::onEvent(const std::string& value)
    {
        if (m_eventsEnabled)
        {
            Add(LogEntryType_Event, value);
        }
    }

    std::string FixFileLog::RemovePasswordValue(const std::string& value)const
    {
        return std::regex_replace(value, m_passwordFieldRegex, m_passwordReplacement);
    }

    void FixFileLog::Add(const LogEntryType type, const std::string& value)
    {
        LogEntry entry(type, value);
        bool isEmpty = false;
        {
            FIX::Locker lock(m_synchronizer);
            isEmpty = m_first.empty();
            m_first.push_back(entry);
        }
        if (isEmpty)
        {
            SetEvent(m_semaphore);
        }
    }

    bool FixFileLog::ExcludeFromLogs(const std::string& value)const
    {
        if (nullptr == m_pattern)
        {
            return false;
        }
        size_t start = value.find("35=");
        if (std::string::npos == start)
        {
            return false;
        }
        start += 3;
        size_t finish = value.find(1, start);
        if (std::string::npos == finish)
        {
            return false;
        }
        std::string st = value.substr(start, finish - start);
        const bool result = std::regex_match(st, *m_pattern);
        return result;
    }
}