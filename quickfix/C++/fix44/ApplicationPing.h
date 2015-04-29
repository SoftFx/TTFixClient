#ifndef FIX44_APPLICATIONPING_H
#define FIX44_APPLICATIONPING_H

#include "Message.h"

namespace FIX44
{

  class ApplicationPing : public Message
  {
  public:
    ApplicationPing() : Message(MsgType()) {}
    ApplicationPing(const FIX::Message& m) : Message(m) {}
    ApplicationPing(const Message& m) : Message(m) {}
    ApplicationPing(const ApplicationPing& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1"); }

    ApplicationPing(
      const FIX::ApplicationPingID& aApplicationPingID,
      const FIX::TransactTime& aTransactTime )
    : Message(MsgType())
    {
      set(aApplicationPingID);
      set(aTransactTime);
    }

    FIELD_SET(*this, FIX::ApplicationPingID);
    FIELD_SET(*this, FIX::TransactTime);
  };

}

#endif
