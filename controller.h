#pragma once

#include <iostream>
#include <thread>

#include "gui.h"

class Gui;  // forward declaration

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
    ~Controller();
    void start();
    void stop();
    void inc();

   private:
    void runner();
    bool mRunning = false;
    std::thread mRunnerThread;
    int mNumber;
    State mState;
    Gui* mGui;
};