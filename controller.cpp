#include "controller.h"

#include <chrono>
#include <iostream>

Controller::Controller(Gui* gui)
    : mState(State::stopped), mGui(gui), mCounter(0) {
    mGui->setText(std::to_string(mCounter));
    std::cout << "Controller constructor\n";
}

Controller::~Controller() {
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
    std::cout << "void Controller::stop()\n";
    if (mState != State::stopped) {
        mState = State::stopped;
        mRunnerThread.join();
        std::cout << "worker thread joined\n";
        mCounter = 0;
        mGui->setText(std::to_string(mCounter));
    }
    std::cout << "Setting mState = stopped\n";
}

void Controller::setUpdateInterval(int updateInterval) {
    mUpdateInterval = updateInterval;
}

void Controller::runner() {
    std::cout << "Starting runner()\n";
    while (mState != State::stopped) {
        std::this_thread::sleep_for(std::chrono::milliseconds(mUpdateInterval));
        if (mState == State::running) {
            mGui->setText(std::to_string(mCounter++));
        }
    }
    std::cout << "runner() returns\n";
}