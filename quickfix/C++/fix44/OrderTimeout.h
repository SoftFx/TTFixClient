#ifndef FIX44_ORDERTIMEOUT_H
#define FIX44_ORDERTIMEOUT_H

#include "Message.h"

namespace FIX44
{

  class OrderTimeout : public Message
  {
  public:
    OrderTimeout() : Message(MsgType()) {}
    OrderTimeout(const FIX::Message& m) : Message(m) {}
    OrderTimeout(const Message& m) : Message(m) {}
    OrderTimeout(const OrderTimeout& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U3"); }

    OrderTimeout(
      const FIX::ClOrdID& aClOrdID )

    : Message(MsgType())
    {
      set(aClOrdID);
    }

    FIELD_SET(*this, FIX::ClOrdID);
   
  };
}

#endif
