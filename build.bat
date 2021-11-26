cd discord-rpc\build
cmake .. -DENABLE_IO_THREAD=OFF -G "MinGW Makefiles"
mingw32-make.exe
cd ..\..
glib-compile-resources --generate-source --generate-header tony_gresource.xml
l
meson --buildtype=release build
ninja -C build
