#ifndef FIX44_TRADETRANSACTIONREPORTREQUEST_H
#define FIX44_TRADETRANSACTIONREPORTREQUEST_H

#include "Message.h"

namespace FIX44
{

  class TradeTransactionReportRequest : public Message
  {
  public:
    TradeTransactionReportRequest() : Message(MsgType()) {}
    TradeTransactionReportRequest(const FIX::Message& m) : Message(m) {}
    TradeTransactionReportRequest(const Message& m) : Message(m) {}
    TradeTransactionReportRequest(const TradeTransactionReportRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1015"); }

    TradeTransactionReportRequest(
      const FIX::TradeRequestID& aTradeRequestID )
    : Message(MsgType())
    {
      set(aTradeRequestID);
    }

    FIELD_SET(*this, FIX::TradeRequestID);
    FIELD_SET(*this, FIX::SubscriptionRequestType);
    FIELD_SET(*this, FIX::StrmngDirection);
    FIELD_SET(*this, FIX::StrmngBufSize);
    FIELD_SET(*this, FIX::StrmngPosID);
    FIELD_SET(*this, FIX::HstFrom);
    FIELD_SET(*this, FIX::HstTo);
  };

}

#endif
