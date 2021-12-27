#ifndef HATCHBACK_H
#define HATCHBACK_H

#include <Vehicle.h>

class Hatchback : public Vehicle
{
public:
    Hatchback();
    Hatchback(std::string name,
              std::string type,
              int productionYear,
              std::vector <engineProperties> engine,
              std::vector <accessories> interior,
              std::vector <accessories> color,
              std::vector <accessories> wheels,
              std::vector <accessories> additionalEquipment);
};

#endif // HATCHBACK_H
