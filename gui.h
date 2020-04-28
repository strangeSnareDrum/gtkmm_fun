#pragma once

#include <gtkmm/adjustment.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/label.h>
#include <gtkmm/scale.h>
#include <gtkmm/window.h>

#include "action_box.h"
#include "controller.h"

class Controller;

class Gui : public Gtk::Window {
   public:
    Gui();
    ~Gui();
    void init(Controller* contoller);
    void setText(std::string str);

   private:
    // inherited gtkmm methods
    bool on_delete_event(GdkEventAny* any_event) override;

    void adjustmentValueChanged();
    void buttonStartClicked();
    void buttonPauseClicked();
    void buttonStopClicked();

    ActionBox mActionBox;

    Glib::RefPtr<Gtk::Adjustment> mAdjustment;
    Gtk::Box mBoxMain, mBoxL, mBoxR;
    Gtk::Button mButtonStart, mButtonPause, mButtonStop;
    Gtk::Scale mScaleUpdateSpeed;
    Gtk::Label mLabel;
    Controller* mController;
};
