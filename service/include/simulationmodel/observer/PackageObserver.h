#ifndef PACKOBSERVER_H_
#define PACKOBSERVER_H_

#include <string>

#include "vector3.h"
#include "Package.h"
/**
 * @class PackageObserver 
 * @brief interface provides a map on how interested parties receive
 * notification when package dropped at destination
 **/
class PackageObserver {
 public:
 /**
 * @brief interested parties receive notification
 **/
  virtual void notify(Vector3 position, Package* package) = 0;
};

#endif
