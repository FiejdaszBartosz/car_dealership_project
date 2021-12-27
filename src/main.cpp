#include "../include/mainwindow.h"
#include "../include/Vehicle.h"
#include "../include/Hatchback.h"

#include <QApplication>

int main(int argc, char *argv[])
{
#define test

#ifdef notTest
    QApplication a(argc, argv);
    Vehicle nowyPojazd;
    MainWindow w;
    w.show();
    return a.exec();
#endif //notTest

#ifdef test
    std::vector <engineProperties> newEngine;
    std::vector <accessories> newInterior;
    std::vector <accessories> newColor;
    std::vector <accessories> newWheels;
    std::vector <accessories> newAdditionalEquipment;

    Hatchback newVehicle("mercedes",
                         "Combi",
                         2020,
                         newEngine,
                         newInterior,
                         newColor,
                         newWheels,
                         newAdditionalEquipment);

    std::cout << newVehicle.getType() << std::endl << std::endl;
    std::cout << newVehicle.getName() << std::endl <<
                 newVehicle.getType() << std::endl <<
                 newVehicle.getProductionYear() << std::endl;

    return 0;
#endif //test
}
