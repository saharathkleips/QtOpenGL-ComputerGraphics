# PA3 - Moons (Saharath Kleips)
This program displays a planet orbiting around a central location with a moon that orbits the planet. Both the planet and the moon utilize the same mesh, but may act and transform independently of each other. In this program the moon will always orbit the planet no matter where the planet is, or what the planet is doing. Controls listed below showcase this interaction.

!(.screenshot.png "Screenshot")

## Table of Contents
+ [Program Usage](#program-usage)  
    - [Controls](#controls)  
    - [Context Menu](#context-menu)  
+ [Installation Instructions](#installation-instructions)  
+ [Build Instructions](#build-instructions)  

## Program Usage
###Controls
<table>
    <tbody>
        <tr>
            <th>Action</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>Keyboard - Up</td>
            <td>Rotate planet counter-clockwise</td>
        </tr>
        <tr>
            <td>Keyboard - Down</td>
            <td>Rotate planet clockwise</td>
        </tr>
        <tr>
            <td>Keyboard - Left</td>
            <td>Orbit planet counter-clockwise</td>
        </tr>
        <tr>
            <td>Keyboard - Right</td>
            <td>Orbit planet clockwise</td>
        </tr>
        <tr>
            <td>Keyboard - W</td>
            <td>Rotate moon counter-clockwise</td>
        </tr>
        <tr>
            <td>Keyboard - S</td>
            <td>Rotate moon clockwise</td>
        </tr>
        <tr>
            <td>Keyboard - A</td>
            <td>Orbit moon counter-clockwise</td>
        </tr>
        <tr>
            <td>Keyboard - D</td>
            <td>Orbit moon clockwise</td>
        </tr>
        <tr>
            <td>Keyboard - ESC</td>
            <td>Exit the program</td>
        </tr>
        <tr>
            <td>Mouse - Left Click</td>
            <td>Reverse the orbits of both objects</td>
        </tr>
        <tr>
            <td>Mouse - Right Click</td>
            <td>Create a popup context menu</td>
        </tr>
    </tbody>
</table>

###Context Menu
<table>
    <tbody>
        <tr>
            <th>Context Item</th>
            <th>Description</th>
        </tr>
            <td>Unpause / Pause</td>
            <td>Unpauses / pauses all object montion</td>
        <tr>
        </tr>
        <tr>
            <td>Exit Program</td>
            <td>Exit the program</td>
        </tr>
    </tbody>
</table>

## Installation Instructions
### Ubuntu 14.04 LTS
**g++ Install**
```
sudo apt-get install build-essential
```

**OpenGL Install**
```
sudo apt-get install libgl1-mesa-dev
```

**Qt 5.5 Install**
64-bit
```
wget http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-linux-x64-5.5.0-2.run
chmod +x qt-opensource-linux-x64-5.5.0-2.run
./qt-opensource-linux-x64-5.5.0-2.run
```
32-bit
```
wget http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-linux-x86-5.5.0.run
chmod +x qt-opensource-linux-x86-5.5.0.run
./qt-opensource-linux-x86-5.5.0.run
```
Click "Next," then click "Skip," make a note of your installation directory then click "Next," make sure all of the components are selected then click "Next," agree to the license agreement and then click "Next," then click "Install," wait for the wizard to finish to uncheck "Launch Qt Creator," and then lastly click "Finish."

**Set Up Development Environment**


## Build Instructions
```
TODO: Write build instructions
```