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

  void createEngine(int hpTemp,
					int nmTemp,
					std::string fuelTypeTemp,
					int enginePriceTemp,
					engineProperties rEngine);

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
  void setName(const std::string &rName);
  void setType(const std::string &rType);
  void setProductionYear(const int &rProductionYear);
  //engine functions section
  void setEngine(const std::vector<engineProperties> &rEngineVector);
  void setEngine(const engineProperties &rEngineStruct);
  void addEngine(int hp,
				 int nm,
				 std::string fuelType,
				 int enginePrice);
  void removeEngine(int hp,
					int nm,
					std::string fuelType,
					int enginePrice);
  void changeEngineProperties(int hp,
							  int nm,
							  std::string fuelType,
							  int enginePrice);
  void setInterior(const accessories &rInterior);
  void setColor(const accessories &rColor);
  void setWheels(const accessories &rWheels);
  void setAdditionalEquipment(const accessories &rAdditionalEquipment);
};

#endif // VEHICLE_H
