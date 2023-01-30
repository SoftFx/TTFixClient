// QFClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "FileStore.h"
#include "NullStore.h"
#include "FileLog.h"
#include "SocketInitiator.h"
#include "SessionSettings.h"

#include "FixFeedClient.h"
#include "FixFileLog.h"
#include "FixMessage.h"

using namespace TTFixFeedClient;

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

int _tmain(int argc, _TCHAR* argv[])
{
    try
    {
        FIX::Dictionary defaults;
        defaults.setString("ConnectionType", "initiator");
        defaults.setString("ReconnectInterval", "60");
        defaults.setString("ResetOnLogout", "Y");
        defaults.setString("ResetOnDisconnect", "N");
        defaults.setString("ResetOnLogon", "Y");
        defaults.setString("CheckLatency", "N");
        defaults.setString("RefreshOnLogon", "Y");
        defaults.setString("StartTime", "00:00:00");
        defaults.setString("EndTime", "00:00:00");
        defaults.setString("HeartBtInt", "30");
        defaults.setString("UseDataDictionary", "Y");
        defaults.setString("DataDictionary", "FIX44.xml");
        defaults.setString("FileLogPath", "Log");
        defaults.setString("ValidateFieldsHaveValues", "N");

        std::string id = CreateGUID();
        FIX::SessionID sessionId("FIX.4.4", std::string("CLIENT_") + id, "EXECUTOR");

        std::string serverAddress = "localhost";
        std::string username = "100";
        std::string password = "123qwe!";

        std::string deviceId = "123456789";
        std::string appSessionId = "987654321";

#ifndef _DEBUG
        if (argc < 4)
        {
            std::cout << std::endl << "Enter Server address: " << std::endl;
            std::getline(std::cin, serverAddress);

            std::cout << std::endl << "Enter DeviceId: " << std::endl;
            std::getline(std::cin, deviceId);

            std::cout << std::endl << "Enter AppSessionId: " << std::endl;
            std::getline(std::cin, appSessionId);

            std::cout << std::endl << "Enter Username: " << std::endl;
            std::getline(std::cin, username);

            std::cout << std::endl << "Enter Password: " << std::endl;
            std::getline(std::cin, password);
        }
        else
        {
            serverAddress = argv[1];
            username = argv[2];
            password = argv[3];
        }
#endif // DEBUG

        FIX::Dictionary sessionSettings;
        sessionSettings.setString("SocketConnectHost", serverAddress);
        sessionSettings.setString("SocketConnectPort", "5001");

        FIX::SessionSettings settings;
        settings.set(defaults);
        settings.set(sessionId, sessionSettings);

        FixFeedClient application(username, password, deviceId, appSessionId);

        mkdir("Log");
        FixMessage::LoadDictionary("FIX44.xml");

        FIX::NullStoreFactory storeFactory;
        //FIX::FixFileLogFactory fileLogFactory(settings);
        FixFileLogFactory fileLogFactory(L"Log", StringUtils::StringToWString(id + "_Events.log"), StringUtils::StringToWString(id + "_Messages.log"), "", true);
        FIX::SocketInitiator initiator(application, storeFactory, settings, fileLogFactory);

        //while (true)
        {
            initiator.start();
            application.run();
            initiator.stop();
        }

        return 0;
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
        return 1;
    }
}
