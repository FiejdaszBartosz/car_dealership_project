#include "Vehicle.h"

//setting by default values
Vehicle::Vehicle() :
    aName("Not set"),
    aType("Not set"),
    aProductionYear(0),
    aTotalPrice(0) {}

//setting by declared value
Vehicle::Vehicle(std::string name,
                 std::string type,
                 int productionYear,
                 std::vector <engineProperties> engine,
                 std::vector <accessories> interior,
                 std::vector <accessories> color,
                 std::vector <accessories> wheels,
                 std::vector <accessories> additionalEquipment) :
    aName(name),
    aType(type),
    aProductionYear(productionYear),
    aEngine(engine),
    aInterior(interior),
    aColor(color),
    aWheels(wheels),
    aAdditionalEquipment(additionalEquipment) {}

std::string Vehicle::getName() const{
    return aName;
}

std::string Vehicle::getType() const{
    return aType;
}

int Vehicle::getProductionYear() const{
    return aProductionYear;
}

void Vehicle::setName(const std::string name){
    this->aName = name;
}

void Vehicle::setType(const std::string type){
    this->aType = type;
}

void Vehicle::setProductionYear(const int productionYear){
    this->aProductionYear = productionYear;
}

void Vehicle::setEngine(const std::vector<engineProperties> engineVector){
    this->aEngine = engineVector;
}

void Vehicle::setEngine(const engineProperties engineStruct){
    this->aEngine.push_back(engineStruct);
}

void setAccessories(const std::vector <accessories> accessoriesVector){
    //to do
}

void setAccessories(const accessories accessoriesStruct){
    //to do
}
