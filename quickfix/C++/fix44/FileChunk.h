#ifndef FIX44_FILECHUNK_H
#define FIX44_FILECHUNK_H

#include "Message.h"

namespace FIX44
{

  class FileChunk : public Message
  {
  public:
    FileChunk() : Message(MsgType()) {}
    FileChunk(const FIX::Message& m) : Message(m) {}
    FileChunk(const Message& m) : Message(m) {}
    FileChunk(const FileChunk& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1003"); }

    FileChunk(
      const FIX::FileId& aFileId,
      const FIX::ChunkId& aChunkId,
      const FIX::ChunksNo& aChunksNo,
      const FIX::RawDataLength& aRawDataLength,
      const FIX::RawData& aRawData,
      const FIX::FileSize& aFileSize )
    : Message(MsgType())
    {
      set(aFileId);
      set(aChunkId);
      set(aChunksNo);
      set(aRawDataLength);
      set(aRawData);
      set(aFileSize);
    }

    FIELD_SET(*this, FIX::FileId);
    FIELD_SET(*this, FIX::ChunkId);
    FIELD_SET(*this, FIX::ChunksNo);
    FIELD_SET(*this, FIX::RawDataLength);
    FIELD_SET(*this, FIX::RawData);
    FIELD_SET(*this, FIX::FileName);
    FIELD_SET(*this, FIX::FileSize);
  };

}

#endif
