#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <vector>

struct engineProperties {
  int hp; //horsepower
  int nm; //Newton metre
  std::string fuelType;
  int enginePrice;
};

//struct for accessories like leather upholstery 1000PLN
struct accessories {
  std::string accessoriesName;
  int accessoriesPrice;
};

class Vehicle {
 protected:
  std::string aName;
  std::string aType;
  int aProductionYear;
  int aVehicleLength;
  std::vector<engineProperties> aEngine;
  std::vector<accessories> aInterior;
  std::vector<accessories> aColor;
  std::vector<accessories> aWheels;
  std::vector<accessories> aAdditionalEquipment;

  void createEngine(const int &rHp,
					const int &rNm,
					const std::string &rFuelType,
					const int &rEnginePrice,
					engineProperties &rEngine);
  void createAccessories(const std::string &rAccessoriesName,
						 const int &rAccessoriesPrice,
						 accessories &rAccessories);

 public:
  Vehicle();
  Vehicle(std::string &rName,
		  std::string &rType,
		  int &rProductionYear,
          int &rVehicleLength,
		  std::vector<engineProperties> &rEngine,
		  std::vector<accessories> &rInterior,
		  std::vector<accessories> &rColor,
		  std::vector<accessories> &rWheels,
		  std::vector<accessories> &rAdditionalEquipment);

  std::string getName() const;
  std::string getType() const;
  int getProductionYear() const;
  int getVehicleLength() const;
  std::vector<engineProperties> getEngine() const;
  std::vector<accessories> getInterior() const;
  std::vector<accessories> getColor() const;
  std::vector<accessories> getWheels() const;
  std::vector<accessories> getAdditionalEquipment() const;
  void setName(const std::string &rName);
  void setType(const std::string &rType);
  void setProductionYear(const int &rProductionYear);
  void setVehicleLength(const int &rVehicleLength);
  void addVehicleLength(const int &rAdditionaLenght);
  //engine functions section
  void setEngine(const std::vector<engineProperties> &rEngineVector);
  void setEngine(const engineProperties &rEngineStruct);
  void addEngine(const int &rHp,
				 const int &rNm,
				 const std::string &rFuelType,
				 const int &rEnginePrice);
  void removeEngine(const int &rHp,
					const int &rNm,
					const std::string &rFuelType,
					const int &rEnginePrice);
  void changeEngineProperties(const int &rHp,
							  const int &rNm,
							  const std::string &rFuelType,
							  const int &rEnginePrice);
  //interior functions section
  void setInterior(const std::vector<accessories> &rInteriorVector);
  void setInterior(const accessories &rInteriorStruct);
  void addInterior(const std::string &rAccessoriesName,
				   const int &rAccessoriesPrice);
  void removeInterior(const std::string &rAccessoriesName,
					  const int &rAccessoriesPrice);
  void changeInteriorProperties(const std::string &rAccessoriesName,
								const int &rAccessoriesPrice);
  //color functions section
  void setColor(const std::vector<accessories> &rColorVector);
  void setColor(const accessories &rColor);
  void addColor(const std::string &rAccessoriesName,
				const int &rAccessoriesPrice);
  void removeColor(const std::string &rAccessoriesName,
				   const int &rAccessoriesPrice);
  void changeColorProperties(const std::string &rAccessoriesName,
							 const int &rAccessoriesPrice);
  //wheels functions section
  void setWheels(const std::vector<accessories> &rWheels);
  void setWheels(const accessories &rWheels);
  void addWheels(const std::string &rAccessoriesName,
				 const int &rAccessoriesPrice);
  void removeWheels(const std::string &rAccessoriesName,
					const int &rAccessoriesPrice);
  void changeWheelsProperties(const std::string &rAccessoriesName,
							  const int &rAccessoriesPrice);
  //additional equipment functions section
  void setAdditionalEquipment(const std::vector<accessories> &rAdditionalEquipment);
  void setAdditionalEquipment(const accessories &rAdditionalEquipment);
  void addAdditionalEquipment(const std::string &rAccessoriesName,
							  const int &rAccessoriesPrice);
  void removeAdditionalEquipment(const std::string &rAccessoriesName,
								 const int &rAccessoriesPrice);
  void changeAdditionalEquipmentProperties(const std::string &rAccessoriesName,
										   const int &rAccessoriesPrice);
};

#endif // VEHICLE_H
