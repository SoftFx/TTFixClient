#ifndef FIX44_TRADESERVERINFOREQUEST_H
#define FIX44_TRADESERVERINFOREQUEST_H

#include "Message.h"

namespace FIX44
{

  class TradeServerInfoRequest : public Message
  {
  public:
    TradeServerInfoRequest() : Message(MsgType()) {}
    TradeServerInfoRequest(const FIX::Message& m) : Message(m) {}
    TradeServerInfoRequest(const Message& m) : Message(m) {}
    TradeServerInfoRequest(const TradeServerInfoRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1023"); }

    TradeServerInfoRequest(
      const FIX::TrdSrvReqID& aTrdSrvReqID )
    : Message(MsgType())
    {
      set(aTrdSrvReqID);
    }

    FIELD_SET(*this, FIX::TrdSrvReqID);
  };

}

#endif
