#include "Vehicle.h"

//setting by default values
Vehicle::Vehicle() :
    aName("Not set"),
    aType("Not set"),
    aProductionYear(0),
    apUsage(nullptr)
{
    aEngine.hp = 0;
    aEngine.nm = 0;
    aEngine.fuelType = "Not set";
    aEngine.fuelType = "Not set";
    aEquipment.interior = "Not set";
}

//setting by declared value
Vehicle::Vehicle(std::string name,
        std::string type,
        int productionYear,
        engineProperties engine,
        equipmentOptions equipment,
        std::string *pUsage) :
    aName(name),
    aType(type),
    aProductionYear(productionYear),
    aEngine(engine),
    aEquipment(equipment),
    apUsage(pUsage) {
    //aEngine.fuelType = engine.fuelType;
}

Vehicle::~Vehicle(){
    delete apUsage;
}

std::string Vehicle::getName() const{
    return aName;
}

std::string Vehicle::getType() const{
    return aType;
}

int Vehicle::getProductionYear() const{
    return aProductionYear;
}
