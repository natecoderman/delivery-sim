#ifndef RACEROBOT_H_
#define RACEROBOT_H_

#include "Robot.h"
#include "PackageObserver.h"
#include "math/vector3.h"
#include "IStrategy.h"
#include "Package.h"
#include "AstarStrategy.h"

/**
 *@brief Racing Robot class inherits from Robot Class
 * Handles behavior of both owners and porch pirates
 **/
class RacingRobot : public Robot, public PackageObserver {
 public:
  /**
   * @brief Racing Robot Constructor
   **/
  RacingRobot(const JsonObject& obj);

  /**
   * @brief Receive notification that package has been dropped at destination
   * @param position provides package's location to observers
   * @param package will allow for interaction between package and observers
   **/
  void notify(Vector3 position, Package* package);

 protected:
  IStrategy* movement = nullptr;
  Package* package;
  Vector3 unattendedPosition;
  int collected;
  bool notified = false;
};
#endif
