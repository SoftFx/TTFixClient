#ifndef FIX44_FILECHUNKREQREJECT_H
#define FIX44_FILECHUNKREQREJECT_H

#include "Message.h"

namespace FIX44
{

  class FileChunkReqReject : public Message
  {
  public:
    FileChunkReqReject() : Message(MsgType()) {}
    FileChunkReqReject(const FIX::Message& m) : Message(m) {}
    FileChunkReqReject(const Message& m) : Message(m) {}
    FileChunkReqReject(const FileChunkReqReject& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1012"); }

    FileChunkReqReject(
      const FIX::FileId& aFileId,
      const FIX::FileReqRejReason& aFileReqRejReason )
    : Message(MsgType())
    {
      set(aFileId);
      set(aFileReqRejReason);
    }

    FIELD_SET(*this, FIX::FileId);
    FIELD_SET(*this, FIX::ChunkId);
    FIELD_SET(*this, FIX::FileReqRejReason);
    FIELD_SET(*this, FIX::Text);
  };

}

#endif
