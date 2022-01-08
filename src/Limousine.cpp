#include "Limousine.h"

Limousine::Limousine() {
  aName = "not set";
  aType = "limousine";
  aProductionYear = 0;
  aIsLong = false;

}

Limousine::Limousine(std::string &rName,
					 int &rProductionYear,
					 int &rVehicleLength,
					 std::vector<engineProperties> &rEngine,
					 std::vector<accessories> &rInterior,
					 std::vector<accessories> &rColor,
					 std::vector<accessories> &rWheels,
					 std::vector<accessories> &rAdditionalEquipment) {
  aName = rName;
  aType = "limousine";
  aProductionYear = rProductionYear;
  aVehicleLength = rVehicleLength;
  aEngine = rEngine;
  aInterior = rInterior;
  aColor = rColor;
  aWheels = rWheels;
  aAdditionalEquipment = rAdditionalEquipment;
  aIsLong = false;
}

Limousine::~Limousine() {}

void Limousine::addLongVersion() {
  aIsLong = true;
  setType("long limousine");
  addVehicleLength(20);
}

void Limousine::saveToFile() const {
  std::ofstream output("database.csv", std::ios::app);
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
  output << aIsLong;
  output << "\n";
  output.close();
}
