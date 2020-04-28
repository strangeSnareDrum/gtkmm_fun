#include "action_box.h"
#include "controller.h"
#include "gui.h"

int main() {
    auto app = Gtk::Application::create("strange.snare.drum");
    Gtk::Window win;
    win.set_title("This little twinky");
    ActionBox aBox;
    win.add(aBox);
    aBox.show();
    // Gui myGui;
    // Controller myController(&myGui);
    // myGui.init(&myController);

    // app->run(myGui);
    app->run(win);

    return 0;
}