#include "stdafx.h"

#ifdef _MSC_VER
#pragma warning( disable : 4503 4355 4786 )
#else
#include "config.h"
#endif

#include "FixTradeClient.h"
#include "FixMessage.h"

namespace TTFixTradeClient
{
    std::string CreateGUID()
    {
        GUID guid;
        CoCreateGuid(&guid);

        char guidStr[37];
        sprintf_s(
            guidStr,
            "%08lX-%04hX-%04hX-%02hhX%02hhX-%02hhX%02hhX%02hhX%02hhX%02hhX%02hhX",
            guid.Data1, guid.Data2, guid.Data3,
            guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
            guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);

        return std::string(guidStr);
    }

    void FixTradeClient::onLogon(const FIX::SessionID& sessionId)
    {
        std::cout << std::endl << "Logon - " << sessionId << std::endl;
        m_sessionId = &sessionId;
    }

    void FixTradeClient::onLogout(const FIX::SessionID& sessionId)
    {
        std::cout << std::endl << "Logout - " << sessionId << std::endl;
        m_sessionId = nullptr;
    }

    void FixTradeClient::onMessage(const FIX44::TwoFactorLogon& msg, const FIX::SessionID& sessionId)
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

    void FixTradeClient::onMessage(const FIX44::TradingSessionStatus& msg, const FIX::SessionID& sessionId)
    {
        std::cout << std::endl << "TradingSessionStatus:" << std::endl << FixMessage(msg.toString()) << std::endl;
    }

    void FixTradeClient::onMessage(const FIX44::AccountInfo& msg, const FIX::SessionID& sessionId)
    {
        std::cout << std::endl << "AccountInfo:" << std::endl << FixMessage(msg.toString()) << std::endl;
    }

    void FixTradeClient::onMessage(const FIX44::ExecutionReport& msg, const FIX::SessionID& sessionId)
    {
        std::cout << std::endl << "ExecutionReport:" << std::endl << FixMessage(msg.toString()) << std::endl;
    }

    void FixTradeClient::onMessage(const FIX44::PositionReport& msg, const FIX::SessionID& sessionId)
    {
        std::cout << std::endl << "PositionReport:" << std::endl << FixMessage(msg.toString()) << std::endl;
    }

