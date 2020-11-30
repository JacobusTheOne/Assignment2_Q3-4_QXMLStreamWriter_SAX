#include "stockfactory.h"

StockFactory::StockFactory()
{

}



Stock* StockFactory::createStock(QString stockType, QString i, int q, QString f)
{
    ReadingMaterial *rm = new ReadingMaterial(i,q,f);
    rm->setObjectName(stockType);
    return rm;
}

Stock *StockFactory::createStock(QString stockType, QString i, int q, int w)
{
    Confectionery *cf = new Confectionery(i,q,w);
    cf->setObjectName(stockType);
    return cf;
}
