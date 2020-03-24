#include <chrono>
#include <iostream>

#include "controller.h"

int main() {
    std::cout << "woop" << std::endl;

    auto app = Gtk::Application::create("christian.hanner.hero");
    Gui myGui;
    Controller myController(&myGui);
    // Controller myController;
    myController.start();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    myController.stop();

    app->run(myGui);

    return 7;
}