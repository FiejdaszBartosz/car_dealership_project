#ifndef LIMOUSINE_H
#define LIMOUSINE_H

#include <Vehicle.h>

class Limousine : public Vehicle
{
protected:
    bool aIsLong;
public:
    Limousine();
    Limousine(std::string &rName,
              int &rProductionYear,
              int &rVehicleLength,
              std::vector<engineProperties> &rEngine,
              std::vector<accessories> &rInterior,
              std::vector<accessories> &rColor,
              std::vector<accessories> &rWheels,
              std::vector<accessories> &rAdditionalEquipment);
    void addLongVersion();
};

#endif // LIMOUSINE_H
