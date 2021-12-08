#ifndef FIX44_CLOSEPOSITIONREQUEST_H
#define FIX44_CLOSEPOSITIONREQUEST_H

#include "Message.h"

namespace FIX44
{

  class ClosePositionRequest : public Message
  {
  public:
    ClosePositionRequest() : Message(MsgType()) {}
    ClosePositionRequest(const FIX::Message& m) : Message(m) {}
    ClosePositionRequest(const Message& m) : Message(m) {}
    ClosePositionRequest(const ClosePositionRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1008"); }

    ClosePositionRequest(
      const FIX::ClosePosReqID& aClosePosReqID,
      const FIX::PosCloseType& aPosCloseType )
    : Message(MsgType())
    {
      set(aClosePosReqID);
      set(aPosCloseType);
    }

    FIELD_SET(*this, FIX::ClosePosReqID);
    FIELD_SET(*this, FIX::OrderID);
    FIELD_SET(*this, FIX::SecondaryOrderID);
    FIELD_SET(*this, FIX::ClAppID);
    FIELD_SET(*this, FIX::PosCloseType);
    FIELD_SET(*this, FIX::Quantity);
  };

}

#endif
