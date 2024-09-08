#include "UnattendedPackage.h"

UnattendedPackage::UnattendedPackage(Package* p) : PackageDecorator(p) {
    wrappee = p;
}

void UnattendedPackage::findOwner(SimulationModel* model) {
    if (model) {
        std::vector<Owner*> check = model->owners;
        std::string package_owner = this->getDetails()["owner"];
        for (int i =0; i < check.size(); i++) {
            std::string owner_name = check[i]->getDetails()["name"];
            if (package_owner == owner_name) {
                this->addPerson(check[i]);
            }
        }
    }
}

void UnattendedPackage::findPirates(SimulationModel* model) {
    std::vector<PorchPirate*> piratesNear;
    if (model) {
        std::vector<PorchPirate*> allPirates = model->pirates;
        for (int i = 0; i < allPirates.size(); i++) {
            if (this->getPosition().dist(allPirates[i]->getPosition()) < 700) {
                this->addPerson(allPirates[i]);
            }
        }
    }
}
