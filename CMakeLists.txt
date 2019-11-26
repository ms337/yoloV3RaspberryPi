cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
project( Project )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
include_directories( ${Qt5_INCLUDE_DIRS} )

add_executable( Main.out Main.cpp controller/FeedController.cpp controller/FeedController.h controller/Client.cpp controller/Client.h view/mainwindow.h view/mainwindow.cpp view/mainwindow.ui view/objectlist.h view/objectlist.cpp view/zonelist.h view/zonelist.cpp)
target_link_libraries( Main.out ${OpenCV_LIBS} Qt5::Core Qt5::Gui Qt5::Widgets)
