#include "../include/VehicleManager.h"

/**
  * @brief constructor
*/
VehicleManager::VehicleManager() {}

/**
  * @brief destructor
  */
VehicleManager::~VehicleManager() {}

/**
  * @returns vehicle register
  */
std::vector<Vehicle *> VehicleManager::getVehicleRegister() const {
  return aVehicleRegister;
}

/**
  * @returns vehicle register length
  */
int VehicleManager::getRegisterLenght() const {
  return aVehicleRegister.size();
}

/**
  * @brief sets vehicle register
  * @param vehicleRegister input register
  */
void VehicleManager::setVehicleRegister(const std::vector<Vehicle *> vehicleRegister) {
  this->aVehicleRegister = vehicleRegister;
}

/**
  * @brief adds hatchback object to register
  * @param pHatchback input hatchback
  */
void VehicleManager::addElemnt(Hatchback *pHatchback) {
  aVehicleRegister.push_back(pHatchback);
}

/**
  * @brief adds limousine object to register
  * @param pHatchback input limousine
  */
void VehicleManager::addElemnt(Limousine *pLimousine) {
  aVehicleRegister.push_back(pLimousine);
}

/**
  * @brief adds sport vehicle object to register
  * @param pSportVehicle input sport vehicle
  */
void VehicleManager::addElemnt(SportVehicle *pSportVehicle) {
  aVehicleRegister.push_back(pSportVehicle);
}

/**
  * @brief removes element from register
  * @param position element position to be deleted
  */
void VehicleManager::removeElemnt(const int position) {
  auto temp = getVehicleRegister();
  temp.erase(temp.begin() + position);
  setVehicleRegister(temp);
}

/**
  * @brief checks type of vehicle in file
  * @param rType - vehicle type
  * @param rTypeNumber
  * @param rAttributesNumber - number of attributes to be loaded
  */
bool VehicleManager::checkType(std::string &rType, int &rTypeNumber, int &rAttributesNumber) const {
  if (rType == "hatchback") {
	rAttributesNumber = 6;
	rTypeNumber = 0;
	return true;
  } else if (rType == "limousine") {
	rAttributesNumber = 7;
	rTypeNumber = 1;
	return true;
  } else if (rType == "sportVehicle") {
	rAttributesNumber = 7;
	rTypeNumber = 2;
	return true;
  } else
	return false;
}

/**
  * @brief saves vehicles to file
  * @param fileName - file location
  */
void VehicleManager::saveAllVehicle(const std::string fileName) {
  for (std::vector<Vehicle *>::iterator iter = aVehicleRegister.begin(); iter != aVehicleRegister.end(); ++iter) {
	(*iter)->saveToFile(fileName);
  }
}

/**
  * @brief loads vehicles from file
  * @param fileName - file location
  */
