cmake_minimum_required(VERSION 3.7)
project(BridgeGame)

set(wxWidgets_ROOT_DIR </usr/local/include/wx-3.0>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.cpp Game.h Player.cpp Player.h Team.cpp Team.h HumanPlayer.cpp HumanPlayer.h Card.cpp Card.h Trick.cpp Trick.h ComputerPlayer.cpp ComputerPlayer.h Color.h Contract.h Contract.cpp Deal.cpp Deal.h misc.h CardValue.h)
add_executable(BridgeGame ${SOURCE_FILES})
set_target_properties(BridgeGame PROPERTIES COMPILE_DEFINITIONS "${_gui_flag};${wxWidgets_DEFINITIONS};_WCHAR_H_CPLUSPLUS_98_CONFORMANCE_")

target_link_libraries(BridgeGame ${wxWidgets_LIBRARIES})