    void FixTradeClient::fromAdmin(const FIX::Message& msg, const FIX::SessionID&)
        throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon)
    {
        //std::cout << std::endl << "IN: " << FixMessage(msg.toString()) << std::endl;
    }

    void FixTradeClient::fromApp(const FIX::Message& msg, const FIX::SessionID& sessionId)
        throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType)
    {
        //std::cout << std::endl << "IN: " << FixMessage(msg.toString()) << std::endl;
        crack(msg, sessionId);
    }

    void FixTradeClient::toAdmin(FIX::Message& msg, const FIX::SessionID&)
    {
        if (FIX::MsgType_Logon == msg.getHeader().getField(FIX::FIELD::MsgType))
        {
            msg.setField(FIX::Username(m_username));
            msg.setField(FIX::Password(m_password));
            msg.setField(FIX::DeviceID(m_deviceId));
            //msg.setField(FIX::AppSessionID(m_appSessionId));
            msg.setField(FIX::ProtocolSpec("ext.1.72"));
        }
        //std::cout << std::endl << "OUT: " << FixMessage(msg.toString()) << std::endl;
    }

    void FixTradeClient::toApp(FIX::Message& msg, const FIX::SessionID& sessionId) throw(FIX::DoNotSend)
    {
        std::cout << std::endl << "OUT: " << FixMessage(msg.toString()) << std::endl;
    }


    void printHelp()
    {
        std::cout << std::endl
            << "a - get account info." << std::endl
            << "o - get orders." << std::endl
            << "p - get positions." << std::endl
            << "nobm - new Buy Market order. Type 'nobm [?]' for help." << std::endl
            << "nosm - new Sell Market order. Type 'nosm [?]' for help." << std::endl
            << "nobl - new Buy Limit order. Type 'nobl [?]' for help." << std::endl
            << "nosl - new Sell Limit order. Type 'nosl [?]' for help." << std::endl
            << "nobs - new Buy Stop order. Type 'nobs [?]' for help." << std::endl
            << "noss - new Sell Stop order. Type 'noss [?]' for help." << std::endl
            << "nobsl - new Buy StopLimit order. Type 'nobsl [?]' for help." << std::endl
            << "nossl - new Sell StopLimit order. Type 'nossl [?]' for help." << std::endl
            << "ro - replace order. Type 'ro [?]' for help." << std::endl
            << "co - cancel order. Type 'co [?]' for help." << std::endl
            << "cp - close position. Type 'cp [?]' for help." << std::endl
            << "th - get trade history. Type 'th [?]' for help." << std::endl
            << "e - exit" << std::endl;
    }

    void printNewMarketOrderHelp(const std::string& title, const std::string& cmd)
    {
        std::cout << std::endl << title;
        std::cout << std::endl << cmd << " <Symbol> <Qty> [<p:Price> <sl:StopLoss> <tp:TakeProfit> <s:Slippage>]";
        std::cout << std::endl << "Examples:";
        std::cout << std::endl << cmd << " EUR/USD 100000";
        std::cout << std::endl << cmd << " EUR/USD 100000 p:1.08836 sl:1.08821 tp:1.008898";
        std::cout << std::endl << cmd << " EUR/USD 100000 1.08836 s:0.05";
    }

    void printNewOrderHelp(const std::string& title, const std::string& cmd, const std::string& p)
    {
        std::cout << std::endl << title;
        std::cout << std::endl << cmd << " <Symbol> <Qty> " << p << " [<t:TimeInForce> <e:ExpireTime> <sl:StopLoss> <tp:TakeProfit> <s:Slippage> <c:ClientOrderId>]";
        std::cout << std::endl << "TimeInForce: gtc - Good Till Cancel | gtd - Good Till Date | ioc - Immediate Or Cancel";
        std::cout << std::endl << "ExpireTime format YYYY-mm-ddTHH:MM:SS";
        std::cout << std::endl << "Examples:";
        std::cout << std::endl << cmd << " EUR/USD 100000 1.08836";
        std::cout << std::endl << cmd << " EUR/USD 100000 1.08836 t:ioc";
        std::cout << std::endl << cmd << " EUR/USD 100000 1.08836 t:gtd e:2023-02-29T13:24:35";
        std::cout << std::endl << cmd << " EUR/USD 100000 1.08836 sl:1.08821 tp:1.008898";
    }

    void SendNewOrderSingle(const FIX::SessionID& session, const std::string& symbol, char side, char type,
        double qty, double price, double stopPrice = 0.0, double sl = 0.0, double tp = 0.0,
        char timeInForce = FIX::TimeInForce_GOOD_TILL_CANCEL, const std::tm* expTime = nullptr, double slippage = 0.0, std::string clOrdId = "")
    {
        FIX::UtcTimeStamp utcNow;

        FIX44::NewOrderSingle request;

        if (clOrdId.empty())
            request.setField(FIX::ClOrdID(CreateGUID()));
        else
            request.setField(FIX::ClOrdID(clOrdId));

        request.setField(FIX::OrdType(type));
        request.setField(FIX::Side(side));
        request.setField(FIX::Symbol(symbol));
        request.setField(FIX::OrderQty(qty));

        if (price > 0)
            request.setField(FIX::Price(price));
        if (stopPrice > 0)
            request.setField(FIX::StopPx(stopPrice));
        if (sl > 0)
            request.setField(FIX::StopLoss(sl));
        if (tp > 0)
            request.setField(FIX::TakeProfit(tp));
        if (timeInForce > 0)
            request.setField(FIX::TimeInForce(timeInForce));
        if (expTime != nullptr)
            request.setField(FIX::ExpireTime(expTime));
        if (slippage > 0)
            request.setField(FIX::Slippage(slippage));

        request.setField(FIX::TransactTime(utcNow));

        FIX::Session::sendToTarget(request, session);
    }

    void SendNewMarketOrder(const FIX::SessionID& session, char side, const std::vector<std::string>& params)
    {
        std::string symbol = params[1];
        double qty = std::stod(params[2]);
        double price = 0.0;
        double sl = 0.0;
        double tp = 0.0;
        double slippage = 0.0;
        std::string clOrdId;

        for (int i = 4; i < params.size(); i++)
        {
            std::string param = params[i];
            size_t sidx = param.find_first_of(':');
            std::string key = param.substr(0U, sidx);
            std::string value = param.substr(sidx + 1);
            if (key == "p")
            {
                price = std::stod(value);
            }
            else if (key == "sl")
            {
                sl = std::stod(value);
            }
            else if (key == "tp")
            {
                tp = std::stod(value);
            }
            else if (key == "s")
            {
                slippage = std::stod(value);
            }
            else if (key == "c")
            {
                clOrdId = value;
            }
        }

        SendNewOrderSingle(session, symbol, FIX::OrdType_MARKET, side, qty, price, 0.0, sl, tp, 0, nullptr, slippage, clOrdId);
    }

    void SendNewLimitOrder(const FIX::SessionID& session, char side, const std::vector<std::string>& params)
    {
        char tif = FIX::TimeInForce_GOOD_TILL_CANCEL;
        std::string symbol = params[1];
        double qty = std::stod(params[2]);
        double price = std::stod(params[3]);
        double sl = 0.0;
        double tp = 0.0;
        double slippage = 0.0;
        std::tm expTime;
        std::tm* p_expTime = nullptr;
        std::string clOrdId;

        for (int i = 4; i < params.size(); i++)
        {
            std::string param = params[i];
            size_t sidx = param.find_first_of(':');
            std::string key = param.substr(0U, sidx);
            std::string value = param.substr(sidx + 1);
            if (key == "t")
            {
                if (value == "ioc")
                    tif = FIX::TimeInForce_IMMEDIATE_OR_CANCEL;
                else if (value == "gtd")
                    tif = FIX::TimeInForce_GOOD_TILL_DATE;
            }
            else if (key == "e")
            {
                std::istringstream isst(value);
                isst >> std::get_time(&expTime, "%Y-%m-%dT%H:%M:%S");
                p_expTime = &expTime;
            }
            else if (key == "sl")
            {
                sl = std::stod(value);
            }
            else if (key == "tp")
            {
                tp = std::stod(value);
            }
            else if (key == "s")
            {
                slippage = std::stod(value);
            }
            else if (key == "c")
            {
                clOrdId = value;
            }
        }

        SendNewOrderSingle(session, symbol, side, FIX::OrdType_LIMIT, qty, price, 0.0, sl, tp, tif, p_expTime, slippage, clOrdId);
    }

    void SendNewStopOrder(const FIX::SessionID& session, char side, const std::vector<std::string>& params)
    {
        char tif = FIX::TimeInForce_GOOD_TILL_CANCEL;
        std::string symbol = params[1];
        double qty = std::stod(params[2]);
        double stopPrice = std::stod(params[3]);
        double sl = 0.0;
        double tp = 0.0;
        double slippage = 0.0;
        std::tm expTime;
        std::tm* p_expTime = nullptr;
        std::string clOrdId;

        for (int i = 4; i < params.size(); i++)
        {
            std::string param = params[i];
            size_t sidx = param.find_first_of(':');
            std::string key = param.substr(0U, sidx);
            std::string value = param.substr(sidx + 1);
            if (key == "t")
            {
                if (value == "ioc")
                    tif = FIX::TimeInForce_IMMEDIATE_OR_CANCEL;
                else if (value == "gtd")
                    tif = FIX::TimeInForce_GOOD_TILL_DATE;
            }
            else if (key == "e")
            {
                std::istringstream isst(value);
                isst >> std::get_time(&expTime, "%Y-%m-%dT%H:%M:%S");
                p_expTime = &expTime;
            }
            else if (key == "sl")
            {
                sl = std::stod(value);
            }
            else if (key == "tp")
            {
                tp = std::stod(value);
            }
            else if (key == "s")
            {
                slippage = std::stod(value);
            }
            else if (key == "c")
            {
                clOrdId = value;
            }
        }

        SendNewOrderSingle(session, symbol, FIX::OrdType_STOP, side, qty, 0.0, stopPrice, sl, tp, tif, p_expTime, slippage, clOrdId);
    }

    void FixTradeClient::run()
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
                else if (cmd == "a")
                {
                    FIX44::AccountInfoRequest request;
                    request.setField(FIX::AcInfReqID("Account_Info"));

                    FIX::Session::sendToTarget(request, *m_sessionId);
                    delay = 3000;
                }
                else if (cmd == "o")
                {
                    FIX44::OrderMassStatusRequest request;
                    request.setField(FIX::MassStatusReqID("Order_Mass_Status"));
                    request.setField(FIX::MassStatusReqType(FIX::MassStatusReqType_STATUSALLORDERS));

                    FIX::Session::sendToTarget(request, *m_sessionId);
                    delay = 3000;
                }
                else if (cmd == "p")
                {
                    FIX::UtcTimeStamp utcNow;
                    FIX::DateTime now;

                    FIX44::RequestForPositions request;
                    request.setField(FIX::PosReqID("Request_For_Positions"));
                    request.setField(FIX::PosReqType(FIX::PosReqType_POSITIONS));
                    request.setField(FIX::SubscriptionRequestType(FIX::SubscriptionRequestType_SNAPSHOT));
                    request.setField(FIX::Account("200"));
                    request.setField(FIX::AccountType(FIX::AccountType_ACCOUNTCUSTOMER));

                    FIX::TransactTime trTime(utcNow);
                    request.setField(trTime);
                    request.setField(FIX::ClearingBusinessDate(trTime.getString()));

                    FIX::Session::sendToTarget(request, *m_sessionId);
                    delay = 3000;
                }
                else if (cmd == "nobm")
                {
                    if (params.size() == 1 || params[1] == "?")
                    {
                        printNewMarketOrderHelp("New Order Buy Market", "nobm");
                        continue;
                    }
                    else if (params.size() < 3)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    SendNewMarketOrder(*m_sessionId, FIX::Side_BUY, params);
                    delay = 3000;
                }
                else if (cmd == "nosm")
                {
                    if (params.size() == 1 || params[1] == "?")
                    {
                        printNewMarketOrderHelp("New Order Sell Market", "nosm");
                        continue;
                    }
                    else if (params.size() < 3)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    SendNewMarketOrder(*m_sessionId, FIX::Side_SELL, params);
                    delay = 3000;
                }
                else if (cmd == "nobl")
                {
                    if (params.size() == 1 || params[1] == "?")
                    {
                        printNewOrderHelp("New Order Buy Limit:", "nobl", "Price");
                        continue;
                    }
                    else if (params.size() < 4)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    SendNewLimitOrder(*m_sessionId, FIX::Side_BUY, params);
                    delay = 3000;
                }
                else if (cmd == "nosl")
                {
                    if (params.size() == 1 || params[1] == "?")
                    {
                        printNewOrderHelp("New Order Sell Limit:", "nosl", "Price");
                        continue;
                    }
                    else if (params.size() < 4)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    SendNewLimitOrder(*m_sessionId, FIX::Side_SELL, params);
                    delay = 3000;
                }
                else if (cmd == "nobs")
                {
                    if (params.size() == 1 || params[1] == "?")
                    {
                        printNewOrderHelp("New Order Buy Stop:", "nobs", "StopPrice");
                        continue;
                    }
                    else if (params.size() < 4)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    SendNewStopOrder(*m_sessionId, FIX::Side_BUY, params);
                    delay = 3000;
                }
                else if (cmd == "noss")
                {
                    if (params.size() == 1 || params[1] == "?")
                    {
                        printNewOrderHelp("New Order Sell Stop:", "noss", "StopPrice");
                        continue;
                    }
                    else if (params.size() < 4)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    SendNewStopOrder(*m_sessionId, FIX::Side_SELL, params);
                    delay = 3000;
                }
                else if (cmd == "ro")
                {
                    std::cout << std::endl << "Replace order is not implemented yet" << std::endl;
                    continue;
                }
                else if (cmd == "co")
                {
                    if (params.size() == 1 || params[1] == "?")
                    {
                        std::cout << std::endl << "Cancel Order";
                        std::cout << std::endl << "co <Side> <ClientOrderId> [<OrderId>]";
                        std::cout << std::endl << "Side: 1 - Buy; 2 - Sell";
                        std::cout << std::endl << "Examples:";
                        std::cout << std::endl << "co 2 My_favorite_sell_order";
                        std::cout << std::endl << "co 1 My_favorite_buy_order 456789";
                        continue;
                    }
                    else if (params.size() < 3)
                    {
                        std::cout << std::endl << "Invalid params count" << std::endl;
                        continue;
                    }

                    char side = params[1][0];
                    std::string clientOrderId = params[2];
                    std::string orderId;
                    if (params.size() > 3)
                        orderId = params[3];

                    FIX::UtcTimeStamp utcNow;
                    FIX44::OrderCancelRequest request;
                    request.setField(FIX::ClOrdID("Cancel_Order"));
                    request.setField(FIX::OrigClOrdID(clientOrderId));
                    if (!orderId.empty())
                        request.setField(FIX::OrderID(orderId));
                    request.setField(FIX::Side(side));
                    request.setField(FIX::TransactTime(utcNow));

                    FIX::Session::sendToTarget(request, *m_sessionId);
                    delay = 3000;
                }
                else if (cmd == "cp")
                {
                    std::cout << std::endl << "Close position is not implemented yet" << std::endl;
                    continue;
                }
                else if (cmd == "th")
                {
                    std::cout << std::endl << "Get trade history is not implemented yet" << std::endl;
                    continue;
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
