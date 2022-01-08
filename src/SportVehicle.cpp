#include "SportVehicle.h"

SportVehicle::SportVehicle() {
  aName = "not set";
  aType = "sportVehicle";
  aProductionYear = 0;
}

SportVehicle::SportVehicle(std::string &rName,
						   int &rProductionYear,
						   int &rVehicleLength,
						   std::vector<engineProperties> &rEngine,
						   std::vector<accessories> &rInterior,
						   std::vector<accessories> &rColor,
						   std::vector<accessories> &rWheels,
						   std::vector<accessories> &rAdditionalEquipment,
						   std::vector<engineProperties> &rEnginePackage) {
  aName = rName;
  aType = "sport vehicle";
  aProductionYear = rProductionYear;
  aVehicleLength = rVehicleLength;
  aEngine = rEngine;
  aInterior = rInterior;
  aColor = rColor;
  aWheels = rWheels;
  aAdditionalEquipment = rAdditionalEquipment;
  aEnginePackage = rEnginePackage;
}

SportVehicle::~SportVehicle() {

}

std::vector<engineProperties> SportVehicle::getEnginePackage() const {
  return aEnginePackage;
}

void SportVehicle::setEnginePackage(const std::vector<engineProperties> &rEnginePackageVector) {
  this->aEnginePackage = rEnginePackageVector;
}

void SportVehicle::setEnginePackage(const engineProperties &rEnginePackageStruct) {
  this->aEnginePackage.push_back(rEnginePackageStruct);
}

void SportVehicle::addEnginePackage(const int &rHp,
									const int &rNm,
									const std::string &rFuelType,
									const int &rEnginePrice) {
  engineProperties temp;
  createEngine(rHp, rNm, rFuelType, rEnginePrice, temp);
  setEnginePackage(temp);
}

void SportVehicle::removeEnginePackage(const int &rHp,
									   const int &rNm,
									   const std::string &rFuelType,
									   const int &rEnginePrice) {
  auto temp = getEnginePackage();
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
  setEnginePackage(temp);
}

void SportVehicle::changeEnginePackageProperties(const int &rHp,
												 const int &rNm,
												 const std::string &rFuelType,
												 const int &rEnginePrice) {
  auto temp = getEnginePackage();
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
  engineProperties tempEnginePackage;
  createEngine(rHp, rNm, rFuelType, rEnginePrice, tempEnginePackage);
  temp.push_back(tempEnginePackage);
  setEnginePackage(temp);
}

void SportVehicle::upgradeEngine(int position) {
  std::vector<engineProperties> temp = getEngine();
  engineProperties tempEnginePackage = getEnginePackage().at(position);
  for (auto &var : temp)
	var += tempEnginePackage;
  setEngine(temp);
}

void SportVehicle::saveToFile() const {
  std::ofstream output;
  output.open("database.csv", std::ios::app);
  output << aType << "," << aName << "," << aProductionYear << "," << aVehicleLength << "\n";
  for (auto i = aEngine.begin(); i != aEngine.end(); i++)
	output << i->hp << "," << i->nm << "," << i->fuelType << "," << i->enginePrice;
  output << "\n";
  for (auto i = aInterior.begin(); i != aInterior.end(); i++)
	output << i->accessoriesName << "," << i->accessoriesPrice;
  output << "\n";
  for (auto i = aColor.begin(); i != aColor.end(); i++)
	output << i->accessoriesName << "," << i->accessoriesPrice;
  output << "\n";
  for (auto i = aWheels.begin(); i != aWheels.end(); i++)
	output << i->accessoriesName << "," << i->accessoriesPrice;
  output << "\n";
  for (auto i = aAdditionalEquipment.begin(); i != aAdditionalEquipment.end(); i++)
	output << i->accessoriesName << "," << i->accessoriesPrice;
  output << "\n";
  for (auto i = aEnginePackage.begin(); i != aEnginePackage.end(); i++)
	output << i->hp << "," << i->nm << "," << i->fuelType << "," << i->enginePrice;
  output << "\n";
  output.close();
}
