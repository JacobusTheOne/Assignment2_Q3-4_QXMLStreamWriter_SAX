#ifndef STOCKFACTORY_H
#define STOCKFACTORY_H
#include "stock.h"
#include "confectionery.h"
#include "readingmaterial.h"
#include <QList>

class StockFactory
{
public:
    StockFactory();

    Stock *createStock(QString stockType,QString i,int q,QString f);
    Stock *createStock(QString stockType,QString i,int q,int w);


};

#endif // STOCKFACTORY_H
