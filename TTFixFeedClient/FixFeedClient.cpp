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

#include "FixFeedClient.h"
#include "FixMessage.h"

namespace TTFixFeedClient
{
    void FixFeedClient::onLogon(const FIX::SessionID& sessionId)
    {
        std::cout << std::endl << "Logon - " << sessionId << std::endl;
        m_sessionId = &sessionId;
    }

    void FixFeedClient::onLogout(const FIX::SessionID& sessionId)
    {
        std::cout << std::endl << "Logout - " << sessionId << std::endl;
        m_sessionId = nullptr;
    }

    void FixFeedClient::onMessage(const FIX44::TwoFactorLogon& msg, const FIX::SessionID& sessionId)
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

    void FixFeedClient::onMessage(const FIX44::TradingSessionStatus& msg, const FIX::SessionID& sessionId)
    {
        std::cout << std::endl << "TradingSessionStatus:" << std::endl << FixMessage(msg.toString()) << std::endl;
    }

    void FixFeedClient::onMessage(const FIX44::CurrencyList& msg, const FIX::SessionID&)
    {
        std::cout << std::endl << "CurrencyList: " << FixMessage(msg.toString()) << std::endl;
    }

    void FixFeedClient::onMessage(const FIX44::SecurityList& msg, const FIX::SessionID&)
    {
        std::cout << std::endl << "SecurityList: " << FixMessage(msg.toString()) << std::endl;

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

    void FixFeedClient::onMessage(const FIX44::MarketDataRequestAck& msg, const FIX::SessionID&)
    {
        FIX::TotalNumMarketSnaps total;
        msg.get(total);
        std::cout << std::endl << "Total number of snapshots returned " << total.getValue() << std::endl;
    }

    void FixFeedClient::onMessage(const FIX44::MarketDataSnapshotFullRefresh& msg, const FIX::SessionID&)
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

    void FixFeedClient::onMessage(const FIX44::MarketDataHistory& msg, const FIX::SessionID&)
    {
        std::cout << std::endl << "IN: " << FixMessage(msg.toString()) << std::endl;
    }

    void FixFeedClient::onMessage(const FIX44::MarketDataHistoryMetadataReport& msg, const FIX::SessionID&)
    {
        std::cout << std::endl << "IN: " << FixMessage(msg.toString()) << std::endl;
    }

    void FixFeedClient::onMessage(const FIX44::MarketDataHistoryInfoReport& msg, const FIX::SessionID& sessionId)
    {
        std::cout << std::endl << "IN: " << FixMessage(msg.toString()) << std::endl;
    }

    void FixFeedClient::onMessage(const FIX44::ComponentsInfoReport& msg, const FIX::SessionID& sessionId)
    {
        std::cout << std::endl << "IN: " << FixMessage(msg.toString()) << std::endl;
    }

    void FixFeedClient::onMessage(const FIX44::FileChunk& msg, const FIX::SessionID& sessionId)
    {
        //std::cout << std::endl << "IN: " << FixMessage(msg.toString()) << std::endl;

        FIX::FileId fid;
        FIX::ChunkId cid;
        FIX::ChunksNo cno;
        FIX::RawDataLength size;
        FIX::RawData data;

        msg.get(fid);
        msg.get(cid);
        msg.get(cno);
        msg.get(size);
        msg.get(data);

        std::string fidValue = fid.getValue();
        int cidValue = cid.getValue();
        int cnoValue = cno.getValue();
        int sizeValue = size.getValue();
        std::string dataValue = data.getValue();

        std::cout << std::endl << "File ID: " << fidValue << " Chunk ID: " << cidValue << "/" << cnoValue << " Size: " << sizeValue << std::endl;

        const char* dataStr = data.getString().c_str();

        mkdir("FileChunks");
        std::ofstream ofs(".\\FileChunks\\File_"+fidValue+"_"+cid.getString()+".zip", std::ios_base::app);
        ofs.write(dataStr, sizeValue);
        ofs.close();
    }

    void FixFeedClient::fromAdmin(const FIX::Message& msg, const FIX::SessionID&)
        throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon)
    {
        //std::cout << std::endl << "IN: " << FixMessage(msg.toString()) << std::endl;
    }

