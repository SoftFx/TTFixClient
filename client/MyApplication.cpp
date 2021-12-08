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

#include "stdafx.h"

#ifdef _MSC_VER
#pragma warning( disable : 4503 4355 4786 )
#else
#include "config.h"
#endif

#include "MyApplication.h"
#include "FIX44/CurrencyList.h"
#include "FIX44/SecurityList.h"
#include "FIX44/MarketDataRequest.h"

void MyApplication::onLogon(const FIX::SessionID& sessionId)
{
    std::cout << std::endl << "Logon - " << sessionId << std::endl;
    m_sessionId = &sessionId;
}

void MyApplication::onLogout(const FIX::SessionID& sessionId)
{
    std::cout << std::endl << "Logout - " << sessionId << std::endl;
    m_sessionId = nullptr;
}

void MyApplication::onMessage(const FIX44::TwoFactorLogon &msg, const FIX::SessionID &sessionId)
{
  FIX::TwoFactorReason reason;
  msg.get(reason);
  char r = reason.getValue();

    FIX::Text text;
    msg.get(text);

    std::cout << std::endl << "TwoFactorLogon received - " << text.getValue() << std::endl;

    if (r == FIX::TwoFactorReason_SERVER_REQUEST)
    {
        std::cout << std::endl << "Enter One-time password: " << std::endl;

        std::string otp;
        std::getline(std::cin, otp);

        FIX44::TwoFactorLogon response(FIX::TwoFactorReason_CLIENT_RESPONSE);
        response.setField(FIX::OneTimePassword(otp));
        FIX::Session::sendToTarget(response, sessionId);
    }
    else if (r == FIX::TwoFactorReason_SERVER_SUCCESS)
        std::cout << std::endl << "One-time password was successfully validated!" << std::endl;
    else if (r == FIX::TwoFactorReason_SERVER_ERROR)
        std::cout << std::endl << "Failed to validate One-time password!" << std::endl;
    else
        std::cout << std::endl << "Invalid two factor reason!" << std::endl;
}

void MyApplication::onMessage( const FIX44::TradingSessionStatus& msg, const FIX::SessionID& sessionId)
{
    std::cout << std::endl << "TradingSessionStatus received!" << std::endl;
}

void MyApplication::onMessage(const FIX44::MarketDataHistoryInfoReport& msg, const FIX::SessionID& sessionId)
{
    std::cout << std::endl << "MarketDataHistoryInfoReport received!" << std::endl;
}

void MyApplication::onMessage(const FIX44::CurrencyList& msg, const FIX::SessionID&)
{
    std::cout << std::endl << "CurrencyList: " << msg << std::endl;
}

void MyApplication::onMessage(const FIX44::SecurityList& msg, const FIX::SessionID&)
{
    std::cout << std::endl << "SecurityList: " << msg << std::endl;

    FIX::NoRelatedSym noSym;
    msg.get(noSym);
    int count = noSym.getValue();
    for (int i = 1; i <= count; i++)
    {
        FIX44::SecurityList::NoRelatedSym symGrp;
        msg.getGroup(i, symGrp);
        FIX::Symbol symbol;
        symGrp.get(symbol);
        m_symbols.push_back(symbol.getValue());
    }
}

void MyApplication::onMessage(const FIX44::MarketDataRequestAck& msg, const FIX::SessionID&)
{
    FIX::TotalNumMarketSnaps total;
    msg.get(total);
    std::cout << std::endl << "Subscribed. Total number of snapshots returned " << total.getValue() << std::endl;
}

void MyApplication::onMessage(const FIX44::MarketDataSnapshotFullRefresh& msg, const FIX::SessionID&)
{
    FIX::Symbol symbol;
    FIX::OrigTime origTime;
    FIX::TickId tickId;
    FIX::IndicativeTick indicative;
    FIX::NoMDEntries noMDEntries;

    msg.get(symbol);
    msg.get(origTime);
    msg.get(tickId);
    msg.get(indicative);
    std::string ind_str = indicative.getValue() == 1 ? "indicative" : "";

    std::stringstream ss;
    ss << symbol.getValue() << " " << tickId.getValue() << " " << ind_str;

    msg.get(noMDEntries);
    int count = noMDEntries.getValue();
    for (int i = 1; i <= count; i++)
    {
        FIX::MDEntryType type;
        FIX::MDEntryPx price;
        FIX::MDEntrySize volume;

        FIX44::MarketDataSnapshotFullRefresh::NoMDEntries entry;
        msg.getGroup(i, entry);
        entry.get(type);
        entry.get(price);
        entry.get(volume);
        std::string type_str = type.getValue() == '0' ? " Bid: " : " Ask: ";
        ss << type_str << price.getValue() << " " << volume.getValue();
    }

    std::cout << std::endl << ss.str() << std::endl;
}

