#ifndef RED_DECORATOR_H_
#define RED_DECORATOR_H_

#include "PackageColorDecorator.h"

/**
 * @class RedDecorator
 * @brief Colors the packages red in the simulation
 */
class RedDecorator : public PackageColorDecorator {
 public:
 /**
 * @brief Red Constructor
 * @param The package that will be colored red
 */
  RedDecorator(Package*);
};

#endif  // RED_DECORATOR_H_
