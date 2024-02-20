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
    include/helpcommandswidget.hpp
    include/commanditem.hpp
    include/commandmodel.hpp

)

set(MATH_WIDGETS
    include/mathWidgets/add.hpp include/mathWidgets/add.cpp
    include/mathWidgets/sub.hpp include/mathWidgets/sub.cpp
    include/mathWidgets/mult.hpp include/mathWidgets/mult.cpp
    include/mathWidgets/div.hpp  include/mathWidgets/div.cpp
)

set(SOURCES
    src/main.cpp
    src/logindialog.cpp
    src/mainwindow.cpp
    src/namevalidator.cpp
    src/helpcommandswidget.cpp
    src/commanditem.cpp
    src/commandmodel.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(chatBot
  ${SOURCES}
  ${INCLUDES}
  ${MATH_WIDGETS}
  resources/pictures.qrc

)
target_link_libraries(chatBot Qt6::Core Qt6::Gui Qt6::Widgets)

