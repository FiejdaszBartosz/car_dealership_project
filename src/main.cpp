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

  Hatchback *newHatchback = new Hatchback;
  newHatchback->addEngine(300, 500, "petrol", 15000);
  newHatchback->addInterior("brown leather", 15000);
  newHatchback->addColor("black metallic", 3000);
  newHatchback->addWheels("18", 5000);
  newHatchback->addAdditionalEquipment("panoramic roof", 5000);
  newHatchback->setName("panamera");
  newHatchback->setProductionYear(2020);
  newHatchback->setVehicleLength(2100);

  std::cout << newHatchback->getName() << std::endl <<
			newHatchback->getType() << std::endl <<
			newHatchback->getProductionYear() << std::endl <<
			newHatchback->getVehicleLength() << std::endl;

  SportVehicle *newSport = new SportVehicle;
  newSport->addEngine(300, 500, "petrol", 15000);
  newSport->addEngine(600, 700, "petrol", 250000);
  newSport->addInterior("brown leather", 15000);
  newSport->addColor("black metallic", 3000);
  newSport->addWheels("18", 5000);
  newSport->addAdditionalEquipment("panoramic roof", 5000);
  newSport->setName("G class");
  newSport->setProductionYear(2020);
  newSport->setVehicleLength(2100);
  newSport->addEnginePackage(100, 50, "petrol", 5000);
  newSport->upgradeEngine(0);

  std::cout << newSport->getName() << std::endl <<
			newSport->getEngine().at(0).hp << std::endl <<
			newSport->getEngine().at(0).nm << std::endl;

  Limousine *newLimo = new Limousine;
  newLimo->addEngine(300, 500, "petrol", 15000);
  newLimo->addEngine(600, 700, "petrol", 250000);
  newLimo->addInterior("brown leather", 15000);
  newLimo->addColor("black metallic", 3000);
  newLimo->addWheels("18", 5000);
  newLimo->addAdditionalEquipment("panoramic roof", 5000);
  newLimo->setName("S class");
  newLimo->setProductionYear(2020);
  newLimo->setVehicleLength(2100);
  newLimo->addLongVersion();

  SportVehicle *newSport1 = new SportVehicle;
  VehicleManager newManager;
  newManager.addElemnt(newSport);
  newManager.saveAllVehicle();
  newManager.loadAllVehicle();
  delete newSport;
  delete newSport1;
  delete newHatchback;
  delete newLimo;
  return 0;
#endif //test
}
