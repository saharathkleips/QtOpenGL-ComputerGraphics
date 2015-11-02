# PA8 - Bullet (Ben Nicholes, Denis Morozov, Saharath Kleips)
This project highlights the [Bullet Physics Engine](http://bulletphysics.org/wordpress/). The project demonstrates custom collision meshes as well as collisions between a static object (the board) and a kinematic object (the cube). You may move around the cube and observe it colliding with the board beneth it. The world does contain gravity and the cube can fly off the board if you hit the walls hard enough.

Note: This project is not completed and as a result, the sphere and cylinder are not physics objects and are simply there on display. The "Interaction" menu also currently provides no functionality. I am also aware that I've apparently spelt "cylindar" wrong, but due to time constraints, we will not be refactoring this issue. For a better example of Bullet interactions please check the next assignment, PA9. 
 
![](.screenshot.png "Screenshot")

## Table of Contents
+ [Controls](#controls)
+ [Installation Instructions](install.md)  
+ [Build Instructions](build.md)  
+ [Bug Encounters / Error Fixes](bugs.md)

##Controls
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
            <td>RMB + Q</td>
            <td>Move camera down</td>
        </tr>
        <tr>
            <td>RMB + E</td>
            <td>Move camera up</td>
        </tr>
        <tr>
            <td>RMB + W</td>
            <td>Move camera forward</td>
        </tr>
        <tr>
            <td>RMB + A</td>
            <td>Move camera left</td>
        </tr>
        <tr>
            <td>RMB + S</td>
            <td>Move camera backwards</td>
        </tr>
        <tr>
            <td>RMB + D</td>
            <td>Move camera right</td>
        </tr>
        <tr>
            <td>Up Arrow</td>
            <td>Move cube along negative z axis</td>
        </tr>
        <tr>
            <td>Down Arrow</td>
            <td>Move cube along positive z axis</td>
        </tr>
        <tr>
            <td>Left Arrow</td>
            <td>Move cube along negative x axis</td>
        </tr>
        <tr>
            <td>Right Arrow</td>
            <td>Move cube along positive x axis</td>
        </tr>
        <tr>
            <td>Ctrl + Q</td>
            <td>Quit the application</td>
        </tr>
    </tbody>
</table>