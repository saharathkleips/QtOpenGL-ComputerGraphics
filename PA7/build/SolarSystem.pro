#The type to build (application, library, subdirectories)
TEMPLATE = app  

#The name of the app / library
TARGET = ../bin/SolarSystem.exe

#QT += to add libraries this project uses
QT += core gui opengl

#Necessary for Qt5 and above
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#Any external libraries this build uses
LIBS += -lassimp

#Compiler settings
CONFIG += c++11

#Compiler flags
QMAKE_CXXFLAGS_WARD_ON += -Wall -pedantic

# Input
# HEADERS += first_file.h second_file.h
# SOURCES += first_file.cpp second_file.cpp
HEADERS += \
    ../src/camera3d.h \
    ../src/input.h \
    ../src/mainWindow.h \
    ../src/modelLoader.h \
    ../src/oglWidget.h \
    ../src/renderable.h \
    ../src/skybox.h \
    ../src/transform3d.h \
    ../src/vertex.h \
    #PLANETS
    ../src/Planets/planet.h \
    ../src/Planets/sun.h \
    ../src/Planets/mercury.h \
    ../src/Planets/venus.h \
    ../src/Planets/earth.h \
    ../src/Planets/mars.h \
    ../src/Planets/jupiter.h \
    ../src/Planets/saturn.h \
    ../src/Planets/uranus.h \
    ../src/Planets/neptune.h \
    ../src/Planets/pluto.h \
    ../src/Planets/earthMoon.h


SOURCES += \
    ../src/camera3d.cpp \
    ../src/input.cpp \
    ../src/main.cpp \
    ../src/mainWindow.cpp \
    ../src/modelLoader.cpp \
    ../src/oglWidget.cpp \
    ../src/skybox.cpp \
    ../src/transform3d.cpp \
    ../src/vertex.cpp \
    #PLANETS
    ../src/Planets/planet.cpp \
    ../src/Planets/sun.cpp \
    ../src/Planets/mercury.cpp \
    ../src/Planets/venus.cpp \
    ../src/Planets/earth.cpp \
    ../src/Planets/mars.cpp \
    ../src/Planets/jupiter.cpp \
    ../src/Planets/saturn.cpp \
    ../src/Planets/uranus.cpp \
    ../src/Planets/neptune.cpp \
    ../src/Planets/pluto.cpp \
    ../src/Planets/earthMoon.cpp

# Resource files are .qrc - they will be compiled into the binary
RESOURCES += \
    shader_resource.qrc \
    texture_resource.qrc
