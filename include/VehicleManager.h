#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H
#include "../include/Vehicle.h"
#include "../include/Hatchback.h"
#include "../include/Limousine.h"
#include "../include/SportVehicle.h"
#include <vector>
#include <sstream>
#include <string>

class VehicleManager {
 protected:
  std::vector<Vehicle *> aVehicleRegister;

 public:
  VehicleManager();
  ~VehicleManager();
  std::vector<Vehicle *> getVehicleRegister() const;
  void setVehicleRegister(const std::vector<Vehicle *> vehicleRegister);
  void addElemnt(Hatchback *pHatchback);
  void addElemnt(Limousine *pLimousine);
  void addElemnt(SportVehicle *pSportVehicle);
  void removeElemnt(const int position);
  bool checkType(std::string &rType, int &rTypeNumber, int &rAttributesNumber) const;
  void saveAllVehicle();
  void loadAllVehicle();
};

#endif // VEHICLEMANAGER_H
