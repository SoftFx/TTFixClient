#pragma once

namespace TTFixTradeClient
{
    class FixMessage
    {
    public:
        explicit FixMessage(const std::string& text);
    private:
        FixMessage& operator = (const FixMessage&);
    public:
        static void LoadDictionary(const std::string& text);
        const std::string& Text()const;
    private:
        bool Format(std::ostream& stream)const;
    private:
        const std::string& m_text;
    private:
        friend std::ostream& operator << (std::ostream& stream, const FixMessage& message);
        friend std::wostream& operator << (std::wostream& stream, const FixMessage& message);
    };

#pragma region inline methods
    inline const std::string& FixMessage::Text() const
    {
        return m_text;
    }
#pragma endregion
}
