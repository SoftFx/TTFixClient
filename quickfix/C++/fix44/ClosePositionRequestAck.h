#ifndef FIX44_CLOSEPOSITIONREQUESTACK_H
#define FIX44_CLOSEPOSITIONREQUESTACK_H

#include "Message.h"

namespace FIX44
{

  class ClosePositionRequestAck : public Message
  {
  public:
    ClosePositionRequestAck() : Message(MsgType()) {}
    ClosePositionRequestAck(const FIX::Message& m) : Message(m) {}
    ClosePositionRequestAck(const Message& m) : Message(m) {}
    ClosePositionRequestAck(const ClosePositionRequestAck& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1009"); }

    ClosePositionRequestAck(
      const FIX::ClosePosReqID& aClosePosReqID,
      const FIX::ClosePosReqResult& aClosePosReqResult )
    : Message(MsgType())
    {
      set(aClosePosReqID);
      set(aClosePosReqResult);
    }

    FIELD_SET(*this, FIX::ClosePosReqID);
    FIELD_SET(*this, FIX::ClosePosReqResult);
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::EncodedTextLen);
    FIELD_SET(*this, FIX::EncodedText);
    FIELD_SET(*this, FIX::NoPositions);
    class NoPositions: public FIX::Group
    {
    public:
    NoPositions() : FIX::Group(702,37,FIX::message_order(37,0)) {}
      FIELD_SET(*this, FIX::OrderID);
    };
  };

}

#endif
