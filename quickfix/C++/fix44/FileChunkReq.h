#ifndef FIX44_FILECHUNKREQ_H
#define FIX44_FILECHUNKREQ_H

#include "Message.h"

namespace FIX44
{

  class FileChunkReq : public Message
  {
  public:
    FileChunkReq() : Message(MsgType()) {}
    FileChunkReq(const FIX::Message& m) : Message(m) {}
    FileChunkReq(const Message& m) : Message(m) {}
    FileChunkReq(const FileChunkReq& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1004"); }

    FileChunkReq(
      const FIX::FileId& aFileId )
    : Message(MsgType())
    {
      set(aFileId);
    }

    FIELD_SET(*this, FIX::FileId);
    FIELD_SET(*this, FIX::ChunkId);
  };

}

#endif
