#include "BaseBinaryReader.h"

class InteractiveElementModel : public BaseBinaryReader
{
public:
    InteractiveElementModel() {}

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
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadByte("byte");
            r->ReadInt("int");
            r->ReadInt("int");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};