#include "BaseBinaryReader.h"

class CraftInteractiveElementParam : public BaseBinaryReader
{
public:
    CraftInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadIntArray("int array");
            r->ReadByte("byte");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};