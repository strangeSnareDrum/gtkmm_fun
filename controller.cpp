#include "controller.h"

#include <chrono>
#include <iostream>

Controller::Controller(Gui* gui) : mState(State::stopped), mGui(gui) {
    std::cout << "Controller constructor\n";
}

Controller::~Controller() {
    mRunnerThread.join();
    std::cout << "Controller destructor\n";
}

void Controller::start() {
    if (mState == State::stopped) {
        mState = State::running;
        mRunnerThread = std::thread(&Controller::runner, this);
        std::cout << "Setting mState = running\n";
    } else {
        mState = State::running;
    }
}

void Controller::pause() {
    std::cout << "Setting mState = paused\n";
    if (mState == State::stopped) {
        mState = State::paused;
        mRunnerThread = std::thread(&Controller::runner, this);
    } else {
        mState = State::paused;
    }
}

void Controller::stop() {
    if (mState != State::stopped) {
        std::cout << "join worker thread\n";
        mState = State::stopped;
        mRunnerThread.join();
    }
    std::cout << "Setting mState = idle\n";
}

void Controller::runner() {
    std::cout << "Starting runner()\n";
    int counter = 0;
    while (mState != State::stopped) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        if (mState == State::running) {
            mGui->setText(std::to_string(counter++));
        }
    }
    std::cout << "runner() returns\n";
}