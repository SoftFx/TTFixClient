#ifndef FEED_CLIENT_APPLICATION_H
#define FEED_CLIENT_APPLICATION_H

#include "Application.h"
#include "Mutex.h"
#include "Session.h"
#include "Values.h"
#include "FIX44/MessageCracker.h"
#include "FIX44/Logon.h"
#include "FIX44/TradingSessionStatus.h"
#include "FIX44/TwoFactorLogon.h"
#include "FIX44/AccountInfoRequest.h"
#include "FIX44/AccountInfo.h"
#include "FIX44/OrderMassStatusRequest.h"
#include "FIX44/RequestForPositions.h"
#include "FIX44/RequestForPositionsAck.h"
#include "FIX44/PositionReport.h"
#include "FIX44/NewOrderSingle.h"
#include "FIX44/ExecutionReport.h"
#include "FIX44/OrderCancelReplaceRequest.h"
#include "FIX44/OrderCancelRequest.h"

namespace TTFixTradeClient
{
    std::string CreateGUID();

    class FixTradeClient :
        public FIX::Application,
        public FIX44::MessageCracker
    {
        std::string m_username;
        std::string m_password;
        std::string m_deviceId;
        std::string m_appSessionId;
        const FIX::SessionID* m_sessionId;
        std::vector<std::string> m_symbols;
        bool m_subscribedAll;

    public:
        FixTradeClient(std::string username, std::string password, std::string deviceId, std::string appSessionId) :
            m_username(username),
            m_password(password),
            m_deviceId(deviceId),
            m_appSessionId(appSessionId),
            m_sessionId(nullptr),
            m_subscribedAll(false)
        {
        }

        void run();

    private:
        void onCreate(const FIX::SessionID&) {}
        void onLogon(const FIX::SessionID&);
        void onLogout(const FIX::SessionID&);

        void onMessage(const FIX44::TwoFactorLogon&, const FIX::SessionID&);
        void onMessage(const FIX44::TradingSessionStatus&, const FIX::SessionID&);
        void onMessage(const FIX44::AccountInfo&, const FIX::SessionID&);
        void onMessage(const FIX44::ExecutionReport&, const FIX::SessionID&);
        void onMessage(const FIX44::PositionReport&, const FIX::SessionID&);

        void fromAdmin(const FIX::Message&, const FIX::SessionID&) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon);
        void fromApp(const FIX::Message&, const FIX::SessionID&) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType);
        void toAdmin(FIX::Message&, const FIX::SessionID&);
        void toApp(FIX::Message&, const FIX::SessionID&) throw(FIX::DoNotSend);
    };
}

#endif
