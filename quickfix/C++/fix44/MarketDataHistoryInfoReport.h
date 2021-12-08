#ifndef FIX44_MARKETDATAHISTORYINFOREPORT_H
#define FIX44_MARKETDATAHISTORYINFOREPORT_H

#include "Message.h"

namespace FIX44
{

  class MarketDataHistoryInfoReport : public Message
  {
  public:
    MarketDataHistoryInfoReport() : Message(MsgType()) {}
    MarketDataHistoryInfoReport(const FIX::Message& m) : Message(m) {}
    MarketDataHistoryInfoReport(const Message& m) : Message(m) {}
    MarketDataHistoryInfoReport(const MarketDataHistoryInfoReport& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1029"); }

    MarketDataHistoryInfoReport(
      const FIX::MarketHistReqID& aMarketHistReqID,
      const FIX::Symbol& aSymbol,
      const FIX::AllHstFrom& aAllHstFrom,
      const FIX::AllHstTo& aAllHstTo )
    : Message(MsgType())
    {
      set(aMarketHistReqID);
      set(aSymbol);
      set(aAllHstFrom);
      set(aAllHstTo);
    }

    FIELD_SET(*this, FIX::MarketHistReqID);
    FIELD_SET(*this, FIX::Symbol);
    FIELD_SET(*this, FIX::AllHstFrom);
    FIELD_SET(*this, FIX::AllHstTo);
    FIELD_SET(*this, FIX::LastTickId);
  };

}

#endif