    void FixFeedClient::fromApp(const FIX::Message& msg, const FIX::SessionID& sessionId)
        throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType)
    {
        //std::cout << std::endl << "IN: " << FixMessage(msg.toString()) << std::endl;
        crack(msg, sessionId);
    }

    void FixFeedClient::toAdmin(FIX::Message& msg, const FIX::SessionID&)
    {
        if (FIX::MsgType_Logon == msg.getHeader().getField(FIX::FIELD::MsgType))
        {
            msg.setField(FIX::Username(m_username));
            msg.setField(FIX::Password(m_password));
            msg.setField(FIX::DeviceID(m_deviceId));
            //msg.setField(FIX::AppSessionID(m_appSessionId));
            msg.setField(FIX::ProtocolSpec("ext.1.73"));
        }
        //std::cout << std::endl << "OUT: " << FixMessage(msg.toString()) << std::endl;
    }

    void FixFeedClient::toApp(FIX::Message& msg, const FIX::SessionID& sessionId) throw(FIX::DoNotSend)
    {
        std::cout << std::endl << "OUT: " << FixMessage(msg.toString()) << std::endl;
    }


    void printHelp()
    {
        std::cout << std::endl
            << "c - get all currencies" << std::endl
            << "s - get all symbols" << std::endl
            << "sb - subscribe for all or single symbol with depth. Exaples: sb all 1 | sb EUR/USD 5" << std::endl
            << "us - unsubscribe from all or single symbol. Exaples: us all | us EUR/USD" << std::endl
            << "mdh - market data history request. Type mdh ? for help." << std::endl
            << "mdhm - market data history metadata request. Type mdhm ? for help." << std::endl
            << "mdhi - market data history info request. Type mdhi ? for help." << std::endl
            << "fc - file chank request" << std::endl
            << "e - exit" << std::endl;
    }

    void FixFeedClient::run()
    {
        Sleep(3000);
        printHelp();

        while (true)
        {
            int delay = 0;

            try
            {
                std::cout << std::endl << ">>";
                std::string cmdLine;
                std::getline(std::cin, cmdLine);

                std::istringstream issp(cmdLine);
                std::vector<std::string> params
                {
                    std::istream_iterator<std::string> { issp },
                    std::istream_iterator<std::string> { }
                };
                std::string cmd = params[0];

                if (cmd == "e")
                {
                    return;
                }
                if (cmd == "?")
                {
                    printHelp();
                }
                else if (cmd == "c")
                {
                    FIX44::CurrencyListRequest request;
                    request.setField(FIX::CurrencyReqID("Currencies_123"));
                    request.setField(FIX::CurrencyListRequestType(FIX::CurrencyListRequestType_ALLCURRENCIES));
                    FIX::Session::sendToTarget(request, *m_sessionId);
                    delay = 2000;
                }
                else if (cmd == "s")
                {
                    FIX44::SecurityListRequest request;
                    request.setField(FIX::SecurityReqID("Securities_123"));
                    request.setField(FIX::SecurityListRequestType(FIX::SecurityListRequestType_ALLSECURITIES));
                    FIX::Session::sendToTarget(request, *m_sessionId);
                    delay = 5000;
                }
                else if (cmd == "sb")
                {
                    if (params.size() < 3)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    std::string smb = params[1];
                    int depth = stoi(params[2]);

                    if (smb == "all")
                    {
                        if (m_symbols.empty())
                        {
                            std::cout << std::endl << "get symbols first" << std::endl;
                        }
                        else
                        {
                            FIX44::MarketDataRequest request;
                            request.setField(FIX::MDReqID("MD_Subscribe_All"));
                            request.setField(FIX::SubscriptionRequestType(FIX::SubscriptionRequestType_SNAPSHOT_PLUS_UPDATES));
                            request.setField(FIX::MarketDepth(depth));

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
                            m_subscribedAll = true;
                            delay = 5000;
                        }
                    }
                    else
                    {
                        FIX44::MarketDataRequest request;
                        request.setField(FIX::MDReqID("MD_Subscribe_Symbol"));
                        request.setField(FIX::SubscriptionRequestType(FIX::SubscriptionRequestType_SNAPSHOT_PLUS_UPDATES));
                        request.setField(FIX::MarketDepth(depth));

                        request.setField(FIX::NoMDEntryTypes(0));
                        FIX44::MarketDataRequest::NoMDEntryTypes mdType;
                        mdType.set(FIX::MDEntryType(FIX::MDEntryType_TRADE));
                        request.addGroup(mdType);

                        request.setField(FIX::NoRelatedSym(0));
                        {
                            FIX44::MarketDataRequest::NoRelatedSym symbol;
                            symbol.set(FIX::Symbol(smb));
                            request.addGroup(symbol);
                        }

                        FIX::Session::sendToTarget(request, *m_sessionId);
                        delay = 3000;
                    }
                }
                else if (cmd == "us")
                {
                    if (params.size() < 2)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    std::string smb = params[1];

                    if (smb == "all")
                    {
                        if (!m_subscribedAll)
                        {
                            std::cout << std::endl << "subscribe first" << std::endl;
                        }
                        else
                        {
                            FIX44::MarketDataRequest request;
                            request.setField(FIX::MDReqID("MD_Unsubscribe_All"));
                            request.setField(FIX::SubscriptionRequestType(FIX::SubscriptionRequestType_UNSUBSCRIBE));
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
                            delay = 3000;
                        }
                    }
                    else
                    {
                        FIX44::MarketDataRequest request;
                        request.setField(FIX::MDReqID("MD_Unsubscribe_Symbol"));
                        request.setField(FIX::SubscriptionRequestType(FIX::SubscriptionRequestType_UNSUBSCRIBE));
                        request.setField(FIX::MarketDepth(1));

                        request.setField(FIX::NoMDEntryTypes(0));
                        FIX44::MarketDataRequest::NoMDEntryTypes mdType;
                        mdType.set(FIX::MDEntryType(FIX::MDEntryType_TRADE));
                        request.addGroup(mdType);

                        request.setField(FIX::NoRelatedSym(0));
                        {
                            FIX44::MarketDataRequest::NoRelatedSym symbol;
                            symbol.set(FIX::Symbol(smb));
                            request.addGroup(symbol);
                        }

                        FIX::Session::sendToTarget(request, *m_sessionId);
                        delay = 3000;
                    }
                }
                else if (cmd == "mdh")
                {
                    if (params.size() == 1 || params[1] == "?")
                    {
                        std::cout << std::endl << "mdh <ReportType> <Symbol> <Period> <PriceType> <BarsCount> <Timestamp>";
                        std::cout << std::endl << "ReportType: G - fix groups (Bars, by default); F - compressed file (ZIP);";
                        std::cout << std::endl << "Period : S1|S10|M1|M5|M15|M30|H1|H4|D1|W1|MN1;";
                        std::cout << std::endl << "PriceType: A - Ask; B - Bid;";
                        std::cout << std::endl << "Example: mdh EUR/USD H1 A -10 2023-01-23T11:00:00 F" << std::endl;
                        continue;
                    }
                    else if (params.size() < 6)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    std::string smb = params[1];
                    std::string per = params[2];
                    char prt = params[3].at(0);
                    int cnt = std::stoi(params[4]);
                    std::tm time;
                    std::istringstream isst(params[5]);
                    isst >> std::get_time(&time, "%Y-%m-%dT%H:%M:%S");
                    char rpt = params.size() == 7 ? params[6].at(0) : 'G';

                    FIX44::MarketDataHistoryRequest request;
                    request.setField(FIX::MarketHistReqID("MD_History"));
                    request.setField(FIX::Symbol(smb));
                    request.setField(FIX::HstGraphPeriodID(per));
                    request.setField(FIX::ForexPriceType(prt));
                    request.setField(FIX::HstReqBars(cnt));
                    request.setField(FIX::HstTo(FIX::UTCTIMESTAMP(&time)));
                    request.setField(FIX::HstReportType(rpt));
                    request.setField(FIX::HstGraphType(FIX::HstGraphType_BARS));

                    FIX::Session::sendToTarget(request, *m_sessionId);
                    delay = 3000;
                }
                else if (cmd == "mdhm")
                {
                    if (params.size() == 1 || params[1] == "?")
                    {
                        std::cout << std::endl << "mdhm <Symbol> <Period(S1|S10|M1|M5|M15|M30|H1|H4|D1|W1|MN1)> <PriceType(A|B)>";
                        std::cout << std::endl << "Example: mdhm EUR/USD H1 A" << std::endl;
                        continue;
                    }
                    else if (params.size() < 4)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    std::string smb = params[1];
                    std::string per = params[2];
                    char prt = params[3].at(0);

                    FIX44::MarketDataHistoryMetadataRequest request;
                    request.setField(FIX::MDHstMetaReqID("MD_History_Metadata"));
                    request.setField(FIX::Symbol(smb));
                    request.setField(FIX::HstGraphPeriodID(per));
                    request.setField(FIX::ForexPriceType(prt));
                    request.setField(FIX::HstGraphType(FIX::HstGraphType_BARS));

                    FIX::Session::sendToTarget(request, *m_sessionId);
                    delay = 3000;
                }
                else if (cmd == "mdhi")
                {
                    if (params.size() == 1 || params[1] == "?")
                    {
                        std::cout << std::endl << "mdhi <Symbol> <Period(S1|S10|M1|M5|M15|M30|H1|H4|D1|W1|MN1)> <PriceType(A|B)>";
                        std::cout << std::endl << "Example: mdhi EUR/USD H1 A" << std::endl;
                        continue;
                    }
                    else if (params.size() < 4)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    std::string smb = params[1];
                    std::string per = params[2];
                    char prt = params[3].at(0);

                    FIX44::MarketDataHistoryInfoRequest request;
                    request.setField(FIX::MarketHistReqID("MD_History_Info"));
                    request.setField(FIX::Symbol(smb));
                    request.setField(FIX::HstGraphPeriodID(per));
                    request.setField(FIX::ForexPriceType(prt));
                    request.setField(FIX::HstGraphType(FIX::HstGraphType_BARS));

                    FIX::Session::sendToTarget(request, *m_sessionId);
                    delay = 3000;
                }
                else if (cmd == "fc")
                {
                    if (params.size() == 1 || params[1] == "?")
                    {
                        std::cout << std::endl << "fc <FileId> <ChunkNo>";
                        std::cout << std::endl << "Example: fc b3bed14d-14ed-4c8e-b5fb-54c2ab754436 0" << std::endl;
                        continue;
                    }
                    else if (params.size() < 3)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    std::string fid = params[1];
                    int cid = std::stoi(params[2]);

                    FIX44::FileChunkReq request;
                    request.setField(FIX::FileId(fid));
                    request.setField(FIX::ChunkId(cid));

                    FIX::Session::sendToTarget(request, *m_sessionId);
                    delay = 5000;
                }
                else if (cmd == "ci")
                {
                    int qhv = std::stoi(params[1]);
                    FIX44::ComponentsInfoRequest request;
                    request.setField(FIX::CompReqID("Components_Info"));
                    request.setField(FIX::ClientQuoteHistoryVersion(qhv));
                    FIX::Session::sendToTarget(request, *m_sessionId);
                    delay = 2000;
                }
            }
            catch (std::exception& e)
            {
                std::cout << "Message Not Sent: " << e.what();
            }

            Sleep(delay);
        }
    }
}
