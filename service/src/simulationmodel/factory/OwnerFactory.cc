#include "OwnerFactory.h"

IEntity* OwnerFactory::createEntity(const JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("owner") == 0) {
    std::cout << "Owner Created" << std::endl;
    return new Owner(entity);
  }
  return nullptr;
}
