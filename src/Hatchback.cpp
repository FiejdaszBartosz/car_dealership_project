#include "../include/Hatchback.h"

/**
  * @brief constructor - create Hatchback with default value
*/
Hatchback::Hatchback() {
  aName = "not set";
  aType = "hatchback";
  aProductionYear = 0;
}

/**
  * @brief constructor - create Hatchback with given values
  * @param rName - hatchback name - reference
  * @param rProductionYear - production year - reference
  * @param rEngine - vector of engine struct - reference
  * @param rInterior - vector of accessories for interior - reference
  * @param rColor - vector of accessories for color - reference
  * @param rWheels - vector of accessories for wheels - reference
  * @param rAdditionalEquipment - vector of accessories for additional equipment - reference
*/
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

/**
  * @brief destructor
  */
Hatchback::~Hatchback() {}

/**
  * @brief virtual function for saving to file
  * @param fileName - name of the file where you want to save
*/
void Hatchback::saveToFile(const std::string fileName) const {
  std::ofstream output(fileName, std::ios::app);
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
  output.close();
}

/**
  * @brief function that creates information about limousine and saves that to string
  * @returns created information
*/
std::string Hatchback::showInformation() const {
  std::string information;
  information = "Name: " + getName() + "\n";
  information = information + "Typ: " + getType() + "\n";
  information = information + "Length: " + std::to_string(getVehicleLength()) + "\n";
  information = information + "Production Year: " + std::to_string(getProductionYear()) + "\n";

  auto tempEngine = getEngine();
  for (auto i = tempEngine.begin(); i != tempEngine.end(); i++) {
	information = information + "HP: " + std::to_string(i->hp) + " Nm: " + std::to_string(i->hp)
		+ " Petrol: " + i->fuelType + " Price: " + std::to_string(i->enginePrice) + "\n";
  }

  auto tempInterior = getInterior();
  for (auto i = tempInterior.begin(); i != tempInterior.end(); i++) {
	information = information + "Interior trim: " + i->accessoriesName + " Price: "
		+ std::to_string(i->accessoriesPrice) + "\n";
  }

  auto tempColor = getColor();
  for (auto i = tempColor.begin(); i != tempColor.end(); i++) {
	information = information + "Color: " + i->accessoriesName + " Price: "
		+ std::to_string(i->accessoriesPrice) + "\n";
  }

  auto tempWheels = getWheels();
  for (auto i = tempWheels.begin(); i != tempWheels.end(); i++) {
	information = information + "Wheels size: " + i->accessoriesName + " Price: "
		+ std::to_string(i->accessoriesPrice) + "\n";
  }

  information += "Additional Equipment:\n";
  auto tempAdditionalEquipment = getAdditionalEquipment();
  for (auto i = tempAdditionalEquipment.begin(); i != tempAdditionalEquipment.end(); i++) {
	information = information + i->accessoriesName + " Price: "
		+ std::to_string(i->accessoriesPrice) + "\n";
  }

  return information;
}

/**
 * @brief based on virtual function, shows package details
 * @param position - package position
 * @returns error in hatchback case
 */
std::string Hatchback::showPackage(int position) const {
  return "error";
}

/**
 * @brief based on virtual function, gets vector of engine properties
 * @returns in hatchback case empty engine properties vector
 */
std::vector<engineProperties> Hatchback::getEnginePackage() const {
  std::vector<engineProperties> temp;
  return temp;
}

/**
 * @brief based on virtual function, doing nothing in hatchback case
 */
void Hatchback::setEnginePackage(const std::vector<engineProperties> &rEnginePackageVector) {}

/**
 * @brief based on virtual function, doing nothing in hatchback case
 */
void Hatchback::setEnginePackage(const engineProperties &rEnginePackageStruct) {}

/**
 * @brief based on virtual function, gets information if the package was added
 * @returns false in hatchback case
 */
bool Hatchback::getIsPackageAdded() {
  return false;
}

/**
 * @brief based on virtual function, doing nothing in hatchback case
 */
void Hatchback::setIsPackageAdded() {}
