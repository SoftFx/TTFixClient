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
#include "FIX44/CurrencyListRequest.h"
#include "FIX44/CurrencyList.h"
#include "FIX44/SecurityListRequest.h"
#include "FIX44/SecurityList.h"
#include "FIX44/MarketDataRequest.h"
#include "FIX44/MarketDataRequestAck.h"
#include "FIX44/MarketDataSnapshotFullRefresh.h"
#include "FIX44/MarketDataHistoryRequest.h"
#include "FIX44/MarketDataHistory.h"
#include "Fix44/MarketDataHistoryMetadataRequest.h"
#include "Fix44/MarketDataHistoryMetadataReport.h"
#include "Fix44/MarketDataHistoryInfoRequest.h"
#include "Fix44/MarketDataHistoryInfoReport.h"
#include "Fix44/ComponentsInfoRequest.h"
#include "Fix44/ComponentsInfoReport.h"
#include "Fix44/FileChunkReq.h"
#include "Fix44/FileChunk.h"

namespace TTFixFeedClient
{
    class FixFeedClient :
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
        FixFeedClient(std::string username, std::string password, std::string deviceId, std::string appSessionId) :
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
        void onMessage(const FIX44::CurrencyList&, const FIX::SessionID&);
        void onMessage(const FIX44::SecurityList&, const FIX::SessionID&);
        void onMessage(const FIX44::MarketDataRequestAck&, const FIX::SessionID&);
        void onMessage(const FIX44::MarketDataSnapshotFullRefresh&, const FIX::SessionID&);
        void onMessage(const FIX44::MarketDataHistory&, const FIX::SessionID&);
        void onMessage(const FIX44::MarketDataHistoryMetadataReport&, const FIX::SessionID&);
        void onMessage(const FIX44::MarketDataHistoryInfoReport&, const FIX::SessionID&);
        void onMessage(const FIX44::ComponentsInfoReport&, const FIX::SessionID&);
        void onMessage(const FIX44::FileChunk&, const FIX::SessionID&);

        void fromAdmin(const FIX::Message&, const FIX::SessionID&) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon);
        void fromApp(const FIX::Message&, const FIX::SessionID&) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType);
        void toAdmin(FIX::Message&, const FIX::SessionID&);
        void toApp(FIX::Message&, const FIX::SessionID&) throw(FIX::DoNotSend);
    };
}

#endif
