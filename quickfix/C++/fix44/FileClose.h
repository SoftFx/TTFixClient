#ifndef FIX44_FILECLOSE_H
#define FIX44_FILECLOSE_H

#include "Message.h"

namespace FIX44
{

  class FileClose : public Message
  {
  public:
    FileClose() : Message(MsgType()) {}
    FileClose(const FIX::Message& m) : Message(m) {}
    FileClose(const Message& m) : Message(m) {}
    FileClose(const FileClose& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1012"); }

    FileClose(
      const FIX::FileId& aFileId )
    : Message(MsgType())
    {
      set(aFileId);
    }

    FIELD_SET(*this, FIX::FileId);
  };

}

#endif
