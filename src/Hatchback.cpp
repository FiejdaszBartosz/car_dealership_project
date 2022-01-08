#include "../include/Hatchback.h"

Hatchback::Hatchback() {
  aName = "not set";
  aType = "hatchback";
  aProductionYear = 0;
}

Hatchback::Hatchback(std::string &rName,
					 int &rProductionYear,
					 int &rVehicleLength,
					 std::vector<engineProperties> &rEngine,
					 std::vector<accessories> &rInterior,
					 std::vector<accessories> &rColor,
					 std::vector<accessories> &rWheels,
					 std::vector<accessories> &rAdditionalEquipment) {
  aName = rName;
  aType = "hatchback";
  aProductionYear = rProductionYear;
  aVehicleLength = rVehicleLength;
  aEngine = rEngine;
  aInterior = rInterior;
  aColor = rColor;
  aWheels = rWheels;
  aAdditionalEquipment = rAdditionalEquipment;
}

Hatchback::~Hatchback() {}

void Hatchback::saveToFile() const {
  std::ofstream output("database.csv", std::ios::app);
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
  output.close();
}
