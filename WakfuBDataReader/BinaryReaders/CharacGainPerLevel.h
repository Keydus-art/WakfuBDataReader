#include "BaseBinaryReader.h"

class CharacGainPerLevel : public BaseBinaryReader
{
public:
    CharacGainPerLevel() {}

    QString GetColumns()
    {
        return r->GetColumns();
    }

    void Read(Rows rows)
    {
        qint32 size = rows.size();
        r->FirstRow();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            QVariantList d;

            r->SetBufferPosition(row.offset);

            // Struct
            d << r->ReadShort();
            qint32 size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadByte();
                d << r->ReadFloat();
            }

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
