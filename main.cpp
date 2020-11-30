#include <QCoreApplication>
#include "stock.h"
#include "stockfactory.h"
#include "stocklist.h"
#include <QTextStream>
#include <QObject>
#include "xmlreader.h"
#include "saxhandler.h"
#include <QList>

static QTextStream cout(stdout);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    StockFactory sf;
    Stock* c1 = sf.createStock("Confectionery", "Kit Kat", 12, 65);
    Stock* c2 = sf.createStock("Confectionery", "Bar One", 15, 55);
    Stock* c3 = sf.createStock("Confectionery", "Chocolate Log", 11, 70);
    Stock* rm1 = sf.createStock("ReadingMaterial", "The Star", 100, "Daily");
    Stock* rm2 = sf.createStock("ReadingMaterial", "Die Burger", 70, "Daily");
    Stock* rm3 = sf.createStock("ReadingMaterial", "The Times", 100, "Monthly");




    cout << c1->toString() << endl;
    cout << c2->toString() << endl;
    cout << c3->toString() << endl;
    cout << rm1->toString() << endl;
    cout << rm2->toString() << endl;
    cout << rm3->toString() << endl;

    StockList* st = StockList::getInstance();
    st->addStock(c1);
    st->addStock(c2);
    st->addStock(c3);
    st->addStock(rm1);
    st->addStock(rm2);
    st->addStock(rm3);




    cout << "\nThe list after calling return list, specifying confectionery: \n" << endl;
    QList<Stock*> cList = st->returnList("Confectionery");
    for (int i=0; i<cList.size(); i++)
    cout << cList.at(i)->toString() << endl;

    cout << "\nThe list after calling return list, specifying ReadingMaterial: \n" << endl;
    QList<Stock*> rList = st->returnList("ReadingMaterial");
    for (int i=0; i<rList.size(); i++)
    cout << rList.at(i)->toString() << endl;

    cout << "\nWriting the newly created stock to file(Data.xml): \n" << endl;
    st->writeToFile("Data.xml");

    SaxHandler saxHandler;
    //Going to read data from a file into a list and I am going to create new stock from that list
    saxHandler.readFile("Data.xml");
    QStringList list2;

    list2 = saxHandler.getList2();

    QList<Stock*> stockList;
    QStringList names;
    for(int i = 0;i < list2.size();i+=4)
    {

            names.append(list2[i]);
            names.append(list2[i+1]);
            names.append(list2[i+2]);
            names.append(list2[i+3]);

            if(names[i]=="Confectionery")
            {
                Stock* cStock = sf.createStock(names[i], names[i+1], names[i+2].toDouble(), names[i+3].toDouble());
                stockList.append(cStock);
            }
            else
            {
                Stock* rStock = sf.createStock(names[i], names[i+1], names[i+2].toDouble(), names[i+3]);
                stockList.append(rStock);
            }
     }
    //The new stock that I have created from the xml file I am going to add to my Stocklist
    for(int i = 0;i < stockList.size();i++)
    {
        st->addStock(stockList[i]);
    }
    //Now I am going to display the updated list
    cout << "\n\nThe Confectionery list after it is read from file(Data.xml): \n\n" << endl;
    QList<Stock*> confList = st->returnList("Confectionery");
    for (int i=0; i<confList.size(); i++)
    cout << confList.at(i)->toString() << endl;

    cout << "\n\nThe Reading material list after it is read from file(Data.xml): \n\n" << endl;
    QList<Stock*> readList = st->returnList("ReadingMaterial");
    for (int i=0; i<readList.size(); i++)
    cout << readList.at(i)->toString() << endl;

    cout << "\n\nAs expected both lists doubled because of adding more stock from the xml file." << endl;
}
