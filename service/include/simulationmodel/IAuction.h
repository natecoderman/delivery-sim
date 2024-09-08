#ifndef I_AUCTION_H_
#define I_AUCTION_H_

#include "Package.h"

/**
 * @brief Auction interface
 *
 */
class IAuction {
 public:
  virtual ~IAuction() {}
  /**
   * @brief entities bid on another entity for some purpose. Currently only used for packages bidding on drones for scheduling.
   * @param simModel Simulation model that auctioneers/auctionees are in
   */
  virtual void calculateBids(SimulationModel* simModel) = 0;
};

#endif
