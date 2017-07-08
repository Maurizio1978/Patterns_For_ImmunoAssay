#include "Factory/mago4factory.h"
#include "boost/shared_ptr.hpp"

DilutionRackSP Mago4Factory::createDilutionRack()
{
    return boost::shared_ptr<DilutionRack>(new Mago4DilutionRack);
}

SampleRackSP Mago4Factory::createSampleRack()
{
    return boost::shared_ptr<SampleRack>(new Mago4SampleRack);
}

WellRackSP Mago4Factory::createWellRack()
{
    return boost::shared_ptr<WellRack>(new Mago4WellRack);
}
