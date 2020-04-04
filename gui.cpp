#include "gui.h"

#include <iostream>

Gui::Gui()
    : mBoxMain(Gtk::ORIENTATION_HORIZONTAL),
      mBoxL(Gtk::ORIENTATION_VERTICAL),
      mLabel("") {
    std::cout << "Gui constructor" << std::endl;

    // window
    set_title("t h e g u i");
    set_border_width(0);
    set_default_size(400, 200);

    // mButtonStart
    mButtonStart.set_label("start");
    mButtonStart.signal_clicked().connect(
        sigc::mem_fun(*this, &Gui::buttonStartClicked));

    // mButtonPause
    mButtonPause.set_label("pause");
    mButtonPause.signal_clicked().connect(
        sigc::mem_fun(*this, &Gui::buttonPauseClicked));

    // mButtonStop
    //    mButtonStop.set_size_request(30, 80);
    mButtonStop.set_label("stop");
    mButtonStop.signal_clicked().connect(
        sigc::mem_fun(*this, &Gui::buttonStopClicked));

    add(mBoxMain);
    mBoxMain.pack_start(mBoxL, Gtk::PACK_SHRINK, 10);
    mBoxMain.pack_start(mBoxR);
    mBoxL.pack_start(mButtonStart, Gtk::PACK_EXPAND_WIDGET, 10);
    mBoxL.pack_start(mButtonPause, Gtk::PACK_EXPAND_WIDGET, 10);
    mBoxL.pack_start(mButtonStop, Gtk::PACK_EXPAND_WIDGET, 10);
    mBoxR.pack_start(mLabel);
    mLabel.set_visible(true);
    show_all();
}

Gui::~Gui() {
    std::cout << "Gui destructor\n";
}

void Gui::init(Controller* controller) {
    mController = controller;
}

void Gui::setText(std::string str) {
    mLabel.set_text(str);
};

bool Gui::on_delete_event(GdkEventAny* any_event) {
    std::cout << "void Gui::on_delete_event()\n";
    mController->stop();
    hide();
    return true;
}

void Gui::buttonStartClicked() {
    std::cout << "void Gui::buttonStartClicked()\n";
    mController->start();
}

void Gui::buttonPauseClicked() {
    std::cout << "void Gui::buttonPauseClicked()\n";
    mController->pause();
}

void Gui::buttonStopClicked() {
    std::cout << "void Gui::buttonStopClicked()\n";
    mController->stop();
}