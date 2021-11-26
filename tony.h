// https://www.gtk.org/docs/language-bindings/cpp/

#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm/image.h>
#include <gtkmm/window.h>

class Tony : public Gtk::Window
{

public:
    Tony();
    virtual ~Tony();

protected:
    //Member widgets:
    Gtk::Image m_image;
};

#endif
