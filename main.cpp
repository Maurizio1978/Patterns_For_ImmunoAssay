#include "mainwindow.h"
#include <QApplication>
#include "Logger/logger.h"

#include "boost/shared_ptr.hpp"

#include "Factory/factory.h"
#include "Factory/mago4factory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Logger::Info("Main >>> main::Application Start");


    boost::shared_ptr<Factory> aFactorySP(new Mago4Factory);
    aFactorySP->createDilutionRack();


    return a.exec();
}
