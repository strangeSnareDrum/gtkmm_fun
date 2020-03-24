#include "controller.h"

#include <chrono>
#include <iostream>

Controller::Controller(Gui* gui) : mNumber(0), mState(idle), mGui(gui) {
    std::cout << "Controller constructor\n";
}

Controller::Controller() : mNumber(0), mState(idle) {
    std::cout << "Controller constructor\n";
}

Controller::~Controller() {
    mRunnerThread.join();
    std::cout << "Controller destructor\n";
}

void Controller::start() {
    if (mState != State::running) {
        mRunnerThread = std::thread(&Controller::runner, this);
        std::cout << "Setting mState = running\n";
        mState = running;
    }
}

void Controller::stop() {
    if (mState != State::idle) {
        mRunning = false;
        std::cout << "Setting mState = idle\n";
        mState = idle;
    }
}

void Controller::inc() {
    if (mState == running) mNumber++;
    std::cout << "Controller inc, mNumber = " << mNumber << std::endl;
    mGui->setText(std::to_string(mNumber));
}

void Controller::runner() {
    std::cout << "Starting runner()\n";
    while (mState == State::running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "tick\n";
    }
    std::cout << "runner() returns\n";
}