void VehicleManager::loadAllVehicle(const std::string fileName) {
  bool checkTypeFlag = false;
  std::fstream input;
  std::vector<std::string> row;
  std::string line, word;
  int typeNumber = 0, attributesNumber = 0, i = 0;
  input.open(fileName, std::ios::in);
  Hatchback *pTempHatchback = new Hatchback;
  Limousine *pTempLimousine = new Limousine;
  SportVehicle *pTempSportVehicle = new SportVehicle;
  bool isSetHatchback = false,
	  isSetLimousine = false,
	  isSetSportVehicle = false;

  while (getline(input, line)) {                                            //saves all line to line variable
	std::stringstream s(line);
	while (std::getline(s, word, ',')) {
	  if (!checkTypeFlag) {                                                            //whether the type was checked?
		if (!checkType(word, typeNumber, attributesNumber))                //checks type
		  std::cout << "invalid type\n";
		checkTypeFlag = true;
	  }
	  row.push_back(word);
	}
	if (typeNumber == 0 && i < 6) {                                                    //case for hatchback
	  int tempInt1 = 0, tempInt2 = 0, tempInt3 = 0;
	  std::string tempString;

	  switch (i) {
		case 0:                                                                    //loads name, prodYear, length
		  tempString = row.at(1);
		  pTempHatchback->setName(tempString);
		  tempString = row.at(2);
		  tempInt1 = std::stoi(tempString);
		  pTempHatchback->setProductionYear(tempInt1);
		  tempString = row.at(3);
		  tempInt1 = std::stoi(tempString);
		  pTempHatchback->setVehicleLength(tempInt1);
		  break;
		case 1:                                                                    //loads engines
		  for (int j = 0; j < row.size(); j += 4) {
			tempString = row.at(j);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j + 1);
			tempInt2 = std::stoi(tempString);
			tempString = row.at(j + 3);
			tempInt3 = std::stoi(tempString);
			tempString = row.at(j + 2);
			pTempHatchback->addEngine(tempInt1,
									  tempInt2,
									  tempString,
									  tempInt3);
		  }
		  break;
		case 2:                                                                    //loads interiors
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempHatchback->addInterior(tempString,
										tempInt1);
		  }
		  break;
		case 3:                                                                    //loads colors
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempHatchback->addColor(tempString,
									 tempInt1);
		  }
		  break;
		case 4:                                                                    //wheels
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempHatchback->addWheels(tempString,
									  tempInt1);
		  }
		  break;
		case 5:                                                                    //additionalEquipment
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempHatchback->addAdditionalEquipment(tempString,
												   tempInt1);
		  }
		  break;
		default:std::cout << "unexpected error\n";
		  break;
	  }
	  i++;
	  row.clear();
	  if (i == 6) {
		addElemnt(pTempHatchback);
		isSetHatchback = true;
		checkTypeFlag = false;
		i = 0;
	  }
	} else if (typeNumber == 1 && i < 7) {                                            //case for limousine
	  int tempInt1 = 0, tempInt2 = 0, tempInt3 = 0;
	  std::string tempString;
	  bool tempBool;

	  switch (i) {
		case 0:                                                                    //loads name, prodYear, length
		  tempString = row.at(1);
		  pTempLimousine->setName(tempString);
		  tempString = row.at(2);
		  tempInt1 = std::stoi(tempString);
		  pTempLimousine->setProductionYear(tempInt1);
		  tempString = row.at(3);
		  tempInt1 = std::stoi(tempString);
		  pTempLimousine->setVehicleLength(tempInt1);
		  break;
		case 1:                                                                    //loads engines
		  for (int j = 0; j < row.size(); j += 4) {
			tempString = row.at(j);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j + 1);
			tempInt2 = std::stoi(tempString);
			tempString = row.at(j + 3);
			tempInt3 = std::stoi(tempString);
			tempString = row.at(j + 2);
			pTempLimousine->addEngine(tempInt1,
									  tempInt2,
									  tempString,
									  tempInt3);
		  }
		  break;
		case 2:                                                                    //loads interiors
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempLimousine->addInterior(tempString,
										tempInt1);
		  }
		  break;
		case 3:                                                                    //loads colors
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempLimousine->addColor(tempString,
									 tempInt1);
		  }
		  break;
		case 4:                                                                    //wheels
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempLimousine->addWheels(tempString,
									  tempInt1);
		  }
		  break;
		case 5:                                                                    //additionalEquipment
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempLimousine->addAdditionalEquipment(tempString,
												   tempInt1);
		  }
		  break;
		case 6:
		  for (int j = 0; j < row.size(); ++j) {
			tempString = row.at(j);
			std::istringstream(tempString) >> tempBool;
			if (tempBool)
			  pTempLimousine->addLongVersion();
		  }
		  break;
		default:std::cout << "unexpected error\n";
		  break;
	  }
	  i++;
	  row.clear();
	  if (i == 7) {
		addElemnt(pTempLimousine);
		isSetLimousine = true;
		checkTypeFlag = false;
		i = 0;
	  }
	} else if (typeNumber == 2 && i < 7) {                                            //case for sportVehicle
	  int tempInt1 = 0, tempInt2 = 0, tempInt3 = 0;
	  std::string tempString;

	  switch (i) {
		case 0:                                                                    //loads name, prodYear, length
		  tempString = row.at(1);
		  pTempSportVehicle->setName(tempString);
		  tempString = row.at(2);
		  tempInt1 = std::stoi(tempString);
		  pTempSportVehicle->setProductionYear(tempInt1);
		  tempString = row.at(3);
		  tempInt1 = std::stoi(tempString);
		  pTempSportVehicle->setVehicleLength(tempInt1);
		  break;
		case 1:                                                                    //loads engines
		  for (int j = 0; j < row.size(); j += 4) {
			tempString = row.at(j);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j + 1);
			tempInt2 = std::stoi(tempString);
			tempString = row.at(j + 3);
			tempInt3 = std::stoi(tempString);
			tempString = row.at(j + 2);
			pTempSportVehicle->addEngine(tempInt1,
										 tempInt2,
										 tempString,
										 tempInt3);
		  }
		  break;
		case 2:                                                                    //loads interiors
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempSportVehicle->addInterior(tempString,
										   tempInt1);
		  }
		  break;
		case 3:                                                                    //loads colors
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempSportVehicle->addColor(tempString,
										tempInt1);
		  }
		  break;
		case 4:                                                                    //wheels
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempSportVehicle->addWheels(tempString,
										 tempInt1);
		  }
		  break;
		case 5:                                                                    //additionalEquipment
		  for (int j = 0; j < row.size(); j += 2) {
			tempString = row.at(j + 1);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j);
			pTempSportVehicle->addAdditionalEquipment(tempString,
													  tempInt1);
		  }
		  break;
		case 6:                                                                    //enginePackage
		  for (int j = 0; j < row.size(); j += 4) {
			tempString = row.at(j);
			tempInt1 = std::stoi(tempString);
			tempString = row.at(j + 1);
			tempInt2 = std::stoi(tempString);
			tempString = row.at(j + 3);
			tempInt3 = std::stoi(tempString);
			tempString = row.at(j + 2);
			pTempSportVehicle->addEnginePackage(tempInt1,
												tempInt2,
												tempString,
												tempInt3);
		  }
		  break;
		default:std::cout << "unexpected error\n";
		  break;
	  }
	  i++;
	  row.clear();
	  if (i == 7) {
		addElemnt(pTempSportVehicle);
		isSetSportVehicle = true;
		checkTypeFlag = false;
		i = 0;
	  }
	} else
	  std::cout << "Unexpected error\n";
  }
  if (!isSetHatchback)
	delete pTempHatchback;
  if (!isSetLimousine)
	delete pTempLimousine;
  if (!isSetSportVehicle)
	delete pTempSportVehicle;
  input.close();
}


