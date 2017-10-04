#include "mainwindow.h"
#include <QApplication>
#include "Logger/logger.h"

#include "boost/shared_ptr.hpp"

#include "Factory/factory.h"
#include "Factory/mago4factory.h"

#include <macros.h>
#include <stdio.h>

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

        log(INFO, "Application does something");

        log(INFO, "Application end");
    }
    catch (...)
    {

    }
    return a.exec();
}
