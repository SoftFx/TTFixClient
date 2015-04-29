#ifndef FIX44_MARKETDATAHISTORYREQUESTREJECT_H
#define FIX44_MARKETDATAHISTORYREQUESTREJECT_H

#include "Message.h"

namespace FIX44
{

  class MarketDataHistoryRequestReject : public Message
  {
  public:
    MarketDataHistoryRequestReject() : Message(MsgType()) {}
    MarketDataHistoryRequestReject(const FIX::Message& m) : Message(m) {}
    MarketDataHistoryRequestReject(const Message& m) : Message(m) {}
    MarketDataHistoryRequestReject(const MarketDataHistoryRequestReject& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1001"); }

    MarketDataHistoryRequestReject(
      const FIX::MarketHistReqID& aMarketHistReqID,
      const FIX::MHstRejReason& aMHstRejReason )
    : Message(MsgType())
    {
      set(aMarketHistReqID);
      set(aMHstRejReason);
    }

    FIELD_SET(*this, FIX::MarketHistReqID);
    FIELD_SET(*this, FIX::MHstRejReason);
    FIELD_SET(*this, FIX::Text);
  };

}

#endif
