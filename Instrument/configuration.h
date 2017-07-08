#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QFile>
#include <QtXml>
#include <Templates/Singleton.h>

#include <Instrument/configuration.h>
#include <Logger/logger.h>
#include <Exceptions/exceptions.h>

class Configuration : public Templates::Singleton<Instrument::Configuration>
{
    friend class Templates::Singleton<Instrument::Configuration>;
public:
    void ReadParameters()
    {
        try
        {
            logger::Info("Configuration >>");

            std::string configurationPath = QDir::currentPath().toStdString();
            configurationPath += "/Configuration.xml";

            QFile file(configurationPath.c_str());
            if (!file.open(QIODevice::ReadOnly))
            {
                logger::Error("Configuration:: Error Opening Configuration.xml!");
                throw;
            }
            // Set data into the QDomDocument before processing
            QDomDocument configurationXml;
            configurationXml.setContent(&file);
            file.close();

            QDomElement root = configurationXml.documentElement();
            QDomElement element = root.firstChild().toElement();
            while (!element.isNull())
            {
                if (element.tagName() == "instrument")
                    _InstrumentVersion = element.attribute("type", "");

                element = element.nextSibling().toElement();
            }

            if (_InstrumentVersion.isEmpty())
            {
                logger::Error("Configuration:: Error Version is empty!");
                throw ConfigurationException(_InstrumentVersion.toStdString());
            }
            logger::Info("Instrument version = %s", _InstrumentVersion.toStdString());
            logger::Info("Configuration <<");
        }
        catch (ConfigurationException &cException)
        {
            logger::Info("Configuration Parameter = %s is missing!", cException.GetError());
        }
    }
protected:

private:
    Configuration(){}
    ~Configuration(){}

    QString _InstrumentVersion;

};

#endif // CONFIGURATION_H

