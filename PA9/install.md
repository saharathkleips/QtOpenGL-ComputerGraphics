# Installation Instructions
[Return to README](README.md)  
**It is recommended that you use Ubuntu 14.04 LTS.**  

## Table of Contents
+ [Ubuntu 14.04 LTS](#ubuntu-1404-lts)
+ [Ubuntu 12.04 LTS](#ubuntu-1204-lts)
+ [Other Linux Distrbutions](#other-linux-distributions)
+ [OSX](#osx)
+ [Windows](#windows)

## Ubuntu 14.04 LTS
Tested with a clean install of Ubuntu 14.04 x64 LTS on VMWare Workstation Player with VMWare Tools installed and Windows 7 Ultimate x64 host.

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

**Assimp Install**
```
sudo apt-get install libassimp-dev
```

## Ubuntu 12.04 LTS
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

**WARNING: Potentially Unsupported**  
**Assimp Install**
```
sudo apt-get install libassimp-dev
```

## Other Linux Distributions
Qt can be built from [source code](https://wiki.qt.io/Building_Qt_5_from_Git), and is most likely available in your distribution's repositories. However, an easy way of getting the latest Qt is using the official installer:

Download the [Qt Installer](http://www.qt.io/download-open-source/). Give it executable permissions and run as administrator.
```
chmod +x qt-unified-linux-x64-2.0.2-2-online.run
sudo ./qt-unified-linux-x64-2.0.2-2-online.run
```
Add the Qt binaries to PATH environment variable (assumes default install location of /opt/Qt/:
```
echo "PATH=\$PATH:/opt/Qt/Tools/QtCreator/bin:/opt/Qt/5.5/gcc_64/bin" >> ~/.bashrc
source ~/.bashrc
```

... and that's it!

## OSX
Install VirtualBox. Go get Ubuntu. Brew instructions unavailable.  

## Windows  
Really?