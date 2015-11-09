#The type to build (application, library, subdirectories)
TEMPLATE = app  

#Directory of the executable / binary file
DESTDIR = ../bin/

#The name of the app / library
TARGET = AirHockey.exe

#QT libraries this project uses
QT += core gui opengl
QT += multimedia

#Necessary for Qt5 and above
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#Any external libraries this build uses
LIBS += -lassimp -lBulletDynamics -lBulletSoftBody -lBulletCollision -lLinearMath

#General project configuration options.
CONFIG += warn_on c++11

#Compiler flags
QMAKE_CXXFLAGS_WARD_ON += -Wall -pedantic

#Specifies the #include directories which should be searched when compiling the project.
INCLUDEPATH = ../src/ /usr/include/bullet

#A list of filenames of header (.h) files used when building the project.
HEADERS += \
    #3D
    ../src/3D/modelLoader.h \
    ../src/3D/renderable.h \
    ../src/3D/transform3d.h \
    ../src/3D/colorVertex.h \
    ../src/3D/uvVertex.h \
    #Controls
    ../src/Controls/camera3d.h \
    ../src/Controls/input.h \
    #Entity
    ../src/Entity/colorEntity.h \
    ../src/Entity/colorPhysicsEntity.h \
    ../src/Entity/uvEntity.h \
    ../src/Entity/uvPhysicsEntity.h \
    #GameObjects
    ../src/GameObjects/hockeyTable.h \
    ../src/GameObjects/hockeyPuck.h \
    ../src/GameObjects/hockeyPaddle.h \
    ../src/GameObjects/skybox.h \
    #UI
    ../src/UI/mainWindow.h \
    ../src/UI/oglWidget.h

#A list of source code files to be used when building the project.
SOURCES += \
    #3D
    ../src/3D/modelLoader.cpp \
    ../src/3D/transform3d.cpp \
    ../src/3D/colorVertex.cpp \
    ../src/3D/uvVertex.cpp \
    #Controls
    ../src/Controls/camera3d.cpp \
    ../src/Controls/input.cpp \
    #Entity
    ../src/Entity/colorEntity.cpp \
    ../src/Entity/colorPhysicsEntity.cpp \
    ../src/Entity/uvEntity.cpp \
    ../src/Entity/uvPhysicsEntity.cpp \
    #GameObjects
    ../src/GameObjects/hockeyTable.cpp \
    ../src/GameObjects/hockeyPuck.cpp \
    ../src/GameObjects/hockeyPaddle.cpp \
    ../src/GameObjects/skybox.cpp \
    #UI
    ../src/UI/mainWindow.cpp \
    ../src/UI/oglWidget.cpp \
    #Main
    ../src/main.cpp

#A list of resource (.qrc / .rc) files to be included in the final project.
RESOURCES += \
    shader_resource.qrc
