#include "Limousine.h"

Limousine::Limousine()
{
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
                     std::vector<accessories> &rAdditionalEquipment){
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

Limousine::addLongVersion(){
    aIsLong = true;
    setType("long limousine");
    addVehicleLength(20);
}
