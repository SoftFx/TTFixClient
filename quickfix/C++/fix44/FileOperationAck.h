#ifndef FIX44_FILEOPERATIONACK_H
#define FIX44_FILEOPERATIONACK_H

#include "Message.h"

namespace FIX44
{

  class FileOperationAck : public Message
  {
  public:
    FileOperationAck() : Message(MsgType()) {}
    FileOperationAck(const FIX::Message& m) : Message(m) {}
    FileOperationAck(const Message& m) : Message(m) {}
    FileOperationAck(const FileOperationAck& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1012"); }

    FileOperationAck(
      const FIX::FileId& aFileId,
      const FIX::FileOpResult& aFileOpResult )
    : Message(MsgType())
    {
      set(aFileId);
      set(aFileOpResult);
    }

    FIELD_SET(*this, FIX::FileId);
    FIELD_SET(*this, FIX::ChunkId);
    FIELD_SET(*this, FIX::FileOpResult);
    FIELD_SET(*this, FIX::Text);
  };

}

#endif
