#include "../include/mainwindow.h"
#include "../include/Vehicle.h"

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
    engineProperties newEngine;
    newEngine.hp = 100;
    newEngine.nm = 200;
    newEngine.fuelType = "petrol";

    equipmentOptions newEquipment;
    newEquipment.interior = "wood";

    std::string newUsage[2] = {"city", "long"};

    Vehicle newVehicle("mercedes",
                       "Combi",
                       2020,
                       newEngine,
                       newEquipment,
                       newUsage);
    std::cout << "test";
    return 0;
#endif //test
}
