#ifndef MACROS_H
#define MACROS_H

#include <stdio.h>
#include "Logger/logger.h"
#include <sstream>

#define INFO   1
#define DEBUG  2
#define ERROR  3

#define log(LEVEL, s) Logger::Dump(LEVEL, s, __LINE__, __FILE__)

//<< "Line No: " << __LINE__ << \
//                   " Function: " << __FUNCTION__ << \
//                   " Error: " << s // note I leave ; out

#endif // MACROS_H

