#include "mainwindow.h"
#include <QApplication>

#include "boost/shared_ptr.hpp"

#include "Factory/factory.h"
#include "Factory/mago4factory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    boost::shared_ptr<Factory> aFactorySP(new Mago4Factory);
    aFactorySP->createDilutionRack();


    return a.exec();
}
