#include <chrono>
#include <iostream>

#include "controller.h"

int main() {
    auto app = Gtk::Application::create("christian.hanner.hero");
    Gui myGui;
    Controller myController(&myGui);
    myGui.init(&myController);

    app->run(myGui);

    return 0;
}