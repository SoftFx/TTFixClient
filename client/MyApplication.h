/* -*- C++ -*- */

/****************************************************************************
** Copyright (c) quickfixengine.org  All rights reserved.
**
** This file is part of the QuickFIX FIX Engine
**
** This file may be distributed under the terms of the quickfixengine.org
** license as defined by quickfixengine.org and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.quickfixengine.org/LICENSE for licensing information.
**
** Contact ask@quickfixengine.org if any conditions of this licensing are
** not clear to you.
**
****************************************************************************/

#ifndef TRADECLIENT_APPLICATION_H
#define TRADECLIENT_APPLICATION_H

#include "Application.h"
#include "Mutex.h"
#include "Session.h"
#include "Values.h"
#include "FIX44/Logon.h"
#include "FIX44/MessageCracker.h"
#include "FIX44/TwoFactorLogon.h"
#include "Fix44/MarketDataHistoryInfoRequest.h"
#include "Fix44/MarketDataHistoryInfoReport.h"
#include "FIX44/CurrencyListRequest.h"
#include "FIX44/SecurityListRequest.h"
#include "FIX44/MarketDataRequestAck.h"
#include "FIX44/MarketDataSnapshotFullRefresh.h"

class MyApplication :
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
    MyApplication(std::string username, std::string password, std::string deviceId, std::string appSessionId) :
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
    void onMessage(const FIX44::MarketDataHistoryInfoReport&, const FIX::SessionID&);
    void onMessage(const FIX44::CurrencyList&, const FIX::SessionID&);
    void onMessage(const FIX44::SecurityList&, const FIX::SessionID&);
    void onMessage(const FIX44::MarketDataRequestAck&, const FIX::SessionID&);
    void onMessage(const FIX44::MarketDataSnapshotFullRefresh&, const FIX::SessionID&);

    void fromAdmin(const FIX::Message&, const FIX::SessionID&) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon);
    void fromApp(const FIX::Message&, const FIX::SessionID&) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType);
    void toAdmin(FIX::Message&, const FIX::SessionID&);
    void toApp(FIX::Message&, const FIX::SessionID&) throw(FIX::DoNotSend);
};

#endif
