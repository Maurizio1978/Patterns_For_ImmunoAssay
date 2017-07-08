#ifndef MAGO4SFACTORY
#define MAGO4SFACTORY

#include "factory.h"

#include "Mago4s/Mago4sDilutionRack/mago4sdilutionrack.h"
#include "Mago4s/Mago4sSampleRack/mago4ssamplerack.h"
#include "Mago4s/Mago4sWellRack/mago4swellrack.h"

#include "boost/shared_ptr.hpp"

class Mago4sFactory : public Factory {
  public:

    virtual DilutionRackSP createDilutionRack();

    virtual SampleRackSP createSampleRack();

    virtual WellRackSP createWellRack();

};

#endif // MAGO4SFACTORY

