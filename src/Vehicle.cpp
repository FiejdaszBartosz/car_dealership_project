#include "../include/Vehicle.h"

//creates engine struct from input and return this by reference
void Vehicle::createEngine(const int hpTemp,
						   const int nmTemp,
						   const std::string fuelTypeTemp,
						   const int enginePriceTemp,
						   engineProperties rEngine) {
  engineProperties temp;
  temp.hp = hpTemp;
  temp.nm = nmTemp;
  temp.fuelType = fuelTypeTemp;
  temp.enginePrice = enginePriceTemp;
  rEngine = temp;
}

//setting by default values
Vehicle::Vehicle() :
	aName("Not set"),
	aType("Not set"),
	aProductionYear(0) {}

//setting by declared value
Vehicle::Vehicle(std::string name,
				 std::string type,
				 int productionYear,
				 std::vector<engineProperties> engine,
				 std::vector<accessories> interior,
				 std::vector<accessories> color,
				 std::vector<accessories> wheels,
				 std::vector<accessories> additionalEquipment) :
	aName(name),
	aType(type),
	aProductionYear(productionYear),
	aEngine(engine),
	aInterior(interior),
	aColor(color),
	aWheels(wheels),
	aAdditionalEquipment(additionalEquipment) {}

std::string Vehicle::getName() const {
  return aName;
}

std::string Vehicle::getType() const {
  return aType;
}

int Vehicle::getProductionYear() const {
  return aProductionYear;
}

std::vector<engineProperties> Vehicle::getEngine() const {
  return aEngine;
}

void Vehicle::setName(const std::string &rName) {
  this->aName = rName;
}

void Vehicle::setType(const std::string &rType) {
  this->aType = rType;
}

void Vehicle::setProductionYear(const int &rProductionYear) {
  this->aProductionYear = rProductionYear;
}

//engine functions section
void Vehicle::setEngine(const std::vector<engineProperties> &rEngineVector) {
  this->aEngine = rEngineVector;
}

void Vehicle::setEngine(const engineProperties &rEngineStruct) {
  this->aEngine.push_back(rEngineStruct);
}

//adds new enging at the end of the aEngine
void Vehicle::addEngine(const int hp,
						const int nm,
						const std::string fuelType,
						const int enginePrice) {
  engineProperties temp;
  createEngine(hp, nm, fuelType, enginePrice, temp);
  setEngine(temp);
}

//removes all matching engines
void Vehicle::removeEngine(const int hp,
						   const int nm,
						   const std::string fuelType,
						   const int enginePrice) {
  auto temp = getEngine();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->hp == hp &&
		i->nm == nm &&
		i->fuelType == fuelType &&
		i->enginePrice == enginePrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  setEngine(temp);
}

//modifies the engine with the given values
void Vehicle::changeEngineProperties(const int hp,
									 const int nm,
									 const std::string fuelType,
									 const int enginePrice) {
  auto temp = getEngine();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->hp == hp &&
		i->nm == nm &&
		i->fuelType == fuelType &&
		i->enginePrice == enginePrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  engineProperties tempEngine;
  createEngine(hp, nm, fuelType, enginePrice, tempEngine);
  temp.push_back(tempEngine);
  setEngine(temp);
}

void Vehicle::setInterior(const accessories &rInterior) {
  this->aInterior.push_back(rInterior);
}

void Vehicle::setColor(const accessories &rColor) {
  this->aColor.push_back(rColor);
}

void Vehicle::setWheels(const accessories &rWheels) {
  this->aColor.push_back(rWheels);
}

void Vehicle::setAdditionalEquipment(const accessories &rAdditionalEquipment) {
  this->aAdditionalEquipment.push_back(rAdditionalEquipment);
}
