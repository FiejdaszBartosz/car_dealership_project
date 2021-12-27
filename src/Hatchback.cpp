#include "Hatchback.h"

Hatchback::Hatchback()
{

}

Hatchback::Hatchback(std::string name,
                 std::string type,
                 int productionYear,
                 std::vector <engineProperties> engine,
                 std::vector <accessories> interior,
                 std::vector <accessories> color,
                 std::vector <accessories> wheels,
                 std::vector <accessories> additionalEquipment){
aName = name;
aType = type;
aProductionYear = productionYear;
aEngine = engine;
aInterior = interior;
aColor = color;
aWheels = wheels;
aAdditionalEquipment = additionalEquipment;
}
