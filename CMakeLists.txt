cmake_minimum_required(VERSION 3.14)

project(chatBot LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDES
    include/logindialog.hpp
    include/mainwindow.hpp
    include/namevalidator.hpp
    include/commands.hpp
    include/helpcommandsmodel.hpp
    include/helpcommandswidget.hpp

)

set(SOURCES
    src/main.cpp
    src/logindialog.cpp
    src/mainwindow.cpp
    src/namevalidator.cpp
    src/helpcommandsmodel.cpp
    src/helpcommandswidget.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(chatBot
  ${SOURCES}
  ${INCLUDES}
  resources/pictures.qrc
)
target_link_libraries(chatBot Qt6::Core Qt6::Gui Qt6::Widgets)

