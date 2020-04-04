#include "gui.h"

#include <iostream>

Gui::Gui()
    : mBoxMain(Gtk::ORIENTATION_HORIZONTAL),
      mBoxL(Gtk::ORIENTATION_VERTICAL),
      mLabel("roof") {
    std::cout << "Gui constructor" << std::endl;

    // window
    set_title("t h e g u i");
    set_border_width(0);
    set_default_size(400, 200);

    // mButtonStart
    mButtonStart.set_label("start");
    mButtonStart.signal_clicked().connect(
        sigc::mem_fun(*this, &Gui::buttonStartClicked));

    // mButtonStop
    //    mButtonStop.set_size_request(30, 80);
    mButtonStop.set_label("stop");
    mButtonStop.signal_clicked().connect(
        sigc::mem_fun(*this, &Gui::buttonStopClicked));

    add(mBoxMain);
    mBoxMain.pack_start(mBoxL);
    mBoxMain.pack_start(mBoxR);
    mBoxL.pack_start(mButtonStart);
    mBoxL.pack_start(mButtonStop);
    mBoxR.pack_start(mLabel);
    mLabel.set_visible(true);
    show_all();
}

// void init(Controller* controller) {
//     this->mController = controller;
// }

void Gui::setText(std::string str) {
    mLabel.set_text(str);
};

void Gui::close() {
    hide();
}

void Gui::buttonStartClicked() {
    std::cout << "buttonStartClicked\n";
}

void Gui::buttonStopClicked() {
    std::cout << "buttonStopClicked\n";
}