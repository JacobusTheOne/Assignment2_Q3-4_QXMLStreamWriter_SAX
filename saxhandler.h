#ifndef SAXHANDLER_H
#define SAXHANDLER_H
#include <QXmlDefaultHandler>
#include <QString>

class SaxHandler : public QXmlDefaultHandler
{
public:
    SaxHandler();
    bool readFile(const QString &fileName);
    QStringList getList2();
protected:
    bool startElement(const QString &namespaceURI,
                         const QString &localName,
                         const QString &qName,
                         const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI,
                       const QString &localName,
                       const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);
private:
    QStringList xmlListChars;

};

#endif // SAXHANDLER_H
