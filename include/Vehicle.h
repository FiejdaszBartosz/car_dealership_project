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
  std::vector<engineProperties> aEngine;
  std::vector<accessories> aInterior;
  std::vector<accessories> aColor;
  std::vector<accessories> aWheels;
  std::vector<accessories> aAdditionalEquipment;

  void createEngine(const int hp,
					const int nm,
					const std::string fuelType,
					const int enginePrice,
					engineProperties &rEngine);
  void createAccessories(const std::string accessoriesName,
						 const int accessoriesPrice,
						 accessories &rAccessories);

 public:
  Vehicle();
  Vehicle(std::string name,
		  std::string type,
		  int productionYear,
		  std::vector<engineProperties> engine,
		  std::vector<accessories> interior,
		  std::vector<accessories> color,
		  std::vector<accessories> wheels,
		  std::vector<accessories> additionalEquipment);

  std::string getName() const;
  std::string getType() const;
  int getProductionYear() const;
  std::vector<engineProperties> getEngine() const;
  std::vector<accessories> getInterior() const;
  std::vector<accessories> getColor() const;
  std::vector<accessories> getWheels() const;
  std::vector<accessories> getAdditionalEquipment() const;
  void setName(const std::string &rName);
  void setType(const std::string &rType);
  void setProductionYear(const int &rProductionYear);
  //engine functions section
  void setEngine(const std::vector<engineProperties> &rEngineVector);
  void setEngine(const engineProperties &rEngineStruct);
  void addEngine(const int hp,
				 const int nm,
                 const std::string fuelType,
				 const int enginePrice);
  void removeEngine(const int hp,
					const int nm,
					const std::string fuelType,
					const int enginePrice);
  void changeEngineProperties(const int hp,
							  const int nm,
							  const std::string fuelType,
							  const int enginePrice);
  //interior functions section
  void setInterior(const std::vector<accessories> &rInteriorVector);
  void setInterior(const accessories &rInteriorStruct);
  void addInterior(const std::string accessoriesName,
				   const int accessoriesPrice);
  void removeInterior(const std::string accessoriesName,
					  const int accessoriesPrice);
  void changeInteriorProperties(const std::string accessoriesName,
								const int accessoriesPrice);
  //color functions section
  void setColor(const std::vector<accessories> &rColorVector);
  void setColor(const accessories &rColor);
  void addColor(const std::string accessoriesName,
				const int accessoriesPrice);
  void removeColor(const std::string accessoriesName,
				   const int accessoriesPrice);
  void changeColorProperties(const std::string accessoriesName,
							 const int accessoriesPrice);
  //wheels functions section
  void setWheels(const std::vector<accessories> &rWheels);
  void setWheels(const accessories &rWheels);
  void addWheels(const std::string accessoriesName,
				 const int accessoriesPrice);
  void removeWheels(const std::string accessoriesName,
					const int accessoriesPrice);
  void changeWheelsProperties(const std::string accessoriesName,
							  const int accessoriesPrice);
  //additional equipment functions section
  void setAdditionalEquipment(const std::vector<accessories> &rAdditionalEquipment);
  void setAdditionalEquipment(const accessories &rAdditionalEquipment);
  void addAdditionalEquipment(const std::string accessoriesName,
							  const int accessoriesPrice);
  void removeAdditionalEquipment(const std::string accessoriesName,
								 const int accessoriesPrice);
  void changeAdditionalEquipmentProperties(const std::string accessoriesName,
										   const int accessoriesPrice);
};

#endif // VEHICLE_H
