#include "BaseBinaryReader.h"

class MagiCraftLootList : public BaseBinaryReader
{
public:
    MagiCraftLootList() {}

    QString GetColumns()
    {
        return QString("int|byte|int");
    }

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            QVariantList d;

            r->SetBufferPosition(row.offset);

            // Struct
            d << r->ReadInt();
            d << r->ReadByte();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
