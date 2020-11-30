#include "xmlreader.h"
#include <QtXml>
#include <QFile>
#include <QTextStream>


/*
XmlReader::XmlReader()
{

}

void XmlReader::readDocument(QString fName)
{
    QTextStream cout(stdout);
    //QDomDocument class represents an XML document
    QDomDocument xmlBOM;
    //Load xml file as raw data
    QFile f(fName);
    if(!f.open(QIODevice::ReadOnly))
    {
        //Error while loading file
        cout << "Error while loading file" << endl;
    }
    xmlBOM.setContent(&f);
    f.close();
    // Extract the root markup
    QDomElement root=xmlBOM.documentElement();

    //Get root names and attributes
    QString Type=root.tagName();
    //QString Board=root.attribute("BOARD","No name");
    //int Year=root.attribute("YEAR","1900").toInt();

    //Display root data
    cout << "Type = " << Type.toStdString().c_str() << endl;
    //cout << "Board = " << Board.toStdString().c_str() << endl;
    //cout << "Year = " << Year << endl;
    cout << endl;



    //Get the first child of the root (Markup COMPONENT is expected)
    QDomElement Component=root.firstChild().toElement();
    //cout << Component.attribute("stockItem Type","Confectionery") << endl;
    cout << Component.tagName() << endl;
    //Loop while there is a child
    while(!Component.isNull())
    {
        //cout << Component.isNull() << endl;
        //Check if the child tag name is COMPONENT
        if(Component.attribute("stockItem Type","Confectionery")=="Confectionery")
        {
            //Read and display the component ID
            //QString ID=Component.attribute("ID","No ID");
            //Get the first child of the component
            QDomElement Child=Component.firstChild().toElement();

            QString item;
            QString quantity;
            QString weight;
            //Read each child of the component node
            while(!Child.isNull())
            {
                //Read Name and value
                if(Child.tagName()=="item") item=Child.firstChild().toText().data();
                if(Child.tagName()=="quantity") quantity=Child.firstChild().toText().data();
                if(Child.tagName()=="weight") weight=Child.firstChild().toText().data();
                //Next child
                //cout << Child.tagName() << endl;
                Child = Child.nextSibling().toElement();

            }
            //Display component data
            cout << "item        = " << item.toStdString().c_str() << endl;
            cout << "quantity    = " << quantity.toStdString().c_str() << endl;
            cout << "weight      = " << weight.toStdString().c_str() << endl;

        }
        Component = Component.nextSibling().toElement();
        cout << Component.tagName() << endl;
    }


}

*/
