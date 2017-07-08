#ifndef FACTORY_H
#define FACTORY_H

#include "Instrument/instrument.h"

typedef boost::shared_ptr<DilutionRack> DilutionRackSP;
typedef boost::shared_ptr<SampleRack> SampleRackSP;
typedef boost::shared_ptr<WellRack> WellRackSP;

class Factory
{
public:
    virtual DilutionRackSP createDilutionRack() = 0;
    virtual SampleRackSP createSampleRack() = 0;
    virtual WellRackSP createWellRack() = 0;
};

#endif  // FACTORY_H
