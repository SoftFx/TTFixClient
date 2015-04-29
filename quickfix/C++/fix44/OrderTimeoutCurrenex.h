#ifndef FIX44_ORDERTIMEOUTCURRENEX_H
#define FIX44_ORDERTIMEOUTCURRENEX_H

#include "Message.h"

namespace FIX44
{

  class OrderTimeoutCurrenex : public Message
  {
  public:
    OrderTimeoutCurrenex() : Message(MsgType()) {}
    OrderTimeoutCurrenex(const FIX::Message& m) : Message(m) {}
    OrderTimeoutCurrenex(const Message& m) : Message(m) {}
    OrderTimeoutCurrenex(const OrderTimeoutCurrenex& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U3"); }

    OrderTimeoutCurrenex(
      const FIX::ClOrdID& aClOrdID )
    : Message(MsgType())
    {
      set(aClOrdID);
    }

    FIELD_SET(*this, FIX::ClOrdID);
  };

}

#endif
