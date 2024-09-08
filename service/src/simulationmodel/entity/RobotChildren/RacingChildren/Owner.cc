
#include "Owner.h"
#include "AstarStrategy.h"
#include "SimulationModel.h"


Owner::Owner(const JsonObject& obj) : RacingRobot(obj) {
}
Owner::~Owner() {
    if (movement) delete movement;
}
void Owner::update(double dt) {
  // right now is the same as human
    if (movement && !movement->isCompleted()) {
        movement->move(this, dt);
    } else if (notified) {
        Vector3 dest;
        dest.x = unattendedPosition.x;
        dest.y = unattendedPosition.y;
        dest.z = unattendedPosition.z;
        if (model) {
            movement = new AstarStrategy(position, dest, model->getGraph());
        }
        notified = false;
    } else if (movement && movement->isCompleted()) {
        delete movement;
        movement = nullptr;
        this->receive(package);
     }
}

void Owner::receive(Package* p) {
    std::string message;
    std::string name = this->getDetails()["name"];
    std::string pos_message = "Great Service! Got my package so fast.";
    std::string neg_message = "Terrible service! Never even got my package.";
    if (package->requiresPickup) {
        package->requiresPickup = false;
        message = name + " writes: " + pos_message;
        this->notifyObservers(message);
    } else {
        message = name + " writes: " + neg_message;
        this->notifyObservers(message);
        package = nullptr;
    }
}

