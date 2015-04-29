#ifndef FIX44_COMPONENTSINFOREQUEST_H
#define FIX44_COMPONENTSINFOREQUEST_H

#include "Message.h"

namespace FIX44
{

  class ComponentsInfoRequest : public Message
  {
  public:
    ComponentsInfoRequest() : Message(MsgType()) {}
    ComponentsInfoRequest(const FIX::Message& m) : Message(m) {}
    ComponentsInfoRequest(const Message& m) : Message(m) {}
    ComponentsInfoRequest(const ComponentsInfoRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1018"); }

    FIELD_SET(*this, FIX::ClientQuoteHistoryVersion);
  };

}

#endif
