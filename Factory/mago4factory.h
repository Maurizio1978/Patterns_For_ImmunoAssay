#ifndef MAGO4FACTORY
#define MAGO4FACTORY

#include "factory.h"

//#include "Instrument/DilutionRack/dilutionrack.h"
//#include "Instrument/SampleRack/samplerack.h"
//#include "Instrument/WellRack/wellrack.h"

#include "Mago4/Mago4DilutionRack/mago4dilutionrack.h"
#include "Mago4/Mago4SampleRack/mago4samplerack.h"
#include "Mago4/Mago4WellRack/mago4wellrack.h"

#include "boost/shared_ptr.hpp"

class Mago4Factory : public Factory
{
  public:
    virtual DilutionRackSP createDilutionRack();

    virtual SampleRackSP createSampleRack();

    virtual WellRackSP createWellRack();
};

#endif // MAGO4FACTORY

