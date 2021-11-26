// https://www.gtk.org/docs/language-bindings/cpp/
// https://docs.gtk.org/gtk4/class.Image.html
// https://www.freedesktop.org/software/gstreamer-sdk/data/docs/latest/gio/gio-GResource.html
// https://www.freedesktop.org/software/gstreamer-sdk/data/docs/latest/gio/glib-compile-resources.html

#include "tony.h"

Tony::Tony()
: m_image()
{
    gtk_image_set_from_resource(m_image, "/org/jmcb/Tony/tony.jpg")
}

Tony::~Tony()
{
}
