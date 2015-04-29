#ifndef FIX44_ACCOUNTINFOREQUEST_H
#define FIX44_ACCOUNTINFOREQUEST_H

#include "Message.h"

namespace FIX44
{

  class AccountInfoRequest : public Message
  {
  public:
    AccountInfoRequest() : Message(MsgType()) {}
    AccountInfoRequest(const FIX::Message& m) : Message(m) {}
    AccountInfoRequest(const Message& m) : Message(m) {}
    AccountInfoRequest(const AccountInfoRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1005"); }

    AccountInfoRequest(
      const FIX::AcInfReqID& aAcInfReqID )
    : Message(MsgType())
    {
      set(aAcInfReqID);
    }

    FIELD_SET(*this, FIX::AcInfReqID);
  };

}

#endif
