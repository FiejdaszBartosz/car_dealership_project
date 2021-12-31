#include "SportVehicle.h"

SportVehicle::SportVehicle()
{
    aName = "not set";
    aType = "sport vehicle";
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

void SportVehicle::upgradeEngine(int position){
  std::vector<engineProperties> temp = getEngine();
  engineProperties tempEnginePackage = getEnginePackage().at(position);
  for(auto& var : temp)
      var = var + tempEnginePackage;
  setEngine(temp);
}

//Adds engine package to engine
engineProperties operator+(const engineProperties &lhs, const engineProperties &rhs) {
    return {lhs.hp + rhs.hp,
            lhs.nm + rhs.nm};
}