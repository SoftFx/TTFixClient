#ifndef FIX44_MARKETDATAHISTORYMETADATAREPORT_H
#define FIX44_MARKETDATAHISTORYMETADATAREPORT_H

#include "Message.h"

namespace FIX44
{

  class MarketDataHistoryMetadataReport : public Message
  {
  public:
    MarketDataHistoryMetadataReport() : Message(MsgType()) {}
    MarketDataHistoryMetadataReport(const FIX::Message& m) : Message(m) {}
    MarketDataHistoryMetadataReport(const Message& m) : Message(m) {}
    MarketDataHistoryMetadataReport(const MarketDataHistoryMetadataReport& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1014"); }

    MarketDataHistoryMetadataReport(
      const FIX::MDHstMetaReqID& aMDHstMetaReqID,
      const FIX::MDHstMetaReqResult& aMDHstMetaReqResult,
      const FIX::Symbol& aSymbol )
    : Message(MsgType())
    {
      set(aMDHstMetaReqID);
      set(aMDHstMetaReqResult);
      set(aSymbol);
    }

    FIELD_SET(*this, FIX::MDHstMetaReqID);
    FIELD_SET(*this, FIX::MDHstMetaReqResult);
    FIELD_SET(*this, FIX::FileId);
    FIELD_SET(*this, FIX::Symbol);
    FIELD_SET(*this, FIX::ForexPriceType);
    FIELD_SET(*this, FIX::HstGraphPeriodID);
    FIELD_SET(*this, FIX::Text);
  };

}

#endif
