#ifndef PPFACTORY_H_
#define PPFACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "PorchPirate.h"

/**
 *@brief Porch Pirate Factory to produce Porch Pirate class.
 **/
class PorchPirateFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for PorchPirateFactory class.
   **/
  virtual ~PorchPirateFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* createEntity(const JsonObject& entity);
};

#endif
