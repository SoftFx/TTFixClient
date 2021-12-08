#ifndef FIX44_DAILYACCOUNTSNAPSHOTREQUEST_H
#define FIX44_DAILYACCOUNTSNAPSHOTREQUEST_H

#include "Message.h"

namespace FIX44
{

  class DailyAccountSnapshotRequest : public Message
  {
  public:
    DailyAccountSnapshotRequest() : Message(MsgType()) {}
    DailyAccountSnapshotRequest(const FIX::Message& m) : Message(m) {}
    DailyAccountSnapshotRequest(const Message& m) : Message(m) {}
    DailyAccountSnapshotRequest(const DailyAccountSnapshotRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1025"); }

    DailyAccountSnapshotRequest(
      const FIX::SnapshotRequestID& aSnapshotRequestID )
    : Message(MsgType())
    {
      set(aSnapshotRequestID);
    }

    FIELD_SET(*this, FIX::SnapshotRequestID);
    FIELD_SET(*this, FIX::StrmngDirection);
    FIELD_SET(*this, FIX::StrmngBufSize);
    FIELD_SET(*this, FIX::StrmngPosID);
    FIELD_SET(*this, FIX::HstFrom);
    FIELD_SET(*this, FIX::HstTo);
  };

}

#endif
