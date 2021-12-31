#include "../include/mainwindow.h"
#include "../include/Vehicle.h"
#include "../include/Hatchback.h"
#include "../include/Limousine.h"
#include "../include/SportVehicle.h"
#include "../include/VehicleManager.h"

#include <QApplication>

int main(int argc, char *argv[]) {
#define test

#ifdef notTest
  QApplication a(argc, argv);
  Vehicle nowyPojazd;
  MainWindow w;
  w.show();
  return a.exec();
#endif //notTest

#ifdef test
  std::vector<engineProperties> newEngine;
  std::vector<accessories> newInterior;
  std::vector<accessories> newColor;
  std::vector<accessories> newWheels;
  std::vector<accessories> newAdditionalEquipment;

  Hatchback newHatchback;
  newHatchback.addEngine(300, 500, "petrol", 15000);
  newHatchback.addInterior("brown leather", 15000);
  newHatchback.addColor("black metallic", 3000);
  newHatchback.addWheels("18", 5000);
  newHatchback.addColor("panoramic roof", 5000);
  newHatchback.setName("panamera");
  newHatchback.setProductionYear(2020);
  newHatchback.setVehicleLength(2100);

  std::cout << newHatchback.getName() << std::endl <<
            newHatchback.getType() << std::endl <<
            newHatchback.getProductionYear() << std::endl <<
            newHatchback.getVehicleLength() << std::endl;

  SportVehicle *newSport = new SportVehicle;
  newSport->addEngine(300, 500, "petrol", 15000);
  newSport->addInterior("brown leather", 15000);
  newSport->addColor("black metallic", 3000);
  newSport->addWheels("18", 5000);
  newSport->addColor("panoramic roof", 5000);
  newSport->setName("G class");
  newSport->setProductionYear(2020);
  newSport->setVehicleLength(2100);
  newSport->addEnginePackage(100, 50, "petrol", 5000);
  newSport->upgradeEngine(0);

  std::cout << newSport->getName() << std::endl <<
               newSport->getEngine().at(0).hp << std::endl <<
               newSport->getEngine().at(0).nm << std::endl;

  SportVehicle *newSport1 = new SportVehicle;
  VehicleManager newMenager;
  newMenager.addElemnt(newSport);
  delete newSport;
  delete newSport1;
  return 0;
#endif //test
}
