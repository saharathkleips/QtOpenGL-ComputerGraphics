# Build Instructions
[Return to README](#README.md)  

## Table of Contents
+ [Build Executable](#build-executable)
+ [Execute Program](#execute-program)
+ [Clean Compilation Files](#clean-compilation-files)  

## Build Executable
Navigate to the `build` directory.
```
qmake
make
```  
**Note:** `qmake` does not need to be run before `make` everytime, only when the `.pro` file has been changed. Otherwise, simply `qmake` once and `make` from there on out.  

## Execute Program
Navigate to the `bin` directory.
```
./SolarSystem.exe
```  

## Clean Compilation Files
```
make clean
```