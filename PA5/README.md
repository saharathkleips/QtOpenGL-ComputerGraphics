# PA5 - Assimp Model Loading (Ben Nicholes, Denis Morozov, Saharath Kleips)
Sample program that displays the usage of Assimp model loading.

**Note** Possibly broken on most machines.

![](.screenshot.png "Screenshot")

## Table of Contents
+ [Program Usage](#program-usage)  
    - [Controls](#controls)
+ [Installation Instructions](#installation-instructions)  
    - [Ubuntu 14.04 LTS](#ubuntu-1404-lts)
    - [Ubuntu 12.04 LTS](#ubuntu-1204-lts)
    - [OSX](#osx)
    - [Windows](#windows)
+ [Build Instructions](#build-instructions)  
+ [Bug Encounters / Error Fixes](#bug-encounters--error-fixes)
    - [Not Found in Mesa Table OpenGL Error](#not-found-in-mesa-table-opengl-error)

## Program Usage


###Controls
<table>
    <tbody>
        <tr>
            <th></th>
            <th></th>
        </tr>
        <tr>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td></td>
            <td></td>
        </tr>
    </tbody>
</table>

## Installation Instructions
### Ubuntu 14.04 LTS
Tested with a clean install of Ubuntu 14.04 x64 LTS on VirtualBox 5.0.2r102096 with Guest Additions installed and Windows 8.1 x64 host.  

**g++ Install**
```
sudo apt-get install build-essential
```

**OpenGL Install**
```
sudo apt-get install libgl1-mesa-dev
```

**Qt 5.5 Install**  
Add the Qt5.5 PPAs by [Stephan Banner](https://launchpad.net/~beineri) and then install the latest Qt files.
```
sudo apt-add-repository ppa:beineri/opt-qt55-trusty
sudo apt-get update
sudo apt-get install qt-latest
```

**Set Up Development Environment**  
Your `qtchooser` should now list opt-qt55 as an option.
```
qtchooser --list-versions
```
Add the environment variables to your bashrc file.
```
echo 'export QT_SELECT=opt-qt55' >> ~/.bashrc
```
Restart your terminal.

### Ubuntu 12.04 LTS
Tested with a clean install of Ubuntu 12.04 x64 LTS on VirtualBox 5.0.2r102096 with Guest Additions installed and Windows 8.1 x64 host.  

**g++ Install**
```
sudo apt-get install build-essential
```

**OpenGL Install**
```
sudo apt-get install libgl1-mesa-dev
```

**Qt 5.5 Install**  
Add the Qt5.5 PPAs by [Stephan Banner](https://launchpad.net/~beineri) and then install the latest Qt files.
```
sudo apt-add-repository ppa:beineri/opt-qt55
sudo apt-get update
sudo apt-get install qt-latest
```

**Set Up Development Environment**  
Add the environment variables to your bashrc file.
```
cd /opt/qt55/bin
./qt55-env.sh
```
Restart your terminal.

### OSX

Install VirtualBox. Go get Ubuntu. Brew instructions unavailable.

### Windows

Really?

## Build Instructions
Navigate to the `build` directory.
```
qmake
make
```
Navigate to the `bin` directory.
```
Default model:
./PA5.exe

Custom model:
./PA5.exe {$PATH}
ex: ./PA5.exe ../build/models/suzanne.obj
```

Convenince Copy/Paste from the `build` directory:
```
qmake; make; cd ../bin; ./PA5.exe; cd ../build
make; cd ../bin; ./PA5.exe; cd ../build
```

**Note:** `qmake` does not need to be run before `make` everytime, only when the `.pro` file has been changed. Otherwise, simply `qmake` once and `make` from there on out.

## Bug Encounters / Error Fixes
### "Not Found in Mesa Table OpenGL Error"
**Found on:**  
VirtualBox 5.0.2r102096  
Host: Windows 7 Ultimate x64  
Guest: Ubuntu 14.04 LTS x64 (Guest Additions Installed)

VirtualBox 5.0.2r102096  
Host: Windows 8.1 x64  
Guest: Ubuntu 12.04 LTS x64 (Guest Additions Installed)  
**Error:**  
Check `glxinfo`:
```
glxinfo | grep OpenGL
```
glxinfo requires `mesa-utils` installed using:
```
sudo apt-get install mesa-utils
```
The output should resemble the following and contain Chromium and not Mesa:
```
OpenGL vendor string: Humper
OpenGL renderer string: Chromium
OpenGL version string: 2.1 Chromium
OpenGL shading language version string: 4.50 NVIDIA
OpenGL extensions:
```
**Solution:**  
A fix is disabling 3D Hardware Acceleration on your VirtualBox.  
After disabling, your glxinfo should look similar to:
```
OpenGL vendor string: VMWare, Inc.
OpenGL renderer string: Gallium 0.4 on llvmpipe (LLVM 3.6 256 bits)
OpenGL version string: 3.0 Mesa 10.5.2
OpenGL shading language version string: 1.30
OpenGL context flags: (none)
OpenGL extensions:
```
Note: The version string should now contain Mesa rather than Chromium.