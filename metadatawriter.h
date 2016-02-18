#ifndef METADATAWRITER_H
#define METADATAWRITER_H

#include "closet.h"

#include <QWidget>
#include <QString>

class MetaDataWriter : public QWidget
{
    Q_OBJECT
public:
    MetaDataWriter();
    ~MetaDataWriter() {}
    void load(Closet &clst);

public slots:
    void save();

private:
    QString m_filename;
    Closet * m_closet;

};

#endif // METADATAWRITER_H
