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
    ../src/modelLoader.h \
    ../src/oglWidget.h \
    ../src/renderable.h \
    ../src/transform3d.h \
    ../src/vertex.h \
    #PLANETS
    ../src/Planets/planet.h \
    ../src/Planets/planetSun.h \
    ../src/Planets/planetEarth.h \
    ../src/Planets/planetMars.h


SOURCES += \
    ../src/camera3d.cpp \
    ../src/input.cpp \
    ../src/main.cpp \
    ../src/modelLoader.cpp \
    ../src/oglWidget.cpp \
    ../src/transform3d.cpp \
    ../src/vertex.cpp \
    #PLANETS
    ../src/Planets/planet.cpp \
    ../src/Planets/planetSun.cpp \
    ../src/Planets/planetEarth.cpp \
    ../src/Planets/planetMars.cpp

# Resource files are .qrc - they will be compiled into the binary
RESOURCES += \
    shader_resource.qrc \
    texture_resource.qrc
