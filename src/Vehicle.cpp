#include "Vehicle.h"

//seting default values
Vehicle::Vehicle() :
    aName("Not set"),
    aType("Not set"),
    aProductionYear(0),
    apUsage(nullptr)
{
    engineProperties engine;
    equipmentOptions equipment;
    engine.hp = 0;
    engine.nm = 0;
    engine.fuelType = "Not set";
    equipment.interior = "Not set";
}

Vehicle::~Vehicle(){
    delete apUsage;
}
