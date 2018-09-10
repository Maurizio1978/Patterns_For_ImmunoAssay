#ifndef READERCONTROLLER_H
#define READERCONTROLLER_H

#include "boost/shared_ptr.hpp"
#include "reader.h"
#include "mainwindow.h"

class ReaderController
{
public:
    ReaderController(MainWindow* iMainWindowPtr, Reader* iReader);
    ~ReaderController();

    void Initialize();

private:
    MainWindow* _MainWindowPtr;
    Reader* _ReaderPtr;
};

#endif // READERCONTROLLER_H
