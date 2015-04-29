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

void MyApplication::onLogon( const FIX::SessionID& sessionID )
{
	std::cout << std::endl << "Logon - " << sessionID << std::endl;
}

void MyApplication::onLogout( const FIX::SessionID& sessionID )
{
	std::cout << std::endl << "Logout - " << sessionID << std::endl;
}

void MyApplication::onMessage( const FIX44::TradingSessionStatus& message, const FIX::SessionID& )
{
	std::cout << std::endl << "TradingSessionStatus received!" << std::endl;
}

void MyApplication::fromAdmin( const FIX::Message& message, const FIX::SessionID& )
	throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon )
{
	std::cout << std::endl << "IN: " << message << std::endl;
}

void MyApplication::fromApp( const FIX::Message& message, const FIX::SessionID& sessionID )
	throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType )
{
	std::cout << std::endl << "IN: " << message << std::endl;
	crack( message, sessionID );
}

void MyApplication::toAdmin( FIX::Message& message, const FIX::SessionID& )
{
	if (FIX::MsgType_Logon == message.getHeader().getField(FIX::FIELD::MsgType))
	{
		message.setField(FIX::Username("100006"));
		message.setField(FIX::Password("rQTRdKZew8Gb"));
		message.setField(FIX::ProtocolSpec("ext.1.21"));		
	}
	std::cout << std::endl << "OUT: " << message << std::endl;
}

void MyApplication::toApp( FIX::Message& message, const FIX::SessionID& sessionID )
	throw( FIX::DoNotSend )
{
	std::cout << std::endl << "OUT: " << message << std::endl;
}

void MyApplication::run()
{
	while ( true )
	{
		try
		{
			char action = 0;
			std::cin >> action;

			if ( action == 'q' )
				break;
		}
		catch ( std::exception & e )
		{
			std::cout << "Message Not Sent: " << e.what();
		}
	}
}
