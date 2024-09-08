#ifndef GREEN_DECORATOR_H_
#define GREEN_DECORATOR_H_

#include "PackageColorDecorator.h"

/**
 * @class GreenDecorator
 * @brief Colors the packages green in the simulation
 */
class GreenDecorator : public PackageColorDecorator {
 public:
 /**
 * @brief GreenDecorator Constructor
 * @param The package that will be colored green
 */
  GreenDecorator(Package*);
};

#endif  // GREEN_DECORATOR_H_
