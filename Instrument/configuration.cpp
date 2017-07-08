//#include <Instrument/configuration.h>
//#include <Logger/logger.h>
//#include <Exceptions/exceptions.h>

//namespace Instrument
//{
////---------------------------//
////Configuration::Configuration()
////{

////}

////---------------------------//
////Configuration::~Configuration()
////{
////    delete _Instance;
////}

////void Configuration::setA()
////{
////    logger::Info("setA >>");
////    int a = 1;
////}
////----------------------------------------//
//void Configuration::ReadParameters()
//{
//    try
//    {
//        logger::Info("Configuration >>");

//        std::string configurationPath = QDir::currentPath().toStdString();
//        configurationPath += "/Configuration.xml";

//        QFile file(configurationPath.c_str());
//        if (!file.open(QIODevice::ReadOnly))
//        {
//            logger::Error("Configuration:: Error Opening Configuration.xml!");
//            throw;
//        }
//        // Set data into the QDomDocument before processing
//        QDomDocument configurationXml;
//        configurationXml.setContent(&file);
//        file.close();

//        QDomElement root = configurationXml.documentElement();
//        QDomElement element = root.firstChild().toElement();
//        while (!element.isNull())
//        {
//            if (element.tagName() == "instrument")
//                _InstrumentVersion = element.attribute("type", "");

//            element = element.nextSibling().toElement();
//        }

//        if (_InstrumentVersion.isEmpty())
//        {
//            logger::Error("Configuration:: Error Version is empty!");
//            throw ConfigurationException(_InstrumentVersion.toStdString());
//        }
//        logger::Info("Instrument version = %s", _InstrumentVersion.toStdString());
//        logger::Info("Configuration <<");
//    }
//    catch (ConfigurationException &cException)
//    {
//       logger::Info("Configuration Parameter = %s is missing!", cException.GetError());
//    }
//}
//}   // namespace instrument




