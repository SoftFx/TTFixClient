#pragma once

#include "Log.h"
#include "FileLog.h"
#include "SessionSettings.h"
#include <fstream>
#include <regex>

namespace StringUtils
{
    std::wstring& Utf8ToStd(std::wstring& dest, const std::string& src);
    std::wstring StringToWString(const std::string& s);
}

namespace TTFixTradeClient
{
    class FixFileLogFactory : public FIX::LogFactory
    {
    public:
        FixFileLogFactory(const std::wstring& path, const std::wstring& eventsFileName, const std::wstring& messagesFileName, const std::string& excludeMessagesFromLogs, const bool decodeFixMessages)
            : m_path(path), m_eventsFileName(eventsFileName), m_messagesFileName(messagesFileName),
            m_excludeMessagesFromLogs(excludeMessagesFromLogs), m_decodeFixMessages(decodeFixMessages) {};
    public:
        FIX::Log* create();
        FIX::Log* create(const FIX::SessionID&);
        void destroy(FIX::Log* log);
    private:
        const std::wstring m_path;
        const std::wstring m_eventsFileName;
        const std::wstring m_messagesFileName;
        const std::string m_excludeMessagesFromLogs;
        const bool m_decodeFixMessages;
    };

    enum LogEntryType
    {
        LogEntryType_Incomming,
        LogEntryType_Outgoing,
        LogEntryType_Event
    };

    class LogEntry
    {
    public:
        LogEntryType Type;
        FIX::UtcTimeStamp TimeStamp;
        std::string Value;
    public:
        LogEntry(const LogEntryType type, const std::string& value);
    };

    class FixFileLog : public FIX::Log
    {
    public:
        FixFileLog(const std::wstring& eventsPath, const std::wstring& messagesPath, const std::string& excludeMessagesFromLogs, bool decodeFixMessages);
        virtual ~FixFileLog();
    private:
        void Construct();
    public:
        void clear();
        void backup();
        void onIncoming(const std::string& value);
        void onOutgoing(const std::string& value);
        void onEvent(const std::string& value);
        bool getMillisecondsInTimeStamp() const;
        void setMillisecondsInTimeStamp(bool value);
    private:
        static THREAD_PROC ThreadMethod(void* p);
        void Loop();
        void Step();
        void Add(const LogEntryType type, const std::string& value);
    private:
        bool ExcludeFromLogs(const std::string& value)const;
        std::string RemovePasswordValue(const std::string& value)const;
    private:
        bool m_eventsEnabled;
        bool m_messagesEnabled;
        std::wofstream m_messages;
        std::wofstream m_event;
        bool m_decodeFixMessages;
        std::regex* m_pattern;
    private:
        FIX::thread_id m_thread;
        HANDLE m_semaphore;
        volatile bool m_continue;
        FIX::Mutex m_synchronizer;
        std::vector<LogEntry> m_first;
        std::vector<LogEntry> m_second;

        const std::regex m_passwordFieldRegex;
        const std::string m_passwordReplacement;
    };

}

