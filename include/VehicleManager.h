#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H
#include "../include/Vehicle.h"
#include "../include/Hatchback.h"
#include "../include/Limousine.h"
#include "../include/SportVehicle.h"
#include <vector>
#include <memory>

class VehicleManager
{
protected:
    std::vector<Vehicle*> aVehicleRegister;
public:
    VehicleManager();
    ~VehicleManager();
    std::vector<Vehicle*> getVehicleRegister() const;
    void setVehicleRegister(const std::vector<Vehicle*> vehicleRegister);
    void addElemnt(Hatchback *pHatchback);
    void addElemnt(Limousine *pLimousine);
    void addElemnt(SportVehicle *pSportVehicle);
};

#endif // VEHICLEMANAGER_H
