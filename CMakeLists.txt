cmake_minimum_required(VERSION 3.7)
project(final)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.cpp Game.h Player.cpp Player.h Team.cpp Team.h HumanPlayer.cpp HumanPlayer.h Card.cpp Card.h Trick.cpp Trick.h ComputerPlayer.cpp ComputerPlayer.h Color.h Contract.h Contract.cpp Deal.cpp Deal.h)
add_executable(final ${SOURCE_FILES})