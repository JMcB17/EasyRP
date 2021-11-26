// https://www.gtk.org/docs/language-bindings/cpp/

#include "config.hpp"
#include "discord.hpp"
#include "tony.hpp"
#include <chrono>
#include <csignal>
#include <thread>
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
    // define when to shutdown
    signal(SIGINT, Shutdown);
    signal(SIGTERM, Shutdown);
#ifdef SIGBREAK
    signal(SIGBREAK, Shutdown);
#endif

    // main config instance
    config_t config;
    config.update();

    // start discord-rpc
    initDiscord(config.client_id);

    auto app = Gtk::Application::create(argc, argv, "org.jmcb.easyrp");
    Tony tony;
    return app->run(tony);

    // loop to keep program running also to check for updated config
    while (true) {
        config.update();
        if (config.changed) {
            // print and set variables for the presence
            config.print();
            updatePresence(&config);
            config.changed = false;
        }
        refreshDiscord();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
