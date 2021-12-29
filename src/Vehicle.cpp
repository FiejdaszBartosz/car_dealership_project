#include "../include/Vehicle.h"

//creates engine struct from input and returns it by reference
void Vehicle::createEngine(const int hp,
						   const int nm,
						   const std::string fuelType,
						   const int enginePrice,
						   engineProperties &rEngine) {
  engineProperties tempEngine;
  tempEngine.hp = hp;
  tempEngine.nm = nm;
  tempEngine.fuelType = fuelType;
  tempEngine.enginePrice = enginePrice;
  rEngine = tempEngine;
}

//creates accessories struct from input and returns it by reference
void Vehicle::createAccessories(const std::string accessoriesName,
								const int accessoriesPrice,
								accessories &rAccessories) {
  accessories tempAccessories;
  tempAccessories.accessoriesName = accessoriesName;
  tempAccessories.accessoriesPrice = accessoriesPrice;
  rAccessories = tempAccessories;
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

std::vector<accessories> Vehicle::getInterior() const {
  return aInterior;
}

std::vector<accessories> Vehicle::getColor() const {
  return aColor;
}

std::vector<accessories> Vehicle::getWheels() const {
  return aWheels;
}

std::vector<accessories> Vehicle::getAdditionalEquipment() const {
  return aAdditionalEquipment;
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

void Vehicle::setInterior(const std::vector<accessories> &rInteriorVector) {
  this->aInterior = rInteriorVector;
}

void Vehicle::setInterior(const accessories &rInteriorStruct) {
  this->aInterior.push_back(rInteriorStruct);
}

void Vehicle::addInterior(const std::string accessoriesName,
						  const int accessoriesPrice) {
  accessories temp;
  createAccessories(accessoriesName, accessoriesPrice, temp);
  setInterior(temp);
}

void Vehicle::removeInterior(const std::string accessoriesName,
							 const int accessoriesPrice) {
  auto temp = getInterior();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == accessoriesName &&
		i->accessoriesPrice == accessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  setInterior(temp);
}

void Vehicle::changeInteriorProperties(const std::string accessoriesName,
									   const int accessoriesPrice) {
  auto temp = getInterior();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == accessoriesName &&
		i->accessoriesPrice == accessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  accessories tempAccessories;
  createAccessories(accessoriesName, accessoriesPrice, tempAccessories);
  temp.push_back(tempAccessories);
  setInterior(temp);
}

void Vehicle::setColor(const std::vector<accessories> &rColorVector) {
  this->aColor = rColorVector;
}

void Vehicle::setColor(const accessories &rColorStruct) {
  this->aColor.push_back(rColorStruct);
}

void Vehicle::addColor(const std::string accessoriesName,
					   const int accessoriesPrice) {
  accessories temp;
  createAccessories(accessoriesName, accessoriesPrice, temp);
  setColor(temp);
}

void Vehicle::removeColor(const std::string accessoriesName,
						  const int accessoriesPrice) {
  auto temp = getColor();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == accessoriesName &&
		i->accessoriesPrice == accessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  setColor(temp);
}

void Vehicle::changeColorProperties(const std::string accessoriesName,
									const int accessoriesPrice) {
  auto temp = getColor();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == accessoriesName &&
		i->accessoriesPrice == accessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  accessories tempAccessories;
  createAccessories(accessoriesName, accessoriesPrice, tempAccessories);
  temp.push_back(tempAccessories);
  setColor(temp);
}

void Vehicle::setWheels(const std::vector<accessories> &rWheelsVector) {
  this->aWheels = rWheelsVector;
}

void Vehicle::setWheels(const accessories &rWheelsStruct) {
  this->aWheels.push_back(rWheelsStruct);
}

void Vehicle::addWheels(const std::string accessoriesName,
						const int accessoriesPrice) {
  accessories temp;
  createAccessories(accessoriesName, accessoriesPrice, temp);
  setWheels(temp);
}

void Vehicle::removeWheels(const std::string accessoriesName,
						   const int accessoriesPrice) {
  auto temp = getWheels();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == accessoriesName &&
		i->accessoriesPrice == accessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  setWheels(temp);
}

void Vehicle::changeWheelsProperties(const std::string accessoriesName,
									 const int accessoriesPrice) {
  auto temp = getWheels();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == accessoriesName &&
		i->accessoriesPrice == accessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  accessories tempAccessories;
  createAccessories(accessoriesName, accessoriesPrice, tempAccessories);
  temp.push_back(tempAccessories);
  setWheels(temp);
}

void Vehicle::setAdditionalEquipment(const std::vector<accessories> &rAdditionalEquipmentVector) {
  this->aAdditionalEquipment = rAdditionalEquipmentVector;
}

void Vehicle::setAdditionalEquipment(const accessories &rAdditionalEquipmentStruct) {
  this->aAdditionalEquipment.push_back(rAdditionalEquipmentStruct);
}

void Vehicle::addAdditionalEquipment(const std::string accessoriesName,
									 const int accessoriesPrice) {
  accessories temp;
  createAccessories(accessoriesName, accessoriesPrice, temp);
  setAdditionalEquipment(temp);
}

void Vehicle::removeAdditionalEquipment(const std::string accessoriesName,
										const int accessoriesPrice) {
  auto temp = getAdditionalEquipment();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == accessoriesName &&
		i->accessoriesPrice == accessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  setAdditionalEquipment(temp);
}

void Vehicle::changeAdditionalEquipmentProperties(const std::string accessoriesName,
												  const int accessoriesPrice) {
  auto temp = getWheels();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == accessoriesName &&
		i->accessoriesPrice == accessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  accessories tempAccessories;
  createAccessories(accessoriesName, accessoriesPrice, tempAccessories);
  temp.push_back(tempAccessories);
  setAdditionalEquipment(temp);
}
