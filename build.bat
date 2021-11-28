cd discord-rpc
mkdir build
cd build
cmake .. -DENABLE_IO_THREAD=OFF -G "MinGW Makefiles"
mingw32-make.exe
cd ..\..
glib-compile-resources --generate-source --generate-header tony_gresource.xml
meson --buildtype=release build
ninja -C build
