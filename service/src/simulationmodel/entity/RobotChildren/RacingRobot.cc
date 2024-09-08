#include "RacingRobot.h"

#include <sstream>
#include <string>
#include <vector>

RacingRobot::RacingRobot(const JsonObject& obj)  : Robot(obj) {
    package = nullptr;
    collected = 0;
}
void RacingRobot::notify(Vector3 position, Package* package) {
    this->package = package;
    this->unattendedPosition = position;
    this->notified = true;
}

