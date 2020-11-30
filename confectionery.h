#ifndef CONFECTIONERY_H
#define CONFECTIONERY_H
#include "stock.h"

class Confectionery : public Stock
{
    Q_PROPERTY(int weight READ getWeight WRITE setWeight)
public:
    Confectionery();
    Confectionery(QString i,int q,int w);
    int getWeight();
    void setWeight(int w);
    QString toString();   
private:
    int weight;
};

#endif // CONFECTIONERY_H
