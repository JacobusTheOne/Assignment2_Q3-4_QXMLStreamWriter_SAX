#include "readingmaterial.h"

ReadingMaterial::ReadingMaterial():Stock::Stock()
{
    frequency = "";
}

ReadingMaterial::ReadingMaterial(QString i, int q, QString f):Stock::Stock(i,q)
{
    frequency = f;
}

QString ReadingMaterial::getFrequency()
{
    return frequency;
}

void ReadingMaterial::setFrequency(QString f)
{
    frequency = f;
}

QString ReadingMaterial::toString()
{
    QString list;
    list.append(Stock::toString());
    list.append(", frequency: "+frequency);
    return list;
}


