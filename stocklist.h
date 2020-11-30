#ifndef STOCKLIST_H
#define STOCKLIST_H
#include <QList>
#include <QObject>
#include "stock.h"
#include <QXmlStreamWriter>

class StockList
{
public:
    static StockList* getInstance();
    void addStock(Stock* st);
    QList<Stock *> returnList(QString stockType);
    void writeToFile(QString fname);
private:
    StockList(){};
    static StockList* m_Instance;
    QList<Stock*> confList;
    QList<Stock*> readList;
    QXmlStreamWriter writer;

};

#endif // STOCKLIST_H
