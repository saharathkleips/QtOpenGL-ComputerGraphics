#The type to build (application, library, subdirectories)
TEMPLATE = app  

#The name of the app / library
TARGET = ../bin/PA6.exe

#QT += to add libraries this project uses
#Include the GUI framework
QT += core gui

#Include the OpenGL framework
QT += opengl

#Necessary for Qt5 and above
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -lassimp

QMAKE_CXXFLAGS_WARD_ON += -Wall -pedantic

# Input
# HEADERS += first_file.h second_file.h
# SOURCES += first_file.cpp second_file.cpp
HEADERS += \
    ../src/camera3d.h \
    ../src/capsule.h \
    ../src/oglWidget.h \
    ../src/renderable.h \
    ../src/transform3d.h \
    ../src/vertex.h

SOURCES += \
    ../src/camera3d.cpp \
    ../src/capsule.cpp \
    ../src/main.cpp \
    ../src/oglWidget.cpp \
    ../src/transform3d.cpp \
    ../src/vertex.cpp

# Resource files are .qrc - they will be compiled into the binary
RESOURCES += \
    resources.qrc
