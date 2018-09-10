#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <macros.h>
#include <Logger/logger.h>

#include <QThread>
#include "Reader/reader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QThread* aReaderInitThread = new QThread();
//    Reader* aReaderPtr = new Reader();


//    aReaderPtr->moveToThread(aReaderInitThread);

//    QObject::connect(aReaderInitThread, SIGNAL (started()), aReaderPtr, SLOT (Initialize()));

////        QObject::connect(aReaderInitThread, SIGNAL (finished()), aReaderInitThread, SLOT (deleteLater()));

//    QObject::connect(aReaderPtr, SIGNAL (InitializationStarted()), this, SLOT (slot_started));
//    QObject::connect(aReaderPtr, SIGNAL (Initialized()), this, SLOT (slot_finished()));

//    QObject::connect(aReaderPtr, SIGNAL (Initialized()), aReaderInitThread, SLOT (quit()));
//    QObject::connect(aReaderPtr, SIGNAL (Initialized()), aReaderPtr, SLOT (deleteLater()));

//    QObject::connect(aReaderInitThread, SIGNAL (finished()), aReaderInitThread, SLOT (deleteLater()));

//    aReaderInitThread->start();
//    connect(&this->FutureWatcher, SIGNAL (finished()), this, SLOT (slot_finished()));

}


void MainWindow::slot_started()
{
    log(INFO, "slot_started");
    ui->ReaderInitProgressBar->setValue(0);
}

void MainWindow::slot_finished()
{
    log(INFO, "slot_finished");
    ui->ReaderInitProgressBar->setValue(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
