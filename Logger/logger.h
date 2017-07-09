#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <sstream>
#include <tinythread.h>
#include <time.h>
#include <QFileDialog>

#include <Templates/Singleton.h>

using namespace std;

namespace
{
    int kMaxNumberOfMessagesPerFile = 3;
}

class Logger : public Templates::Singleton<Logger>
{
    friend class Templates::Singleton<Logger>;

public:
    static void Info(const std::string& strMessage)
    {
        Instance().operator << ("[Info] " + strMessage);
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

    Logger& operator << (const std::string& strMessage)
    {
        time_t aCurrTime;
        time(&aCurrTime);
        struct tm *aCurrTmPtr = localtime(&aCurrTime);

        if (!_FileStream.is_open())
        {
            std::string aCurrentDirectory = QDir::currentPath().toStdString();

            _FileName << aCurrentDirectory << "/log/" << (1900 + aCurrTmPtr->tm_year) << "_" <<
                         aCurrTmPtr->tm_mon << "_" << aCurrTmPtr->tm_mday << "_" <<
                         aCurrTmPtr->tm_hour << "_" << aCurrTmPtr->tm_min << ".log";

//            aCurrentDirectory =+ "/log/";
//            _FileName << aCurrentDirectory;
            std::string aPattern = _FileName.str();

//            std::string cristo = aCurrentDirectory.append("/log/cristo.log");

//            _FileName << cristo;
            _FileStream.open(aPattern.c_str(), std::ofstream::out | std::ofstream::app);
        }

        logger_lock.lock();
        _FileStream << "[" << aCurrTmPtr->tm_hour << ":" << aCurrTmPtr->tm_min << ":" << aCurrTmPtr->tm_sec << "] ---> " << strMessage << std::endl;
        logger_lock.unlock();

        if (++_NumberOfLines > kMaxNumberOfMessagesPerFile)
        {
            _FileStream.close();
        }

        return *this;
    }

//    static void Info(const std::string& strFormat, const std::string& value);
//    static void Info(const std::string& strFormat, const int& value);

//    static void Error(const std::string& strMessage);
//    static void Error(const std::string& strFormat, const std::string& value);
//    static void Error(const std::string& strFormat, const int& value);

};

//class logger
//{
//public:
//    static void Info(const string& strMessage);
//    static void Info(const string& strFormat, const string& value);
//    static void Info(const string& strFormat, const int& value);

//    static void Error(const string& strMessage);
//    static void Error(const string& strFormat, const string& value);
//    static void Error(const string& strFormat, const int& value);

//private:
//    static logger& GetInstance();
//    logger& operator << (const string& strMessage);

//    logger(logger const&){}
//    logger& operator=(logger const&){}

//    logger();
//    ~logger();

//    static stringstream m_FileName;
//    static ofstream m_FileStream;
//    static tthread::mutex logger_lock;
//};

#endif // LOGGER_H
