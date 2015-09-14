#The type to build (application, library, subdirectories)
TEMPLATE = app  
#The name of the app / library
TARGET = ../bin/qtGL

#QT is neceessary to indicate what libraries this project uses
#Include the GUI framework
QT += core gui
#Include the OpenGL framework
QT += opengl
#Necessary for Qt5 and above
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += .

# Input
# HEADERS += first_file.h second_file.h
# SOURCES += first_file.h second_file.h
HEADERS += \
    ../src/glWidget.h \
    ../src/vertex.h \
    ../src/sg_vertexes.h \
    ../src/transform3d.h \
    ../src/camera3d.h
SOURCES += \
    ../src/glWidget.cpp \
    ../src/vertex.cpp \
    ../src/transform3d.cpp \
    ../src/camera3d.cpp \
    ../src/main.cpp

# Resource files are .qrc
RESOURCES += \
    resources.qrc