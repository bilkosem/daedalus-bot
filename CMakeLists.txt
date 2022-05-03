# CMakeList.txt : CMake project for daedalus-bot, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("daedalus-bot")

# Add source to this project's executable.
add_executable (daedalus-bot "daedalus-bot.cpp" "daedalus-bot.h")

# TODO: Add tests and install targets if needed.
