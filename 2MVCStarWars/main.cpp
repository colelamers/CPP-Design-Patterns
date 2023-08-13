#include <iostream>
#include "Controller/controller.h"

int main() {
  Controller controller;
  controller.updateView(
  controller.jediModel(), 
  controller.sithModel()
  );

  return 0;
}