#ifndef FIX44_CURRENCYLISTREQUEST_H
#define FIX44_CURRENCYLISTREQUEST_H

#include "Message.h"

namespace FIX44
{

  class CurrencyListRequest : public Message
  {
  public:
    CurrencyListRequest() : Message(MsgType()) {}
    CurrencyListRequest(const FIX::Message& m) : Message(m) {}
    CurrencyListRequest(const Message& m) : Message(m) {}
    CurrencyListRequest(const CurrencyListRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1020"); }

    CurrencyListRequest(
      const FIX::CurrencyReqID& aCurrencyReqID,
      const FIX::CurrencyListRequestType& aCurrencyListRequestType )
    : Message(MsgType())
    {
      set(aCurrencyReqID);
      set(aCurrencyListRequestType);
    }

    FIELD_SET(*this, FIX::CurrencyReqID);
    FIELD_SET(*this, FIX::CurrencyListRequestType);
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::EncodedTextLen);
    FIELD_SET(*this, FIX::EncodedText);
  };

}

#endif
