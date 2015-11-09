# Bug Encounters / Error Fixes
[Return to README](README.md)  

## Table of Contents
+ [Not Found in Mesa Table OpenGL Error](#not-found-in-mesa-table-opengl-error)  

## "Not Found in Mesa Table OpenGL Error"
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

**Alternative Solution:**  
Download and install VMWare Workstation Player 12.  
Migrate your current virtual machine image and boot from VMWare.  
Install VMWare tools.  

**Segmentation Fault after Team Select:**
A very rare occurence happens after team select resulting in a segmentation fault.  
The segmentation fault is in QSignalMapper::map(QObject*) ()
This is an rare occurence and running the program again should bypass the issue.

