#ifndef FIX44_TRADETRANSACTIONREPORTREQUESTACK_H
#define FIX44_TRADETRANSACTIONREPORTREQUESTACK_H

#include "Message.h"

namespace FIX44
{

  class TradeTransactionReportRequestAck : public Message
  {
  public:
    TradeTransactionReportRequestAck() : Message(MsgType()) {}
    TradeTransactionReportRequestAck(const FIX::Message& m) : Message(m) {}
    TradeTransactionReportRequestAck(const Message& m) : Message(m) {}
    TradeTransactionReportRequestAck(const TradeTransactionReportRequestAck& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1016"); }

    TradeTransactionReportRequestAck(
      const FIX::TradeRequestID& aTradeRequestID,
      const FIX::TradeTransRepRequestResult& aTradeTransRepRequestResult )
    : Message(MsgType())
    {
      set(aTradeRequestID);
      set(aTradeTransRepRequestResult);
    }

    FIELD_SET(*this, FIX::TradeRequestID);
    FIELD_SET(*this, FIX::SubscriptionRequestType);
    FIELD_SET(*this, FIX::TotNumTradeReports);
    FIELD_SET(*this, FIX::CurNumTradeReports);
    FIELD_SET(*this, FIX::EndOfStrm);
    FIELD_SET(*this, FIX::TradeTransRepRequestResult);
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::EncodedTextLen);
    FIELD_SET(*this, FIX::EncodedText);
  };

}

#endif
