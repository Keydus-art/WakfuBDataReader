#include "BaseBinaryReader.h"

class ExchangeInteractiveElementParam : public BaseBinaryReader
{
public:
    ExchangeInteractiveElementParam() {}

    QString GetColumns()
    {
        return QString("int|int|int|byte|int|byte");
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
            d << r->ReadByte();
            d << r->ReadInt();
            d << r->ReadByte();

            data.push_back(d);
        }

        emit Finished(data);
    }
};