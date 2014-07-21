#include "BaseBinaryReader.h"

class AchievementVariable : public BaseBinaryReader
{
public:
    AchievementVariable() {}

    QString GetColumns()
    {
        return QString("int ID|string Name");
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
            d << r->ReadString();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
