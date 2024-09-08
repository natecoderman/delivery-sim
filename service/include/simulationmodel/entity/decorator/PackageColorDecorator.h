#ifndef PACKAGE_COLOR_DECORATOR_H_
#define PACKAGE_COLOR_DECORATOR_H_

#include "PackageDecorator.h"

/**
 * @class PackageColorDecorator
 * @brief Provides map for setting color of package in simulation
 */
class PackageColorDecorator : public PackageDecorator {
 private:
  double hue = 0;
  double saturation = 0;
  double light = 0;

 public:
 /**
 * @brief Package Color Decorator Constructor
 * @param Double the hue of the color
 * @param Double the saturation of the color
 * @param Double the light of the color
 */
  PackageColorDecorator(Package*, double = 0, double = 0, double = 0);
 /**
 * @brief Returns name of the color
 */
  std::string getColor() const;
};

#endif  // PACKAGE_COLOR_DECORATOR_H_
