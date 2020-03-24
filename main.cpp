#include <iostream>

#include "controller.h"

int main() {
    std::cout << "woop" << std::endl;

    auto app = Gtk::Application::create("christian.hanner.hero");
    Gui myGui;
    Controller myController(&myGui);
    // Controller myController;
    myController.start();
    myController.inc();
    myController.inc();
    app->run(myGui);

    return 7;
}