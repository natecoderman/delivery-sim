#ifndef OWNER_H_
#define OWNER_H_

#include <string>
#include "RacingRobot.h"

/**
 *@brief Owner class inherits from Racing Robot Class
 * Handles behaviors specific to package Owners
 **/
class Owner : public RacingRobot {
 public:
  /**
   * @brief Owner class Constructor
   **/
  Owner(const JsonObject& obj);

  /**
   * @brief Owner class Destructor
   **/
  ~Owner();

  /**
   * @brief Updates the owners's position
   * this overrides Robot class's update function
   * @param dt Delta time
   */
  void update(double dt);

  /**
   * @brief Tries to receive package from it's drop location
   * notifyObservers(...) sends review to front end
   * @param p Package pointer is the scheduled package 
   */
  void receive(Package * p);
};
#endif
