# PA11 - Labyrinth Hockey (Ben Nicholes, Denis Morozov, Saharath Kleips)
This project showcases a physics-based labyrinth game. 
![](.screenshot.png "Screenshot")

## Notes
+ 2 ball play is default.
+ GStreamer is required for audio to work, see Installation Instructions.

## Extra Credit
+ Background Music
+ Main Menu
+ Random Maze Generation
+ Random texture generation
+ Multiple Levels
+ Game Restart
+ Win Screen


## Table of Contents
+ [Instructions](#instructions)
+ [Controls](#controls)
+ [Installation Instructions](install.md)  
+ [Build Instructions](build.md)  
+ [Bug Encounters / Error Fixes](bugs.md)

##Instructions
When first starting up the game you are presented with the game's title screen as shown below. You may also change the resolution of the game by dragging the window at the corners.  
![](.TitleScreen.png "Title Screen")  
Here you are allowed to select from Single Player (disabled) and Versus game modes, as well as the option to exit the game. Upon selecting either "Single Player" or "Versus Mode" you will be presented with the Team Select Screen as shown below.  
![](.TeamSelectScreen.png "Team Select Screen")  
All 30 of your favorite NHL teams may be selected to play as and against! Clicking on a team's logo will select the first player's team, another click on a team's logo will select the second player's team. The game will then begin with the default Player 2 Perspective shown below. Note there is a possiblity for the game to run into a segmentation fault after selecting two teams. Simply re-run the game until it works, trust us, it works. More information on the bug can be found in bugs.md.  
![](.GameScreen.png "Game Screen")  
Here each player may control their respective paddles and attempt to hit the puck into the opposing player's goal. Upon scoring, the puck will reset and a new round will begin. There is no upper limit, so play to your heart's content!

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
        <td>KDown Arrow</td>
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
    <tr>
        <td>Ctrl + F1</td>
        <td>Switch Camera to Player 1 Perspective</td>
    </tr>
    <tr>
        <td>Ctrl + F2</td>
        <td>Switch Camera to Player 2 Perspective</td>
    </tr>
    <tr>
        <td>Ctrl + F3</td>
        <td>Switch Camera to Side of the Table</td>
    </tr>
    <tr>
        <td>Ctrl + F4</td>
        <td>Switch Camera to Top of Table Perspective</td>
    </tr>
    </tbody>
</table>
