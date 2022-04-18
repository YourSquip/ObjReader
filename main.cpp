#include <QCoreApplication>
#include "objreader.h"
#include "objreadertests.h"
#include <QDebug>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ObjReaderTests tests;
    QTest::qExec(&tests);

    //file to read
    QString fileName = "";//file directory
    ObjReadingTools::ObjData objData;

    QString errorMsg;
    if (!ObjReadingTools::read(fileName, objData, errorMsg)) {
        qDebug() << errorMsg;
        return -1;
    }
    //file to save
    QFile fileOut("");//file directory
    ObjReadingTools::save(objData, fileOut,errorMsg);

    return 0;
}
