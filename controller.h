#pragma once

#include <iostream>
#include <thread>

#include "gui.h"

class Gui;  // forward declaration

enum State { stopped = 0, paused, running };

class Controller {
   public:
    Controller(Gui* gui);
    ~Controller();
    void start();
    void pause();
    void stop();
    void inc();

   private:
    void runner();
    std::thread mRunnerThread;
    State mState;
    Gui* mGui;
    int mCounter;
};