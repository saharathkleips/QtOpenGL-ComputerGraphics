# Linux
CC=g++
LIBS= -lglut -lGLEW -lGL

# OSX
#CC=clang++
#LIBS=  -framework OpenGL -framework GLUT -framework Cocoa -lGLEW


# Compiler flags
CXXFLAGS= -g -Wall -std=c++0x

all: ../bin/Pass

../bin/Pass: ../src/main.cpp
	$(CC) $(CXXFLAGS) ../src/main.cpp -o ../bin/Pass $(LIBS)

