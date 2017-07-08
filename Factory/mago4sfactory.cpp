#include "Factory/mago4sfactory.h"
#include "boost/shared_ptr.hpp"

DilutionRackSP Mago4sFactory::createDilutionRack()
{
    return boost::shared_ptr<DilutionRack>(new Mago4sDilutionRack);
}

SampleRackSP Mago4sFactory::createSampleRack()
{
    return boost::shared_ptr<SampleRack>(new Mago4sSampleRack);
}

WellRackSP Mago4sFactory::createWellRack()
{
    return boost::shared_ptr<WellRack>(new Mago4sWellRack);
}
