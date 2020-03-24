#pragma once

#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>

#include <string>

class Gui : public Gtk::Window {
   public:
    Gui();
    void setText(std::string str);
    void close();

   private:
    Gtk::Box mBox;
    Gtk::Label mLabel;
};
