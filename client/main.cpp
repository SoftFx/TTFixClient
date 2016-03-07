// QFClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "FileStore.h"
#include "NullStore.h"
#include "FileLog.h"
#include "SocketInitiator.h"
#include "SessionSettings.h"

#include "MyApplication.h"

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

		FIX::SessionID sessionId("FIX.4.4", std::string("CLIENT_") + CreateGUID(), "EXECUTOR");

		FIX::Dictionary sessionSettings;
		sessionSettings.setString("SocketConnectHost", "ttdemo.soft-fx.com");
		sessionSettings.setString("SocketConnectPort", "5001");

		FIX::SessionSettings settings;
		settings.set(defaults);
		settings.set(sessionId, sessionSettings);

		MyApplication application;
		FIX::NullStoreFactory storeFactory;
		FIX::FileLogFactory fileLogFactory(settings);
		FIX::SocketInitiator initiator( application, storeFactory, settings, fileLogFactory );

		initiator.start();
		application.run();
		initiator.stop();

		return 0;
	}
	catch ( std::exception & e )
	{
		std::cout << e.what();
		return 1;
	}
}
