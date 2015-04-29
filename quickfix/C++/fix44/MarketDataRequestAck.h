#ifndef FIX44_MARKETDATAREQUESTACK_H
#define FIX44_MARKETDATAREQUESTACK_H

#include "Message.h"

namespace FIX44
{

  class MarketDataRequestAck : public Message
  {
  public:
    MarketDataRequestAck() : Message(MsgType()) {}
    MarketDataRequestAck(const FIX::Message& m) : Message(m) {}
    MarketDataRequestAck(const Message& m) : Message(m) {}
    MarketDataRequestAck(const MarketDataRequestAck& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1011"); }

    MarketDataRequestAck(
      const FIX::MDReqID& aMDReqID,
      const FIX::TotalNumMarketSnaps& aTotalNumMarketSnaps )
    : Message(MsgType())
    {
      set(aMDReqID);
      set(aTotalNumMarketSnaps);
    }

    FIELD_SET(*this, FIX::MDReqID);
    FIELD_SET(*this, FIX::TotalNumMarketSnaps);
  };

}

#endif
