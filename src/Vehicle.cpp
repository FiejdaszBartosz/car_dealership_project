#include "../include/Vehicle.h"

struct engineProperties &engineProperties::operator+=(const engineProperties &rhs) {
  hp += rhs.hp;
  nm += rhs.nm;
  return *this;
}

engineProperties operator+(engineProperties lhs, const engineProperties &rhs) {
  return lhs += rhs;
}

//creates engine struct from input and returns it by reference
void Vehicle::createEngine(const int &rHp,
						   const int &rNm,
						   const std::string &rFuelType,
						   const int &rEnginePrice,
						   engineProperties &rEngine) {
  engineProperties tempEngine;
  tempEngine.hp = rHp;
  tempEngine.nm = rNm;
  tempEngine.fuelType = rFuelType;
  tempEngine.enginePrice = rEnginePrice;
  rEngine = tempEngine;
}

//creates accessories struct from input and returns it by reference
void Vehicle::createAccessories(const std::string &rAccessoriesName,
								const int &rAccessoriesPrice,
								accessories &rAccessories) {
  accessories tempAccessories;
  tempAccessories.accessoriesName = rAccessoriesName;
  tempAccessories.accessoriesPrice = rAccessoriesPrice;
  rAccessories = tempAccessories;
}

//setting by default values
Vehicle::Vehicle() :
	aName("Not set"),
	aType("Not set"),
	aProductionYear(0),
	aVehicleLength(0) {}

//setting by declared value
Vehicle::Vehicle(std::string &rName,
				 std::string &rType,
				 int &rProductionYear,
				 int &rVehicleLength,
				 std::vector<engineProperties> &rEngine,
				 std::vector<accessories> &rInterior,
				 std::vector<accessories> &rColor,
				 std::vector<accessories> &rWheels,
				 std::vector<accessories> &rAdditionalEquipment) :
	aName(rName),
	aType(rType),
	aProductionYear(rProductionYear),
	aVehicleLength(rVehicleLength),
	aEngine(rEngine),
	aInterior(rInterior),
	aColor(rColor),
	aWheels(rWheels),
	aAdditionalEquipment(rAdditionalEquipment) {}

Vehicle::~Vehicle() {}

std::string Vehicle::getName() const {
  return aName;
}

std::string Vehicle::getType() const {
  return aType;
}

int Vehicle::getProductionYear() const {
  return aProductionYear;
}

