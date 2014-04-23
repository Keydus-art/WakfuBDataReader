#include "BaseBinaryReader.h"

class Zaap : public BaseBinaryReader
{
public:
    Zaap() {}

    QString GetColumns()
    {
        return QString("int|int|int|int|int|int|byte|bool|string|byte");
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
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadByte();
            d << r->ReadBool();
            d << r->ReadString();
            d << r->ReadByte();

            data.push_back(d);
        }

        emit Finished(data);
    }
};