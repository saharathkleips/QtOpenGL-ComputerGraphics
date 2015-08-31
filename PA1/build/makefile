# Linux
CC=g++
LIBS= -lglut -lGLEW -lGL

# For Macs uncomment the next line and comment out the previous one
#CC=clang++
#LIBS=  -framework OpenGL -framework GLUT -framework Cocoa -lGLEW -stdlib=libc++
# Assuming you want to use a recent compiler

# Compiler flags
CXXFLAGS= -g -Wall -std=c++0x

all: ../bin/Matrix.out

../bin/Matrix.out: ../src/main.cpp ../src/ShaderLoader.o
	$(CC) $(CXXFLAGS) ../src/main.cpp ../src/ShaderLoader.o -o ../bin/Matrix.out $(LIBS)

../bin/ShaderLoader.o: ../src/ShaderLoader.cpp ../src/ShaderLoader.h
	$(CC) $(CXXFLAGS) ../src/ShaderLoader.cpp -c -o ../bin/ShaderLoader.o $(LIBS)

clean: 
	rm -rf *.o ../bin/Matrix.out