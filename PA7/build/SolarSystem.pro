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

#compiler flags
QMAKE_CXXFLAGS_WARD_ON += -Wall -pedantic

# Input
# HEADERS += first_file.h second_file.h
# SOURCES += first_file.cpp second_file.cpp
HEADERS += \

SOURCES += \
    ../src/main.cpp

# Resource files are .qrc - they will be compiled into the binary
RESOURCES += \
    resources.qrc
