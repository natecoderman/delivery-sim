#include "PorchPirate.h"
#include "SimulationModel.h"


#include "AstarStrategy.h"
#include "SimulationModel.h"
#include "UnattendedPackage.h"

PorchPirate::PorchPirate(const JsonObject& obj) : RacingRobot(obj) {
    onWayToPackage = false;
    this->packagesStolen = 0;
}

PorchPirate::~PorchPirate() {
    if (movement) delete movement;
}

void PorchPirate::update(double dt) {
  if (!package) {  // move randomly as humans
    if (movement && !movement->isCompleted()) {
      movement->move(this, dt);
      for (int i = 0; i < stolenPackages.size(); i++) {
        if (stolenPackages[i]) {
          stolenPackages[i]->setPosition(position);
          stolenPackages[i]->setDirection(direction);
        }
      }
    } else {
      if (movement) delete movement;
      Vector3 dest;
      dest.x = ((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400;
      dest.y = position.y;
      dest.z = ((static_cast<double>(rand())) / RAND_MAX) * (1600) - 800;
      if (model) {
        movement = new AstarStrategy(position, dest, model->getGraph());
      }
    }
  } else {
    if (!movement) {
      if (model) movement = new AstarStrategy(position,
                                              unattendedPosition,
                                              model->getGraph());
    }
    if (movement->isCompleted()) {
      receive(package);
      return;
    }
    if (changePackage()) {
      if (model) movement = new AstarStrategy(position,
                                              unattendedPosition,
                                              model->getGraph());
    }
    movement->move(this, dt);
  }
}

bool PorchPirate::changePackage() {
  if (!package) return false;
  if (!movement) return false;
  PathStrategy* strat = dynamic_cast<PathStrategy*>(movement);
  return position.dist(unattendedPosition) <
         position.dist(strat->path[strat->path.size()-1]);
}

void PorchPirate::receive(Package * p) {
  UnattendedPackage* currentPackage = dynamic_cast<UnattendedPackage*>(p);
  if (currentPackage->requiresPickup) {
    currentPackage->requiresPickup = false;
    packagesStolen++;
    stolenPackages.push_back(package);
    std::string message = name + " just stole a package. "
                        + std::to_string(packagesStolen) + " stolen so far!";
    this->notifyObservers(message);
  } else {
    package = nullptr;
  }
}

