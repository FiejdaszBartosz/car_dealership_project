#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>

struct engineProperties{
  int hp; //horsepower
  int nm; //Newton metre
  std::string fuelType;
};

struct equipmentOptions{
    std::string interior;
};

class Vehicle
{
protected:
    std::string aName;
    std::string aType;
    int aProductionYear;
    engineProperties aEngine;
    equipmentOptions aEquipment;
    std::string *apUsage;
public:
    Vehicle();
    ~Vehicle();
    std::string getName() const;
    std::string getType() const;
    int getProductionYear() const;
    engineProperties getEngine() const;
    equipmentOptions getEquipment() const;
    std::string *getUsage() const;
    std::string setName();
    std::string setType();
    int setProductionYear();
    engineProperties setEngine();
    equipmentOptions setEquipment();
    std::string *setUsage();
};

#endif // VEHICLE_H
