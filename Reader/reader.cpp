#include "reader.h"
#include "Logger/logger.h"
#include <macros.h>
#include <unistd.h>

#include <QThread>

Reader::Reader()
{

}

Reader::~Reader()
{

}

void Reader::Initialize()
{
    log(INFO, "Initializing the Reader");

    emit InitializationStarted();

    QThread::msleep(2000);

    emit Initialized();
}


