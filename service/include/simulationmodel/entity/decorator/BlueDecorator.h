#ifndef BLUE_DECORATOR_H_
#define BLUE_DECORATOR_H_

#include "PackageColorDecorator.h"

/**
 * @class BlueDecorator
 * @brief Colors the packages blue in the simulation
 */
class BlueDecorator : public PackageColorDecorator {
 public:
 /**
 * @brief BlueDecorator Constructor
 * @param The package that will be colored blue
 */
  BlueDecorator(Package*);
};

#endif  // BLUE_DECORATOR_H_
