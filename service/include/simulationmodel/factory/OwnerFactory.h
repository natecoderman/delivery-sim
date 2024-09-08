#ifndef OWNERFACTORY_H_
#define OWNERFACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Owner.h"

/**
 *@brief Owner Factory to produce Owner class.
 **/
class OwnerFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for OwnerFactory class.
   **/
  virtual ~OwnerFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* createEntity(const JsonObject& entity);
};

#endif
