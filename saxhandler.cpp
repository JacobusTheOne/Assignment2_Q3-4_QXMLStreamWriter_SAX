#include "saxhandler.h"


SaxHandler::SaxHandler()
{

}

bool SaxHandler::readFile(const QString &fileName)
{
        QFile file(fileName);
        QXmlInputSource inputSource(&file);
        QXmlSimpleReader reader;
        reader.setContentHandler(this);
        reader.setErrorHandler(this);
        return reader.parse(inputSource);
}



QStringList SaxHandler::getList2()
{
   return xmlListChars;
}

bool SaxHandler::startElement(const QString &, const QString &, const QString &, const QXmlAttributes &atts)
{

    if (atts.length()>0) {
        QString fieldValue = atts.value(0);
        xmlListChars.append(fieldValue);
    }

       return true;
}

bool SaxHandler::endElement(const QString &, const QString &, const QString &)
{
    return true;
}

bool SaxHandler::characters(const QString &str)
{
    QString temp = str;
    temp = temp.trimmed();
    if(temp.length()>0)
     xmlListChars.append(temp);
    return true;
}

bool SaxHandler::fatalError(const QXmlParseException &exception)
{
    QTextStream cout(stdout);
    cout << "Parse error at line " << exception.lineNumber()
                 << ", " << "column " << exception.columnNumber() << ": "
                 << qPrintable(exception.message()) << endl;
       return false;
}
