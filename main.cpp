#include "mainwindow.h"
#include <QApplication>
#include <Logger/logger.h>

#include "boost/shared_ptr.hpp"

#include "Factory/factory.h"
#include "Factory/mago4factory.h"

#include <macros.h>
#include <stdio.h>

#include <Reader/readercontroller.h>
#include <Reader/reader.h>"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    try
    {

        log(INFO, "Application start");

        boost::shared_ptr<Factory> aFactorySP(new Mago4Factory);
        aFactorySP->createDilutionRack();

//        QThread* aReaderInitThread = new QThread();
        Reader* aReaderPtr = new Reader();
        ReaderController aReaderController(&w, aReaderPtr);
         aReaderController.Initialize();



//        aReaderPtr->moveToThread(aReaderInitThread);

//        QObject::connect(aReaderInitThread, SIGNAL (started()), aReaderPtr, SLOT (Initialize()));

//        QObject::connect(aReaderPtr, SIGNAL (InitializationStarted()), &w, SLOT (slot_started()));
//        QObject::connect(aReaderPtr, SIGNAL (Initialized()), &w, SLOT (slot_finished()));

//        QObject::connect(aReaderPtr, SIGNAL (Initialized()), aReaderInitThread, SLOT (quit()));
//        QObject::connect(aReaderPtr, SIGNAL (Initialized()), aReaderPtr, SLOT (deleteLater()));

//        QObject::connect(aReaderInitThread, SIGNAL (finished()), aReaderInitThread, SLOT (deleteLater()));

//        aReaderInitThread->start();

        log(INFO, "Application does something");

        log(INFO, "Application end");
    }
    catch (...)
    {

    }
    return a.exec();
}