void MyApplication::fromAdmin( const FIX::Message& msg, const FIX::SessionID& )
    throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon )
{
    //std::cout << std::endl << "IN: " << msg << std::endl;
}

void MyApplication::fromApp( const FIX::Message& msg, const FIX::SessionID& sessionId )
    throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType )
{
    //std::cout << std::endl << "IN: " << msg << std::endl;
    crack(msg, sessionId);
}

void MyApplication::toAdmin( FIX::Message& msg, const FIX::SessionID& )
{
    if (FIX::MsgType_Logon == msg.getHeader().getField(FIX::FIELD::MsgType))
    {
        msg.setField(FIX::Username(m_username));
        msg.setField(FIX::Password(m_password));
        msg.setField(FIX::DeviceID(m_deviceId));
        //msg.setField(FIX::AppSessionID(m_appSessionId));
        msg.setField(FIX::ProtocolSpec("ext.1.73"));
    }
    std::cout << std::endl << "OUT: " << msg << std::endl;
}

void MyApplication::toApp(FIX::Message& msg, const FIX::SessionID& sessionId) throw( FIX::DoNotSend )
{
    std::cout << std::endl << "OUT: " << msg << std::endl;
}

void MyApplication::run()
{
    std::cout << std::endl
    << "c - get currencies" << std::endl
    << "s - get symbols" << std::endl
    << "sb - subscribe for all symbols" << std::endl
    << "us - unsubscribe from all symbols" << std::endl
    << "e - exit" << std::endl;

    while ( true )
    {
        try
        {
            Sleep(3000);

            std::string opt;
            std::getline(std::cin, opt);
            if (opt == "e")
            {
                return;
            }
            if (opt == "c")
            {
                FIX44::CurrencyListRequest request;
                request.setField(FIX::CurrencyReqID("Currencies_123"));
                request.setField(FIX::CurrencyListRequestType(FIX::CurrencyListRequestType_ALLCURRENCIES));
                FIX::Session::sendToTarget(request, *m_sessionId);
            }
            else if (opt == "s")
            {
                FIX44::SecurityListRequest request;
                request.setField(FIX::SecurityReqID("Securities_123"));
                request.setField(FIX::SecurityListRequestType(FIX::SecurityListRequestType_ALLSECURITIES));
                FIX::Session::sendToTarget(request, *m_sessionId);
            }
            else if (opt == "sb")
            {
                if (m_symbols.empty())
                {
                    std::cout << std::endl << "get symbols first" << std::endl;
                }
                else
                {
                    FIX44::MarketDataRequest request;
                    request.setField(FIX::MDReqID("MarketData_123"));
                    request.setField(FIX::SubscriptionRequestType(FIX::SubscriptionRequestType_SNAPSHOT_PLUS_UPDATES));
                    request.setField(FIX::MarketDepth(1));

                    request.setField(FIX::NoMDEntryTypes(0));
                    FIX44::MarketDataRequest::NoMDEntryTypes mdType;
                    mdType.set(FIX::MDEntryType(FIX::MDEntryType_TRADE));
                    request.addGroup(mdType);

                    request.setField(FIX::NoRelatedSym(0));
                    for (int i = 0; i < m_symbols.size(); i++)
                    {
                        FIX44::MarketDataRequest::NoRelatedSym symbol;
                        symbol.set(FIX::Symbol(m_symbols.at(i)));
                        request.addGroup(symbol);
                    }

                    FIX::Session::sendToTarget(request, *m_sessionId);
                }
            }
            else if (opt == "us")
            {
                
            }
        }
        catch ( std::exception & e )
        {
            std::cout << "Message Not Sent: " << e.what();
        }
    }
}
