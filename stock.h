#ifndef STOCK_H
#define STOCK_H
#include <QString>
#include <QObject>


class Stock : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString item READ getItem WRITE setItem)
    Q_PROPERTY(int quantity READ getQuantity WRITE setQuantity)
public:
    Stock();
    Stock(QString i,int q);
    QString getItem();
    int getQuantity();
    void setItem(QString i);
    void setQuantity(int q);
    virtual QString toString() = 0;

private:
    QString item;
    int quantity;


};

#endif // STOCK_H
