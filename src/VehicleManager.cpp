#include "../include/VehicleManager.h"

VehicleManager::VehicleManager()
{

}

VehicleManager::~VehicleManager() {
    for(std::vector<Vehicle*>::iterator it = aVehicleRegister.begin(); it != aVehicleRegister.end(); ++it) {
      delete *it;
    }
}

std::vector<Vehicle*> VehicleManager::getVehicleRegister() const {
    return aVehicleRegister;
}

void VehicleManager::setVehicleRegister(const std::vector<Vehicle*> vehicleRegister){
    this->aVehicleRegister = vehicleRegister;
}

void VehicleManager::addElemnt(Hatchback *pHatchback){
    aVehicleRegister.push_back(pHatchback);
}

void VehicleManager::addElemnt(Limousine *pLimousine){
    aVehicleRegister.push_back(pLimousine);
}

void VehicleManager::addElemnt(SportVehicle *pSportVehicle) {
    aVehicleRegister.push_back(pSportVehicle);
}
