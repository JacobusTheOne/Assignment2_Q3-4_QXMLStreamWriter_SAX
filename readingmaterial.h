#ifndef READINGMATERIAL_H
#define READINGMATERIAL_H
#include "stock.h"

class ReadingMaterial : public Stock
{
    Q_PROPERTY(QString frequency READ getFrequency WRITE setFrequency)
public:
    ReadingMaterial();
    ReadingMaterial(QString i,int q,QString f);
    QString getFrequency();
    void setFrequency(QString f);
    QString toString();

private:
    QString frequency;
};

#endif // READINGMATERIAL_H
