#ifndef FIX44_INITIALIZE_H
#define FIX44_INITIALIZE_H

#include "Message.h"

namespace FIX44
{

  class Initialize : public Message
  {
  public:
    Initialize() : Message(MsgType()) {}
    Initialize(const FIX::Message& m) : Message(m) {}
    Initialize(const Message& m) : Message(m) {}
    Initialize(const Initialize& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U4"); }

    Initialize(
      const FIX::TransactTime& aTransactTime )
    : Message(MsgType())
    {
      set(aTransactTime);
    }

    FIELD_SET(*this, FIX::TransactTime);
  };

}

#endif
