#include "stdafx.h"
#include "FixFieldFormatter.h"
using namespace std;

namespace TTFixFeedClient
{
    /// <summary>
    /// map requires this constructor
    /// </summary>
    FixFieldFormatter::FixFieldFormatter()
    {
    }

    FixFieldFormatter::FixFieldFormatter(const string& name) : m_name(name)
    {
    }

    void FixFieldFormatter::AddEnum(const std::string& key, const std::string& value)
    {
        m_enums[key] = value;
    }

    void FixFieldFormatter::Format(const std::string& st, ostream& stream) const
    {
        stream << m_name << "=";
        auto it = m_enums.find(st);
        if (it == m_enums.end())
        {
            stream << st;
        }
        else
        {
            stream << it->second;
        }
    }

    void FixFieldFormatter::AddEnums(const FixFieldFormatter& formatter)
    {
        m_enums.insert(formatter.m_enums.begin(), formatter.m_enums.end());
    }
}
