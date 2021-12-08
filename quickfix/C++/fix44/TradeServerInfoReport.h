#ifndef FIX44_TRADESERVERINFOREPORT_H
#define FIX44_TRADESERVERINFOREPORT_H

#include "Message.h"

namespace FIX44
{

  class TradeServerInfoReport : public Message
  {
  public:
    TradeServerInfoReport() : Message(MsgType()) {}
    TradeServerInfoReport(const FIX::Message& m) : Message(m) {}
    TradeServerInfoReport(const Message& m) : Message(m) {}
    TradeServerInfoReport(const TradeServerInfoReport& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1024"); }

    TradeServerInfoReport(
      const FIX::TrdSrvReqID& aTrdSrvReqID )
    : Message(MsgType())
    {
      set(aTrdSrvReqID);
    }

    FIELD_SET(*this, FIX::TrdSrvReqID);
    FIELD_SET(*this, FIX::CompanyName);
    FIELD_SET(*this, FIX::CompanyFullName);
    FIELD_SET(*this, FIX::EncodedCompanyDescriptionLen);
    FIELD_SET(*this, FIX::EncodedCompanyDescription);
    FIELD_SET(*this, FIX::CompanyAddress);
    FIELD_SET(*this, FIX::CompanyEmail);
    FIELD_SET(*this, FIX::CompanyPhone);
    FIELD_SET(*this, FIX::CompanyWebSite);
    FIELD_SET(*this, FIX::ServerName);
    FIELD_SET(*this, FIX::ServerFullName);
    FIELD_SET(*this, FIX::EncodedServerDescriptionLen);
    FIELD_SET(*this, FIX::EncodedServerDescription);
    FIELD_SET(*this, FIX::ServerAddress);
    FIELD_SET(*this, FIX::ServerFixFeedSslPort);
    FIELD_SET(*this, FIX::ServerFixTradeSslPort);
    FIELD_SET(*this, FIX::ServerWebSocketFeedPort);
    FIELD_SET(*this, FIX::ServerWebSocketTradePort);
    FIELD_SET(*this, FIX::ServerRestPort);
  };

}

#endif
