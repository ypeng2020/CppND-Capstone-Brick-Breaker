#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "bar.h"

class Controller {
 public:
  void HandleInput(bool &running, Bar &bar) const;

 private:
  void CheckDirection(Bar &bar, Bar::Direction input) const;
};

#endif