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
  aType = "Hatchback";
  aProductionYear = rProductionYear;
  aVehicleLength = rVehicleLength;
  aEngine = rEngine;
  aInterior = rInterior;
  aColor = rColor;
  aWheels = rWheels;
  aAdditionalEquipment = rAdditionalEquipment;
}
