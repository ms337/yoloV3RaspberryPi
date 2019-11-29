cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -ldl")
project( Project )
find_package( OpenCV REQUIRED )
 
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets PrintSupport REQUIRED)
include_directories( ${Qt5_INCLUDE_DIRS} )

add_executable( Main.out Main.cpp sqlite3.c sqlite3.h sqlite3ext.h model/ModelOutput.cpp model/ModelOutput.h model/DatabaseReader.h model/DatabaseReader.cpp model/DatabaseWriter.h model/DatabaseWriter.cpp model/Zone.h model/Zone.cpp model/ZonesCollection.cpp model/ZonesCollection.h  controller/FeedController.cpp controller/FeedController.h  controller/ZonesController.cpp controller/ZonesController.h  view/mainwindow.h view/mainwindow.cpp view/mainwindow.ui view/objectlist.h view/objectlist.cpp view/zonelist.h view/zonelist.cpp view/histogram.h view/histogram.cpp view/histogram.ui view/heatmap.h view/heatmap.cpp view/heatmap.ui view/qcustomplot.h view/qcustomplot.cpp)
target_link_libraries( Main.out ${OpenCV_LIBS} Qt5::Core Qt5::Gui Qt5::Widgets ${SQLITE3_LIBRARIES})
