#include "gui.h"

#include <iostream>

Gui::Gui() : mBox(Gtk::ORIENTATION_VERTICAL), mLabel("roof") {
    std::cout << "Gui constructor" << std::endl;

    // Set title and border of the window
    set_title("t h e g u i");
    set_border_width(0);
    set_default_size(200, 200);

    add(mBox);
    mBox.pack_start(mLabel);
    mLabel.set_visible(true);
    show_all();
}

void Gui::setText(std::string str) {
    mLabel.set_text(str);
};

void Gui::close() {
    hide();
}
