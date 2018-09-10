#include "readercontroller.h"

#include <QThread>

ReaderController::ReaderController(MainWindow *iMainWindowPtr, Reader *iReader) :
    _MainWindowPtr(iMainWindowPtr),
    _ReaderPtr(iReader)
{

}

ReaderController::~ReaderController()
{

}

void ReaderController::Initialize()
{
    QThread* aReaderInitThread = new QThread();

    _ReaderPtr->moveToThread(aReaderInitThread);

    QObject::connect(aReaderInitThread, SIGNAL (started()), _ReaderPtr, SLOT (Initialize()));

    QObject::connect(_ReaderPtr, SIGNAL (InitializationStarted()), _MainWindowPtr, SLOT (slot_started()));
    QObject::connect(_ReaderPtr, SIGNAL (Initialized()), _MainWindowPtr, SLOT (slot_finished()));

    QObject::connect(_ReaderPtr, SIGNAL (Initialized()), aReaderInitThread, SLOT (quit()));
    QObject::connect(_ReaderPtr, SIGNAL (Initialized()), _ReaderPtr, SLOT (deleteLater()));

    QObject::connect(aReaderInitThread, SIGNAL (finished()), aReaderInitThread, SLOT (deleteLater()));

    aReaderInitThread->start();
}

