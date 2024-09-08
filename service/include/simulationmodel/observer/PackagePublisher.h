#ifndef PACKAGEPUB_H_
#define PACKAGEPUB_H_

#include <vector>
#include <string>

#include "PackageObserver.h"
#include "vector3.h"
#include "Package.h"

 /**
 * @class PackagePublisher
 * @brief Package sends notification that it has been dropped off
 **/
class PackagePublisher {
 public:
  /**
  * @brief interested parties need notifications
  * @param o PackageObserver* is an entity that wants to observe
  **/
  void addPerson(PackageObserver* o);
  /**
  * @brief no longer interested parties do not need notifications
  * @param o PackageObserver* is an entity that was observing
  **/
  void removePerson(PackageObserver* o);
  /**
  * @brief Only the owner should receive the notification
  * but porch pirates sneak their way onto the notification list
  * @param position location of the package
  * @param package allows interactions between package and person
  **/
  void notifyOwner(Vector3 position, Package* package);

 private:
  std::vector<PackageObserver*> observers;
};

#endif
