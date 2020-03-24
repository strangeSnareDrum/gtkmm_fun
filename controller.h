#pragma once

#include <iostream>

#include "gui.h"

enum State {
    idle = 0,
    running,
    paused,
    panicked,
};

class Controller {
   public:
    Controller(Gui* gui);
    Controller();
    void start();
    void stop();
    void inc();

   private:
    int mNumber;
    State state;
    Gui* mGui;
};