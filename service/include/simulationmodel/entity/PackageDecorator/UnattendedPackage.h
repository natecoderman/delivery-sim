#ifndef UNATPACKAGE_H_
#define UNATPACKAGE_H_

#include <vector>
#include <string>
#include "PackageDecorator.h"
#include "PackagePublisher.h"
#include "PorchPirate.h"
#include "Owner.h"
#include "SimulationModel.h"


/**
 *@brief Unattended package class decorates package
 * adds functionality to handle porch pirates stealing packages
 **/
class UnattendedPackage : public PackageDecorator, public PackagePublisher {
 public:
  /**
   * @brief Unattended Package Constructor
   **/
  UnattendedPackage(Package*);

  /**
   * @brief Package adds Owner to observer list 
   * @param model simulation vector owners finds owner
   **/

  void findOwner(SimulationModel* model);

  /**
   * @brief Package adds nearby Pirates to observer list 
   * @param model simulation vector pirates finds nearby pirates
   **/

  void findPirates(SimulationModel* model);

 private:
  Package* wrappee;
};
#endif
