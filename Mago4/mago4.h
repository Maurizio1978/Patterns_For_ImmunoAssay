#ifndef MAGO4_H
#define MAGO4_H

#include "Instrument/instrument.h"
#include "Mago4DilutionRack/mago4dilutionrack.h"
#include "Mago4SampleRack/mago4samplerack.h"
#include "Mago4WellRack/mago4wellrack.h"


class Mago4 : public Instrument
{
public:
    Mago4();
    ~Mago4();

private:
    Mago4DilutionRack _Mago4DilutionRack;
    Mago4SampleRack _Mago4SampleRack;
    Mago4WellRack _Mago4WellRack;

}; // class mago4

#endif // MAGO4_H
