# PA11 - Labyrinth (Ben Nicholes, Denis Morozov, Saharath Kleips)
This project showcases a physics-based labyrinth game. A random labyrinth and environment will be generated every time you play the game, for maximum replayability. The game starts to get laggy at 10,000 cells on a mid-high end graphics card, so we've scaled the maze to 900 to ensure even the most modest of toasters can run the game. While the finished product is quite nice, a lot of sacrifices were made to the codebase. And as a result, this project should not be the starting / reference point for any future OpenGL/C++ projects.  
![](TitleScreen.png "Screenshot")

## Notes
+ 2 ball play is default.
+ GStreamer is required for audio to work, see Installation Instructions.

## Extra Credit
+ Background Music
+ Main Menu Screen
+ Win Screen
+ Procedural Maze Generation
+ Random Cell Texture Generation
+ Multiple Environments
+ Multiple Levels
+ Multiple Balls
+ Game Restart
+ Scales to Any Resolution


## Table of Contents
+ [Instructions](#instructions)
+ [Controls](#controls)
+ [Installation Instructions](install.md)  
+ [Build Instructions](build.md)  
+ [Bug Encounters / Error Fixes](bugs.md)

##Instructions
When the game starts you will be shown a title screen. The title screen provides options to start a game or to exit. The settings have currently been disabled. Pressing play will cause a random maze and environment to load. Depending on the specs of your machine, this can take a couple seconds.  
![](TitleScreen.png "Title Screen")  
Once you start a game tilt the board to guide the balls toward the hole. Space may be used to reset the camera incase you off center it.  
![](GameScreen.png "Game Screen")  
If you manage to actually sit through and win the game, you'll be treated with a special victory screen! You can then choose to restart the game, and play on a new maze, or quit by selecting the menu options.  

##Controls
Player Controls
<table>
    <tbody>
    <tr>
        <td>Right Arrow Key</td>
        <td>Tilt Board to the right.</td>
    </tr>
    <tr>
        <td>Left Arrow</td>
        <td>Tilt Board to the left.</td>
    </tr>
    <tr>
        <td>Up Arrow</td>
        <td>Tilt Board up.</td>
    </tr>
    <tr>
        <td>Down Arrow</td>
        <td>Tilt Board Down</td>
    </tr>
    </tbody>
</table>
Program Controls
<table>
    <tbody>
    <tr>
        <th>Action</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>RMB + mouse movement</td>
        <td>Rotate camera</td>
    </tr>
    <tr>
        <td>Space</td>
        <td>Snap camera to starting position</td>
    <tr>
        <td>Q</td>
        <td>Move camera down</td>
    </tr>
    <tr>
        <td>E</td>
        <td>Move camera up</td>
    </tr>
    <tr>
        <td>W</td>
        <td>Move camera forward</td>
    </tr>
    <tr>
        <td>A</td>
        <td>Move camera left</td>
    </tr>
    <tr>
        <td>S</td>
        <td>Move camera backwards</td>
    </tr>
    <tr>
        <td>D</td>
        <td>Move camera right</td>
    </tr>
    <tr>
        <td>Ctrl + P</td>
        <td>Pause Game</td>
    </tr>
    <tr>
        <td>Ctrl + R</td>
        <td>Restart Game</td>
    </tr>
    <tr>
        <td>Ctrl + Q</td>
        <td>Quit the Program</td>
    </tr>
    </tbody>
</table>
