#include "Auctioneer.h"
#include <limits>

void Auctioneer::calculateBids(SimulationModel* simModel) {
    for (auto ent = simModel->entities.begin();
    // Loop through entities in simulation model
        ent != simModel->entities.end(); ent++) {
        IEntity* entity = ent->second;
        Drone* isDrone = dynamic_cast<Drone*>(entity);
        // Test if entity is drone
        if (isDrone && (!isDrone->getPackage())) {
            // If entity is drone and not assigned to a package,
            // add it to the bid
            for (Package* p : simModel->scheduledDeliveries) {
                this->addBid(p, dynamic_cast<Drone*>(entity));
            }
        }
    }
    std::tuple<Package*, Drone*, double> bestBid = auction();
    Drone* winner = std::get<1>(bestBid);
    winner->setPackage(std::get<0>(bestBid));

    // Find and delete index of best bid to remove it from bids since
    // we have selected it and therefore no longer want it in the tuple
    int delInd = 0;
    for (Package* p : simModel->scheduledDeliveries) {
        if (p == (std::get<0>(bestBid))) {
            break;
        }
        delInd++;
    }

    (simModel->scheduledDeliveries).erase(
        (simModel->scheduledDeliveries).begin() + delInd);
}

std::tuple<Package*, Drone*, double> Auctioneer::auction() {
    int bestInd = -1;
    // Set first minDist to absolute max
    double minDist = std::numeric_limits<double>::max();
    for (int i = 0; i < this->bids.size(); i++) {
        // Loop through bids to find min distance; the smaller
        // the distance, the higher the bid
        double currentDist = std::get<2>(bids[i]);
        if (currentDist < minDist) {
            minDist = currentDist;
            bestInd = i;
        }
    }
    return bids[bestInd];
}

void Auctioneer::addBid(Package* package, Drone* drone) {
    // Get distance from package to drone
    double dist = (package->getPosition()).dist(drone->getPosition());
    // Create bid of tuple with the package, drone, and distance
    // between them, with the distance being the bid the package
    // is placing
    std::tuple<Package*, Drone*, double> bid =
        std::make_tuple(package, drone, dist);
    this->bids.push_back(bid);
    return;
}
