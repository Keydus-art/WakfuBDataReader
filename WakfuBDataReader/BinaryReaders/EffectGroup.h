#include "BaseBinaryReader.h"

class EffectGroup : public BaseBinaryReader
{
public:
    EffectGroup() {}

    QString GetColumns()
    {
        return QString("int|int array");
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
            d << r->ReadIntArray();

            data.push_back(d);
        }

        emit Finished(data);
    }
};