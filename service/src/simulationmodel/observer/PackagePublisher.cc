#include "PackagePublisher.h"

void PackagePublisher::addPerson(PackageObserver* o) { observers.push_back(o); }

void PackagePublisher::removePerson(PackageObserver* o) {
  for (int i = observers.size() - 1; i >= 0; i--) {
    if (observers[i] == o) {
      observers.erase(observers.begin() + i);
    }
  }
}

void PackagePublisher::notifyOwner(Vector3 position, Package* package) {
  for (auto& o : observers) o->notify(position, package);
}
