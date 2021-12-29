#ifndef HATCHBACK_H
#define HATCHBACK_H

#include <Vehicle.h>

class Hatchback : public Vehicle {
 public:
  Hatchback();
  Hatchback(std::string &rName,
			int &rProductionYear,
			std::vector<engineProperties> &rEngine,
			std::vector<accessories> &rInterior,
			std::vector<accessories> &rColor,
			std::vector<accessories> &rWheels,
			std::vector<accessories> &rAdditionalEquipment);
};

#endif // HATCHBACK_H
