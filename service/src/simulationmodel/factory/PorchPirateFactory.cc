#include "PorchPirateFactory.h"

IEntity* PorchPirateFactory::createEntity(const JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("pirate") == 0) {
    std::cout << "Porch pirate Created" << std::endl;
    return new PorchPirate(entity);
  }
  return nullptr;
}
