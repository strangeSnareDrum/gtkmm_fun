#pragma once

#include <gtkmm/drawingarea.h>

#include <tuple>

class Dot {
   public:
    Dot();
    ~Dot();
    void setPosition(const float x, const float y);
    void getPosition(float* x, float* y);

   private:
    float mRadius;
    float mX, mY;
};

class ActionBox : public Gtk::DrawingArea {
   public:
    ActionBox();
    ~ActionBox();

   protected:
    // Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

   private:
    Dot mDot;
    float mLineWidth;
};