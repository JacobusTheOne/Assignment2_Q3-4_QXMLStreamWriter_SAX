#include "stock.h"

Stock::Stock()
{
    item = "";
    quantity = 0;
}

Stock::Stock(QString i, int q)
{
    item = i;
    quantity = q;
}

QString Stock::getItem()
{
    return item;
}

int Stock::getQuantity()
{
    return quantity;
}

void Stock::setItem(QString i)
{
    item = i;
}

void Stock::setQuantity(int q)
{
    quantity = q;
}




QString Stock::toString()
{
    QString list;
    list.append("item: "+item);
    list.append(", quantity: "+QString::number(quantity));
    return list;
}
