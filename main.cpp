#include "action_box.h"
#include "controller.h"
#include "gui.h"

int main() {
    auto app = Gtk::Application::create("strange.snare.drum");
    Gui myGui;
    Controller myController(&myGui);
    myGui.init(&myController);

    app->run(myGui);

    return 0;
}