int Vehicle::getVehicleLength() const {
  return aVehicleLength;
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

void Vehicle::setName(const std::string name) {
  this->aName = name;
}

void Vehicle::setType(const std::string type) {
  this->aType = type;
}

void Vehicle::setProductionYear(const int productionYear) {
  this->aProductionYear = productionYear;
}

void Vehicle::setVehicleLength(const int vehicleLength) {
  this->aVehicleLength = vehicleLength;
}

void Vehicle::addVehicleLength(const int additionaLenght) {
  int temp = getVehicleLength();
  temp += additionaLenght;
  setVehicleLength(temp);
}

//engine functions section
void Vehicle::setEngine(const std::vector<engineProperties> &rEngineVector) {
  this->aEngine = rEngineVector;
}

void Vehicle::setEngine(const engineProperties &rEngineStruct) {
  this->aEngine.push_back(rEngineStruct);
}

//adds new enging at the end of the aEngine
void Vehicle::addEngine(const int &rHp,
						const int &rNm,
						const std::string &rFuelType,
						const int &rEnginePrice) {
  engineProperties temp;
  createEngine(rHp, rNm, rFuelType, rEnginePrice, temp);
  setEngine(temp);
}

//removes all matching engines
void Vehicle::removeEngine(const int &rHp,
						   const int &rNm,
						   const std::string &rFuelType,
						   const int &rEnginePrice) {
  auto temp = getEngine();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->hp == rHp &&
		i->nm == rNm &&
		i->fuelType == rFuelType &&
		i->enginePrice == rEnginePrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  setEngine(temp);
}

//modifies the engine with the given values
void Vehicle::changeEngineProperties(const int &rHp,
									 const int &rNm,
									 const std::string &rFuelType,
									 const int &rEnginePrice,
									 const int &rNewHp,
									 const int &rNewNm,
									 const std::string &rNewFuelType,
									 const int &rNewEnginePrice) {
  auto temp = getEngine();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->hp == rHp &&
		i->nm == rNm &&
		i->fuelType == rFuelType &&
		i->enginePrice == rEnginePrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  engineProperties tempEngine;
  createEngine(rNewHp, rNewNm, rNewFuelType, rNewEnginePrice, tempEngine);
  temp.push_back(tempEngine);
  setEngine(temp);
}

void Vehicle::setInterior(const std::vector<accessories> &rInteriorVector) {
  this->aInterior = rInteriorVector;
}

void Vehicle::setInterior(const accessories &rInteriorStruct) {
  this->aInterior.push_back(rInteriorStruct);
}

//Adds interior with the given values
void Vehicle::addInterior(const std::string &rAccessoriesName,
						  const int &rAccessoriesPrice) {
  accessories temp;
  createAccessories(rAccessoriesName, rAccessoriesPrice, temp);
  setInterior(temp);
}

//Remove interior with the given values
void Vehicle::removeInterior(const std::string &rAccessoriesName,
							 const int &rAccessoriesPrice) {
  auto temp = getInterior();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == rAccessoriesName &&
		i->accessoriesPrice == rAccessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  setInterior(temp);
}

//Change interior with the given values
void Vehicle::changeInteriorProperties(const std::string &rAccessoriesName,
									   const int &rAccessoriesPrice,
									   const std::string &rNewAccessoriesName,
									   const int &rNewAccessoriesPrice) {
  auto temp = getInterior();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == rAccessoriesName &&
		i->accessoriesPrice == rAccessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  accessories tempAccessories;
  createAccessories(rNewAccessoriesName, rNewAccessoriesPrice, tempAccessories);
  temp.push_back(tempAccessories);
  setInterior(temp);
}

/** Functions for color, wheels and additionalEquipment are similar to
 * interior functions.
 */
void Vehicle::setColor(const std::vector<accessories> &rColorVector) {
  this->aColor = rColorVector;
}

void Vehicle::setColor(const accessories &rColorStruct) {
  this->aColor.push_back(rColorStruct);
}

void Vehicle::addColor(const std::string &rAccessoriesName,
					   const int &rAccessoriesPrice) {
  accessories temp;
  createAccessories(rAccessoriesName, rAccessoriesPrice, temp);
  setColor(temp);
}

void Vehicle::removeColor(const std::string &rAccessoriesName,
						  const int &rAccessoriesPrice) {
  auto temp = getColor();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == rAccessoriesName &&
		i->accessoriesPrice == rAccessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  setColor(temp);
}

void Vehicle::changeColorProperties(const std::string &rAccessoriesName,
									const int &rAccessoriesPrice,
									const std::string &rNewAccessoriesName,
									const int &rNewAccessoriesPrice) {
  auto temp = getColor();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == rAccessoriesName &&
		i->accessoriesPrice == rAccessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  accessories tempAccessories;
  createAccessories(rNewAccessoriesName, rNewAccessoriesPrice, tempAccessories);
  temp.push_back(tempAccessories);
  setColor(temp);
}

void Vehicle::setWheels(const std::vector<accessories> &rWheelsVector) {
  this->aWheels = rWheelsVector;
}

void Vehicle::setWheels(const accessories &rWheelsStruct) {
  this->aWheels.push_back(rWheelsStruct);
}

void Vehicle::addWheels(const std::string &rAccessoriesName,
						const int &rAccessoriesPrice) {
  accessories temp;
  createAccessories(rAccessoriesName, rAccessoriesPrice, temp);
  setWheels(temp);
}

void Vehicle::removeWheels(const std::string &rAccessoriesName,
						   const int &rAccessoriesPrice) {
  auto temp = getWheels();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == rAccessoriesName &&
		i->accessoriesPrice == rAccessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  setWheels(temp);
}

void Vehicle::changeWheelsProperties(const std::string &rAccessoriesName,
									 const int &rAccessoriesPrice,
									 const std::string &rNewAccessoriesName,
									 const int &rNewAccessoriesPrice) {
  auto temp = getWheels();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == rAccessoriesName &&
		i->accessoriesPrice == rAccessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  accessories tempAccessories;
  createAccessories(rNewAccessoriesName, rNewAccessoriesPrice, tempAccessories);
  temp.push_back(tempAccessories);
  setWheels(temp);
}

void Vehicle::setAdditionalEquipment(const std::vector<accessories> &rAdditionalEquipmentVector) {
  this->aAdditionalEquipment = rAdditionalEquipmentVector;
}

void Vehicle::setAdditionalEquipment(const accessories &rAdditionalEquipmentStruct) {
  this->aAdditionalEquipment.push_back(rAdditionalEquipmentStruct);
}

void Vehicle::addAdditionalEquipment(const std::string &rAccessoriesName,
									 const int &rAccessoriesPrice) {
  accessories temp;
  createAccessories(rAccessoriesName, rAccessoriesPrice, temp);
  setAdditionalEquipment(temp);
}

void Vehicle::removeAdditionalEquipment(const std::string &rAccessoriesName,
										const int &rAccessoriesPrice) {
  auto temp = getAdditionalEquipment();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == rAccessoriesName &&
		i->accessoriesPrice == rAccessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  setAdditionalEquipment(temp);
}

void Vehicle::changeAdditionalEquipmentProperties(const std::string &rAccessoriesName,
												  const int &rAccessoriesPrice,
												  const std::string &rNewAccessoriesName,
												  const int &rNewAccessoriesPrice) {
  auto temp = getWheels();
  for (auto i = temp.begin(); i != temp.end(); i++) {
	if (i->accessoriesName == rAccessoriesName &&
		i->accessoriesPrice == rAccessoriesPrice) {
	  i = temp.erase(i);
	} else {
	  ++i;
	}
  }
  accessories tempAccessories;
  createAccessories(rNewAccessoriesName, rNewAccessoriesPrice, tempAccessories);
  temp.push_back(tempAccessories);
  setAdditionalEquipment(temp);
}
