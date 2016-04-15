#ifndef FIX44_TWOFACTORLOGON_H
#define FIX44_TWOFACTORLOGON_H

#include "Message.h"

namespace FIX44
{

  class TwoFactorLogon : public Message
  {
  public:
    TwoFactorLogon() : Message(MsgType()) {}
    TwoFactorLogon(const FIX::Message& m) : Message(m) {}
    TwoFactorLogon(const Message& m) : Message(m) {}
    TwoFactorLogon(const TwoFactorLogon& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1022"); }

    TwoFactorLogon(
      const FIX::TwoFactorReason& aTwoFactorReason )
    : Message(MsgType())
    {
      set(aTwoFactorReason);
    }

    FIELD_SET(*this, FIX::TwoFactorReason);
    FIELD_SET(*this, FIX::OneTimePassword);
    FIELD_SET(*this, FIX::ExpireTime);
    FIELD_SET(*this, FIX::Text);
  };

}

#endif
