#include "../include/mainwindow.h"
#include "../include/Vehicle.h"
#include "../include/Hatchback.h"

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

  newHatchback.setName("A class");
  newHatchback.setProductionYear(2020);

  std::cout << newHatchback.getName() << std::endl <<
			newHatchback.getType() << std::endl <<
			newHatchback.getProductionYear() << std::endl;

  return 0;
#endif //test
}
