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

void SportVehicle::saveToFile(const std::string fileName) const {
  std::ofstream output;
  output.open(fileName, std::ios::app);
  output << aType << "," << aName << "," << aProductionYear << "," << aVehicleLength << "\n";
  for (auto i = aEngine.begin(); i != aEngine.end(); ++i) {
	output << i->hp << "," << i->nm << "," << i->fuelType << "," << i->enginePrice;
	if (i != (aEngine.end() - 1))
	  output << ",";
  }
  output << "\n";
  for (auto i = aInterior.begin(); i != aInterior.end(); i++) {
	output << i->accessoriesName << "," << i->accessoriesPrice;
	if (i != (aInterior.end() - 1))
	  output << ",";
  }
  output << "\n";
  for (auto i = aColor.begin(); i != aColor.end(); i++) {
	output << i->accessoriesName << "," << i->accessoriesPrice;
	if (i != (aColor.end() - 1))
	  output << ",";
  }
  output << "\n";
  for (auto i = aWheels.begin(); i != aWheels.end(); i++) {
	output << i->accessoriesName << "," << i->accessoriesPrice;
	if (i != (aWheels.end() - 1))
	  output << ",";
  }
  output << "\n";
  for (auto i = aAdditionalEquipment.begin(); i != aAdditionalEquipment.end(); i++) {
	output << i->accessoriesName << "," << i->accessoriesPrice;
	if (i != (aAdditionalEquipment.end() - 1))
	  output << ",";
  }
  output << "\n";
  for (auto i = aEnginePackage.begin(); i != aEnginePackage.end(); i++) {
	output << i->hp << "," << i->nm << "," << i->fuelType << "," << i->enginePrice;
	if (i != (aEnginePackage.end() - 1))
	  output << ",";
  }
  output << "\n";
  output.close();
}

std::string SportVehicle::showInformation() const{
  std::string information;
  information = "Name: " + getName() + "\n";
  information = information + "Typ: " + getType() + "\n";
  information = information + "Length: " + std::to_string(getVehicleLength()) + "\n";
  information = information + "Production Year: " + std::to_string(getProductionYear()) + "\n";

  auto tempEngine = getEngine();
  for(auto i = tempEngine.begin(); i != tempEngine.end(); i++){
    information = information + "HP: " + std::to_string(i->hp) + " Nm: " + std::to_string(i->hp)
            + " Petrol: " + i->fuelType + " Price: " + std::to_string(i->enginePrice) + "\n";
  }

  auto tempInterior = getInterior();
  for(auto i = tempInterior.begin(); i != tempInterior.end(); i++){
    information = information + "Interior trim: " + i->accessoriesName + " Price: "
            + std::to_string(i->accessoriesPrice) + "\n";
  }

  auto tempColor = getColor();
  for(auto i = tempColor.begin(); i != tempColor.end(); i++){
    information = information + "Color: " + i->accessoriesName + " Price: "
            + std::to_string(i->accessoriesPrice) + "\n";
  }

  auto tempWheels = getWheels();
  for(auto i = tempWheels.begin(); i != tempWheels.end(); i++){
    information = information + "Wheels size: " + i->accessoriesName + " Price: "
            + std::to_string(i->accessoriesPrice) + "\n";
  }

  information += "Additional Equipment:\n";
  auto tempAdditionalEquipment = getAdditionalEquipment();
  for(auto i = tempAdditionalEquipment.begin(); i != tempAdditionalEquipment.end(); i++){
    information = information + i->accessoriesName + " Price: "
            + std::to_string(i->accessoriesPrice) + "\n";
  }

  information += "Engine Package:\n";
  auto tempPackage = getEnginePackage();
  for(auto i = tempPackage.begin(); i != tempPackage.end(); i++){
    information = information + "HP: " + std::to_string(i->hp) + " Nm: " + std::to_string(i->hp)
            + " Petrol: " + i->fuelType + " Price: " + std::to_string(i->enginePrice) + "\n";
  }

  return information;
}
