#include "stocklist.h"
#include <QMetaProperty>
#include <QTextStream>
#include <QObjectList>
#include <QFile>

QTextStream cout(stdout);


StockList* StockList::m_Instance = nullptr;

StockList* StockList::getInstance()
{
    if(!m_Instance)
    {
        m_Instance = new StockList();
    }
    return m_Instance;
}

void StockList::addStock(Stock *st)
{

    if(st->objectName()=="Confectionery")
    {
       confList.append(st);
    }
    else if(st->objectName()=="ReadingMaterial")
    {
       readList.append(st);
    }

}

QList<Stock *> StockList::returnList(QString stockType)
{
    if(stockType=="Confectionery")
    {
        return confList;
    }
    else
    {
        return readList;
    }


}

void StockList::writeToFile(QString fname)
{
    QFile file(fname);
    file.open(QIODevice::WriteOnly);

    writer.setDevice(&file);
    writer.setAutoFormatting(true);
    writer.writeStartElement("stockList");
    QStringList attributes, attributes2, temp1, temp2, temp3, temp4;
    //getting all the attributes if it is confectionery
    for(int i = 0;i < confList.size();i++)
    {
        attributes.append(confList.at(i)->toString().split(", ",QString::KeepEmptyParts));
    }
    for(int i = 0;i < attributes.size();i++)
    {
         temp1.append(attributes[i].split(": ",QString::KeepEmptyParts));
    }
    for(int i = 0;i < temp1.size();i++)
    {
         temp2.append(temp1[i].split("item",QString::KeepEmptyParts));
    }
    for(int i = 0;i < temp2.size();i++)
    {
         temp3.append(temp2[i].split("quantity",QString::KeepEmptyParts));
    }
    for(int i = 0;i < temp3.size();i++)
    {
         temp4.append(temp3[i].split("weight",QString::KeepEmptyParts));
    }
    temp4.removeAll(QString(""));
    attributes = temp4;

    //Getting all the attributes if it is reading material
    temp1.clear();
    temp2.clear();
    temp3.clear();
    temp4.clear();

    for(int i = 0;i < readList.size();i++)
    {
        attributes2.append(readList.at(i)->toString().split(", ",QString::KeepEmptyParts));
    }
    for(int i = 0;i < attributes.size();i++)
    {
         temp1.append(attributes2[i].split(": ",QString::KeepEmptyParts));
    }
    for(int i = 0;i < temp1.size();i++)
    {
         temp2.append(temp1[i].split("item",QString::KeepEmptyParts));
    }
    for(int i = 0;i < temp2.size();i++)
    {
         temp3.append(temp2[i].split("quantity",QString::KeepEmptyParts));
    }
    for(int i = 0;i < temp3.size();i++)
    {
         temp4.append(temp3[i].split("frequency",QString::KeepEmptyParts));
    }
    temp4.removeAll(QString(""));

    attributes2 = temp4;


    QXmlStreamAttributes atts;
    atts.append("","","Confectionery");
    for(int i = 0;i < attributes.size();i+=3)
    {


            writer.writeStartElement("stockItem");
            writer.writeAttribute("Type","Confectionery");
            writer.writeTextElement("item",attributes[i]);
            writer.writeTextElement("quantity",attributes[i+1]);
            writer.writeTextElement("weight",attributes[i+2]);

            writer.writeEndElement();


    }


    atts.clear();
    atts.append("Type","ReadingMaterial");
    for(int i = 0;i < attributes2.size();)
    {
            writer.writeStartElement("stockItem");
            writer.writeAttribute("Type","ReadingMaterial");
            writer.writeTextElement("item",attributes2[i]);
            writer.writeTextElement("quantity",attributes2[i+1]);
            writer.writeTextElement("frequency",attributes2[i+2]);
            i+=3;
            writer.writeEndElement();

    }
    writer.writeEndElement();

    file.close();
}
