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

void VehicleManager::removeElemnt(const int position) {
  auto temp = getVehicleRegister();
  temp.erase(temp.begin() + position);
  setVehicleRegister(temp);
}

void VehicleManager::saveAllVehicle() {
    std::vector<Vehicle*>::iterator iter = aVehicleRegister.begin();
    for(iter; iter != aVehicleRegister.end(); ++iter) {
        (*iter)->saveToFile();
    }
}
