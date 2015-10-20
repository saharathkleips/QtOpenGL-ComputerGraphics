#The type to build (application, library, subdirectories)
TEMPLATE = app  

#Directory of the executable / binary file
DESTDIR = ../bin/

#The name of the app / library
TARGET = Bullet.exe

#QT libraries this project uses
QT += core gui opengl

#Necessary for Qt5 and above
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#Any external libraries this build uses
LIBS += -lassimp -I/usr/include/bullet -lBulletDynamics -lBulletSoftBody -lBulletCollision -lLinearMath

#General project configuration options.
CONFIG += warn_on c++11

#Compiler flags
QMAKE_CXXFLAGS_WARD_ON += -Wall -pedantic

#Specifies the #include directories which should be searched when compiling the project.
INCLUDEPATH = ../src/

#A list of filenames of header (.h) files used when building the project.
HEADERS += \
    #3D
    ../src/3D/modelLoader.h \
    ../src/3D/renderable.h \
    ../src/3D/transform3d.h \
    ../src/3D/vertex.h \
    #Controls
    ../src/Controls/camera3d.h \
    ../src/Controls/input.h \
    #Entity
    ../src/Entity/baseEntity.h \
    #UI
    ../src/UI/mainWindow.h \
    ../src/UI/oglWidget.h

#A list of source code files to be used when building the project.
SOURCES += \
    #3D
    ../src/3D/modelLoader.cpp \
    ../src/3D/transform3d.cpp \
    ../src/3D/vertex.cpp \
    #Controls
    ../src/Controls/camera3d.cpp \
    ../src/Controls/input.cpp \
    #Entity
    ../src/Entity/baseEntity.cpp \
    #UI
    ../src/UI/mainWindow.cpp \
    ../src/UI/oglWidget.cpp \
    #Main
    ../src/main.cpp

#A list of resource (.qrc / .rc) files to be included in the final project.
RESOURCES += \
    shader_resource.qrc
