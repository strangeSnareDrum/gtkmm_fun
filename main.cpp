#include <chrono>
#include <iostream>

#include "controller.h"

int main() {
    auto app = Gtk::Application::create("strange.snare.drum");
    Gui myGui;
    Controller myController(&myGui);
    myGui.init(&myController);

    app->run(myGui);

    return 0;
}