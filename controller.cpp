#include "controller.h"

#include <iostream>

Controller::Controller(Gui* gui) : mNumber(0), state(idle), mGui(gui) {
    std::cout << "Controller constructor\n";
}

Controller::Controller() : mNumber(0), state(idle) {
    std::cout << "Controller constructor\n";
}

void Controller::start() {
    std::cout << "Controller start\n";
    state = running;
}

void Controller::stop() {
    std::cout << "Controller stop\n";
    state = idle;
}

void Controller::inc() {
    if (state == running) mNumber++;
    std::cout << "Controller inc, mNumber = " << mNumber << std::endl;
    mGui->setText(std::to_string(mNumber));
}