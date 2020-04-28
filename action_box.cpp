#include "action_box.h"

#include <cairomm/context.h>
#include <glibmm/main.h>

#include <iostream>

Dot::Dot() : mRadius(5) {
    std::cout << "Dot constructor" << std::endl;
}

Dot::~Dot() {
    std::cout << "Dot destructor" << std::endl;
}

void Dot::setPosition(const float x, const float y) {
    mX = x;
    mY = y;
}

void Dot::getPosition(float* x, float* y) {
    *x = mX;
    *y = mY;
}

ActionBox::ActionBox() : mLineWidth(10) {
    std::cout << "ActionBox constructor" << std::endl;
}

ActionBox::~ActionBox() {
    std::cout << "ActionBox destructor" << std::endl;
}

bool ActionBox::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    // scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
    // the center of the window
    cr->scale(width, height);
    cr->translate(0.5, 0.5);
    cr->set_line_width(mLineWidth);

    cr->save();
    cr->set_source_rgba(0.337, 0.612, 0.117, 0.9);  // green
    cr->paint();
    cr->restore();
    double m_radius = 0.2;
    cr->arc(0, 0, m_radius, 0, 2 * M_PI);

    cr->save();
    cr->set_source_rgba(1.0, 1.0, 1.0, 0.8);
    cr->fill_preserve();
    cr->restore();
    // cr->stroke_preserve();
    // cr->clip();
    return true;
}