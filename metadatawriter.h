#ifndef METADATAWRITER_H
#define METADATAWRITER_H

#include "closet.h"

#include <QString>

class MetaDataWriter
{
public:
    MetaDataWriter();
    void load(Closet &clst);
    void save(Closet &clst);

private:
    QString m_filename;
};

#endif // METADATAWRITER_H
