#include "confectionery.h"

Confectionery::Confectionery():Stock::Stock()
{
    weight = 0;
}

Confectionery::Confectionery(QString i, int q, int w):Stock::Stock(i,q)
{
    weight = w;
}

int Confectionery::getWeight()
{
    return weight;
}

void Confectionery::setWeight(int w)
{
    weight = w;
}

QString Confectionery::toString()
{
    QString list;
    list.append(Stock::toString());
    list.append(", weight: "+QString::number(weight));
    return list;
}


