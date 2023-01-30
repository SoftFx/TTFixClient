#include "stdafx.h"
#include <map>
#include <sstream>

#include "FixMessage.h"
#include "FieldNumbers.h"
#include "FixFieldFormatter.h"

using namespace std;

namespace
{
    const string cNumber = "number";
    const string cName = "name";
    const string cType = "type";
    const string cEnum = "enum";
    const string cDescription = "description";

    const char* FindSubstring(const string& line, const char* substring, const size_t offset)
    {
        const size_t index = line.find(substring);
        if (string::npos == index)
        {
            return nullptr;
        }
        const char* result = line.c_str() + index + offset;
        return result;
    }

    template<size_t count> const char* FindSubstring(const string& line, const char(&buffer)[count])
    {
        return FindSubstring(line, buffer, count - 1);
    }

    bool ProcessField(const string& line, int& number, string& name)
    {
        const char* stNumber = FindSubstring(line, "number='");
        if (nullptr == stNumber)
        {
            return false;
        }
        number = atoi(stNumber);
        const char* stAccountBegin = FindSubstring(line, "name='");
        if (nullptr == stAccountBegin)
        {
            return false;
        }
        const char* stAccountEnd = strchr(stAccountBegin, '\'');
        if (nullptr == stAccountEnd)
        {
            return false;
        }
        name.assign(stAccountBegin, stAccountEnd);
        return true;
    }

    bool ProcessEnum(const string& line, string& key, string& value)
    {
        const char* stKeyBegin = FindSubstring(line, "enum='");
        if (nullptr == stKeyBegin)
        {
            return false;
        }
        const char* stKeyEnd = strchr(stKeyBegin, '\'');
        if (nullptr == stKeyEnd)
        {
            return false;
        }
        const char* stValueBegin = FindSubstring(line, "description='");
        if (nullptr == stValueBegin)
        {
            return false;
        }
        const char* stValueEnd = strchr(stValueBegin, '\'');
        if (nullptr == stValueEnd)
        {
            return false;
        }
        key.assign(stKeyBegin, stKeyEnd);
        value.assign(stValueBegin, stValueEnd);
        return true;
    }

    map<int, TTFixFeedClient::FixFieldFormatter> gFormatters;

    const char* ReadKey(const char* text, int32_t& key)
    {
        key = atoi(text);
        for (;; ++text)
        {
            const char ch = *text;
            if ('\0' == ch)
            {
                return text;
            }
            if ('=' == ch)
            {
                return (text + 1);
            }
        }
    }
    const char* ReadValue(const char* text, string& value)
    {
        for (;; ++text)
        {
            const char ch = *text;
            if ('\0' == ch)
            {
                return text;
            }
            if (1 == ch)
            {
                return (text + 1);
            }
            value += ch;
        }
    }
}

namespace TTFixFeedClient
{
    FixMessage::FixMessage(const std::string& text) : m_text(text)
    {

    }

    void FixMessage::LoadDictionary(const std::string& dictFile)
    {
        std::stringstream dictionary;
        std::ifstream file(dictFile);

        if (file)
        {
            dictionary << file.rdbuf();
            file.close();
        }
        else
        {
            throw std::exception("Error loading dictionary");
        }

        string line;
        for (getline(dictionary, line); !dictionary.eof() && dictionary.good(); getline(dictionary, line))
        {
            const size_t index = line.find("<fields>");
            if (string::npos != index)
            {
                break;
            }
        }

        int number = 0;
        string name;
        string key;
        string value;

        FixFieldFormatter* pFormatter = nullptr;

        for (getline(dictionary, line); !dictionary.eof() && dictionary.good(); getline(dictionary, line))
        {
            if (ProcessField(line, number, name))
            {
                FixFieldFormatter& formatter = gFormatters[number];
                formatter = FixFieldFormatter(name);
                pFormatter = &formatter;
            }
            else if (ProcessEnum(line, key, value))
            {
                if (nullptr != pFormatter)
                {
                    pFormatter->AddEnum(key, value);
                }
            }
        }

        FixFieldFormatter& msgType = gFormatters[FIX::FIELD::MsgType];
        FixFieldFormatter& refMsgType = gFormatters[FIX::FIELD::RefMsgType];

        refMsgType.AddEnums(msgType);
    }

    bool FixMessage::Format(std::ostream& stream)const
    {
        size_t length = 0;
        const char* text = &*m_text.begin();
        for (; 0 != *text;)
        {
            int32_t key = 0;
            text = ReadKey(text, key);
            if (0 == key)
            {
                return false;
            }
            string value;
            if (FIX::FIELD::RawData != key)
            {
                text = ReadValue(text, value);
            }
            else
            {
                value = "<DATA>";
                text += (1 + length);
                length = 0;
            }
            if (FIX::FIELD::RawDataLength == key)
            {
                length = atoi(value.c_str());
            }
            auto it = gFormatters.find(key);
            if (gFormatters.end() == it)
            {
                stream << key << '=' << value;
            }
            else
            {
                it->second.Format(value, stream);
            }
            stream << ' ';
        }
        return true;
    }

    std::ostream& operator<<(std::ostream& stream, const FixMessage& message)
    {
        stringstream temp;
        if (message.Format(temp))
        {
            const string st = temp.str();
            stream << st;
        }
        else
        {
            stream << message.Text();
        }
        return stream;
    }

    std::wostream& operator<<(std::wostream& stream, const FixMessage& message)
    {
        stringstream temp;
        if (message.Format(temp))
        {
            const string st = temp.str();
            stream << st.c_str();
        }
        else
        {
            stream << message.Text().c_str();
        }
        return stream;
    }
}
