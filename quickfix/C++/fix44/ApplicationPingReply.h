#ifndef FIX44_APPLICATIONPINGREPLY_H
#define FIX44_APPLICATIONPINGREPLY_H

#include "Message.h"

namespace FIX44
{

  class ApplicationPingReply : public Message
  {
  public:
    ApplicationPingReply() : Message(MsgType()) {}
    ApplicationPingReply(const FIX::Message& m) : Message(m) {}
    ApplicationPingReply(const Message& m) : Message(m) {}
    ApplicationPingReply(const ApplicationPingReply& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U2"); }

    ApplicationPingReply(
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
