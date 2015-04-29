#ifndef FIX44_MARKETDATAHISTORY_H
#define FIX44_MARKETDATAHISTORY_H

#include "Message.h"

namespace FIX44
{

  class MarketDataHistory : public Message
  {
  public:
    MarketDataHistory() : Message(MsgType()) {}
    MarketDataHistory(const FIX::Message& m) : Message(m) {}
    MarketDataHistory(const Message& m) : Message(m) {}
    MarketDataHistory(const MarketDataHistory& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1002"); }

    MarketDataHistory(
      const FIX::MarketHistReqID& aMarketHistReqID,
      const FIX::Symbol& aSymbol,
      const FIX::HstFrom& aHstFrom,
      const FIX::HstTo& aHstTo,
      const FIX::AllHstFrom& aAllHstFrom,
      const FIX::AllHstTo& aAllHstTo )
    : Message(MsgType())
    {
      set(aMarketHistReqID);
      set(aSymbol);
      set(aHstFrom);
      set(aHstTo);
      set(aAllHstFrom);
      set(aAllHstTo);
    }

    FIELD_SET(*this, FIX::MarketHistReqID);
    FIELD_SET(*this, FIX::Symbol);
    FIELD_SET(*this, FIX::HstFrom);
    FIELD_SET(*this, FIX::HstTo);
    FIELD_SET(*this, FIX::LastTickId);
    FIELD_SET(*this, FIX::ForexPriceType);
    FIELD_SET(*this, FIX::HstGraphPeriodID);
    FIELD_SET(*this, FIX::AllHstFrom);
    FIELD_SET(*this, FIX::AllHstTo);
    FIELD_SET(*this, FIX::HstBinData);
    FIELD_SET(*this, FIX::NoBars);
    class NoBars: public FIX::Group
    {
    public:
    NoBars() : FIX::Group(10004,10005,FIX::message_order(10005,10006,10007,10008,10009,10040,10041,0)) {}
      FIELD_SET(*this, FIX::BarHi);
      FIELD_SET(*this, FIX::BarLow);
      FIELD_SET(*this, FIX::BarOpen);
      FIELD_SET(*this, FIX::BarClose);
      FIELD_SET(*this, FIX::BarTime);
      FIELD_SET(*this, FIX::BarVolume);
      FIELD_SET(*this, FIX::BarVolumeEx);
    };
    FIELD_SET(*this, FIX::NoFiles);
    class NoFiles: public FIX::Group
    {
    public:
    NoFiles() : FIX::Group(10068,10017,FIX::message_order(10017,0)) {}
      FIELD_SET(*this, FIX::AttachedFileId);
    };
  };

}

#endif
