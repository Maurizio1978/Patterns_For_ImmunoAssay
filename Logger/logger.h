#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <sstream>
#include <tinythread.h>
#include <time.h>
#include <QFileDialog>

#include <Templates/Singleton.h>
#include <boost/lexical_cast.hpp>

using namespace std;

namespace
{
    const int kMaxNumberOfMessagesPerFile = 10;
    const int kMinValueNotToConvert = 10;

    const std::string kZero = "0";
}

class Logger : public Templates::Singleton<Logger>
{
    friend class Templates::Singleton<Logger>;

public:
      static void Dump(const int iLevel, const char* iMessage, const int iLine, const char* iFile)
      {
          Instance().Log(iLevel, iMessage, iLine, iFile);
      }

protected:
    ~Logger()
    {
        _FileStream.close();
    }

private:
    stringstream _FileName;
    ofstream _FileStream;
    tthread::mutex logger_lock;

    int _NumberOfLines;

    void Log(const int iLevel, const std::string& iMessage, int iLine, const std::string& iFile)
    {
        time_t aCurrTime;
        time(&aCurrTime);
        struct tm *aCurrTmPtr = localtime(&aCurrTime);

        std::string aMonth = Format(aCurrTmPtr->tm_mon + 1);
        std::string aDay = Format(aCurrTmPtr->tm_mday);
        std::string aHour = Format(aCurrTmPtr->tm_hour);
        std::string aMin = Format(aCurrTmPtr->tm_min);
        std::string aSec = Format(aCurrTmPtr->tm_sec);

        if (!_FileStream.is_open())
        {
            std::string aCurrentDirectory = QDir::currentPath().toStdString();

            _FileName << aCurrentDirectory << "/log/" <<
                         (1900 + aCurrTmPtr->tm_year) << "_" <<
                         aMonth << "_" <<
                         aDay << "_" <<
                         aHour << "_" <<
                         aMin << "_" <<
                         aSec << ".log";

            std::string aPattern = _FileName.str();

            _FileStream.open(aPattern.c_str(), std::ofstream::out | std::ofstream::app);

            _FileName.str(std::string());
        }

        logger_lock.lock();
        _FileStream << "[" << aHour << ":" <<
                              aMin << ":" <<
                              aSec << "] ---> " <<
                              iMessage << " at line:" <<
                              iLine << " -- in file:" <<
                              iFile << std::endl;
        logger_lock.unlock();

        if (++_NumberOfLines > kMaxNumberOfMessagesPerFile)
        {
            _NumberOfLines = 0;
            _FileStream.close();
        }
    }

    const std::string Format(const int iInputValue) const
    {
        std::string aOutputString;
        std::string aOriginalValue = boost::lexical_cast<std::string>(iInputValue);
        if (iInputValue < kMinValueNotToConvert)
        {
            aOutputString = kZero;
            aOutputString += aOriginalValue;
        }
        else
        {
            aOutputString = aOriginalValue;
        }
        return aOutputString;
    }
};
#endif // LOGGER_H
