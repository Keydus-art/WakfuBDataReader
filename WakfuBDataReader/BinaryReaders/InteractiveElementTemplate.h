#include "BaseBinaryReader.h"

class InteractiveElementTemplate : public BaseBinaryReader
{
public:
    InteractiveElementTemplate() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("int");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadByte("byte");
            r->ReadShort("short");
            r->ReadString("string");
            r->ReadInt("int");
            r->ReadIntArray("int array");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadShort("short");
            r->ReadInt("int");
            r->ReadIntArray("int array");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};