cd discord-rpc\build
cmake .. -DENABLE_IO_THREAD=OFF -G "MinGW Makefiles"
mingw32-make.exe
cd ..\..
meson --buildtype=release build
ninja -C build
