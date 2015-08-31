#ifndef FIX44_CURRENCYLIST_H
#define FIX44_CURRENCYLIST_H

#include "Message.h"

namespace FIX44
{

  class CurrencyList : public Message
  {
  public:
    CurrencyList() : Message(MsgType()) {}
    CurrencyList(const FIX::Message& m) : Message(m) {}
    CurrencyList(const Message& m) : Message(m) {}
    CurrencyList(const CurrencyList& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1021"); }

    CurrencyList(
      const FIX::CurrencyReqID& aCurrencyReqID,
      const FIX::CurrencyResponseID& aCurrencyResponseID,
      const FIX::CurrencyRequestResult& aCurrencyRequestResult )
    : Message(MsgType())
    {
      set(aCurrencyReqID);
      set(aCurrencyResponseID);
      set(aCurrencyRequestResult);
    }

    FIELD_SET(*this, FIX::CurrencyReqID);
    FIELD_SET(*this, FIX::CurrencyResponseID);
    FIELD_SET(*this, FIX::CurrencyRequestResult);
    FIELD_SET(*this, FIX::TotNoRelatedSym);
    FIELD_SET(*this, FIX::NoRelatedSym);
    class NoRelatedSym: public FIX::Group
    {
    public:
    NoRelatedSym() : FIX::Group(146,15,FIX::message_order(15,10137,10135,58,354,355,0)) {}
      FIELD_SET(*this, FIX::Currency);
      FIELD_SET(*this, FIX::CurrencyPrecision);
      FIELD_SET(*this, FIX::CurrencySortOrder);
      FIELD_SET(*this, FIX::Text);
      FIELD_SET(*this, FIX::EncodedTextLen);
      FIELD_SET(*this, FIX::EncodedText);
    };
  };

}

#endif
