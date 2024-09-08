#ifndef PORCHPIRATE_H_
#define PORCHPIRATE_H_

#include <string>
#include <vector>
#include "RacingRobot.h"

/**
 *@brief PorchPirate class inherits from Racing Robot Class
 * Handles behaviors specific to porch pirates
 **/
class PorchPirate : public RacingRobot {
 public:
  /**
   * @brief PorchPirate class Constructor
   **/
  PorchPirate(const JsonObject& obj);

  /**
   * @brief PorchPirate class destructor
   **/
  ~PorchPirate();

  /**
   * @brief Updates the porch pirate's position
   * When target package exists, they use movement strategy
   * When no target package exists, they move randomly around campus
   * @param dt Delta time
   */
  void update(double dt);

  /**
   * @brief Steals package from it's drop location
   * Delivery is falsly marked as completed
   * notifyObservers(...) sends number of stolen packages to front end
   * @param p Package pointer is the scheduled package 
   */
  void receive(Package * p);
  /**
   * @brief Check if it is necessary to change package
   * becuase a new package was dropped off closer.
   */
  bool changePackage();

 private:
  bool onWayToPackage;
  int packagesStolen;
  std::vector<Package*> stolenPackages;
};
#endif
