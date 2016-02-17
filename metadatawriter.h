#ifndef METADATAWRITER_H
#define METADATAWRITER_H

#include "closet.h"

class MetaDataWriter
{
public:
    MetaDataWriter();
    void load(Closet &clst);
    void save(Closet &clst);
};

#endif // METADATAWRITER_H
