# PA2 - Interaction: Menus, Keyboard, and Mouse
## Saharath Kleips

This project displays various interaction techniques utilizing GLUT.
The cube starts off translating in an elliptical path, to start the rotation, enable it within the menu (instructions found below).
Controls for this program are as follows:
 Keyboard 'a' / 'd' keys: Rotates the cube clockwise / counter-clockwise respectively.
 Left Mouse Click: Switches the rotation of the cube.
 Right Mouse Click: Opens up a menu.

 Menu Items:
 Rotate: Enables / Disables the rotation of the cube.
 Exit: Exits the program.

A simple example of interactions in OpenGL
========================================

Building This Example
---------------------

*This example requires GLM*
*On ubuntu it can be installed with this command*

>$ sudo apt-get install libglm-dev

*On a Mac you can install GLM with this command(using homebrew)*
>$ brew install glm

To build this example just 

>$ cd build
>$ make

*If you are using a Mac you will need to edit the makefile in the build directory*

The excutable will be put in bin

Additional Notes For OSX Users
------------------------------

Ensure that the latest version of the Developer Tools is installed.
