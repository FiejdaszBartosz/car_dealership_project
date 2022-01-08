#ifndef SPORTVEHICLE_H
#define SPORTVEHICLE_H

#include <Vehicle.h>

class SportVehicle : public Vehicle {
 protected:
  std::vector<engineProperties> aEnginePackage;
 public:
  SportVehicle();
  SportVehicle(std::string &rName,
			   int &rProductionYear,
			   int &rVehicleLength,
			   std::vector<engineProperties> &rEngine,
			   std::vector<accessories> &rInterior,
			   std::vector<accessories> &rColor,
			   std::vector<accessories> &rWheels,
			   std::vector<accessories> &rAdditionalEquipment,
			   std::vector<engineProperties> &rEnginePackage);
  ~SportVehicle();
  std::vector<engineProperties> getEnginePackage() const;
  void setEnginePackage(const std::vector<engineProperties> &rEnginePackageVector);
  void setEnginePackage(const engineProperties &rEnginePackageStruct);
  void addEnginePackage(const int &rHp,
						const int &rNm,
						const std::string &rFuelType,
						const int &rEnginePrice);
  void removeEnginePackage(const int &rHp,
						   const int &rNm,
						   const std::string &rFuelType,
						   const int &rEnginePrice);
  void changeEnginePackageProperties(const int &rHp,
									 const int &rNm,
									 const std::string &rFuelType,
									 const int &rEnginePrice);
  void upgradeEngine(int position);
  void saveToFile() const;
};

#endif // SPORTVEHICLE_H
