#pragma once

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>

#include "controller.h"

class Controller;

class Gui : public Gtk::Window {
   public:
    Gui();
    void init(Controller* contoller);
    void setText(std::string str);
    void close();

   private:
    void buttonStartClicked();
    void buttonStopClicked();
    Gtk::Box mBoxMain, mBoxL, mBoxR;
    Gtk::Button mButtonStart, mButtonStop;
    Gtk::Label mLabel;
    Controller* mController;
};
