#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <vector>

struct engineProperties{
  int hp; //horsepower
  int nm; //Newton metre
  std::string fuelType;
  int enginePrice;
};

//struct for accessories like leather upholstery 1000PLN
struct accessories{
    std::string accessoriesName;
    int accessoriesPrice;
};

class Vehicle
{
protected:
    std::string aName;
    std::string aType;
    int aProductionYear;
    int aTotalPrice;
    std::vector <engineProperties> aEngine;
    std::vector <accessories> aInterior;
    std::vector <accessories> aColor;
    std::vector <accessories> aWheels;
    std::vector <accessories> aAdditionalEquipment;

public:
    Vehicle();
    Vehicle(std::string name,
            std::string type,
            int productionYear,
            std::vector <engineProperties> engine,
            std::vector <accessories> interior,
            std::vector <accessories> color,
            std::vector <accessories> wheels,
            std::vector <accessories> additionalEquipment);

    std::string getName() const;
    std::string getType() const;
    int getProductionYear() const;
    void setName(const std::string name);
    void setType(const std::string type);
    void setProductionYear(const int productionYear);
    void setEngine(const std::vector <engineProperties> engineVector);
    void setEngine(const engineProperties engineStruct);
    void setAccessories(const std::vector <accessories> accessoriesVector);
    void setAccessories(const accessories accessoriesStruct);
};

#endif // VEHICLE_H
