#ifndef FIX44_MARKETDATAHISTORYINFOREQUEST_H
#define FIX44_MARKETDATAHISTORYINFOREQUEST_H

#include "Message.h"

namespace FIX44
{

  class MarketDataHistoryInfoRequest : public Message
  {
  public:
    MarketDataHistoryInfoRequest() : Message(MsgType()) {}
    MarketDataHistoryInfoRequest(const FIX::Message& m) : Message(m) {}
    MarketDataHistoryInfoRequest(const Message& m) : Message(m) {}
    MarketDataHistoryInfoRequest(const MarketDataHistoryInfoRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1028"); }

    MarketDataHistoryInfoRequest(
      const FIX::MarketHistReqID& aMarketHistReqID,
      const FIX::Symbol& aSymbol,
      const FIX::HstGraphType& aHstGraphType )
    : Message(MsgType())
    {
      set(aMarketHistReqID);
      set(aSymbol);
      set(aHstGraphType);
    }

    FIELD_SET(*this, FIX::MarketHistReqID);
    FIELD_SET(*this, FIX::Symbol);
    FIELD_SET(*this, FIX::HstGraphType);
    FIELD_SET(*this, FIX::HstGraphPeriodID);
    FIELD_SET(*this, FIX::ForexPriceType);
  };

}

#endif
