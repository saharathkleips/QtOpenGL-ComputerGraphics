#ifndef INPUT_H
#define INPUT_H

#include <Qt>
#include <QPoint>
#include <QCursor>
#include <vector>
#include <algorithm>

#include <QDebug>

class Input
{
public:
    // Key States
    enum InputState
    {
        InputInvalid,
        InputRegistered,
        InputUnregistered,
        InputTriggered,
        InputPressed,
        InputReleased
    };

    // Check States
    static InputState keyState( Qt::Key key );
    static bool keyTriggered( Qt::Key key );
    static bool keyPressed( Qt::Key key );
    static bool keyReleased( Qt::Key key );

    static InputState buttonState( Qt::MouseButton button );
    static bool buttonTriggered( Qt::MouseButton button );
    static bool buttonPressed( Qt::MouseButton button );
    static bool buttonReleased( Qt::MouseButton button );

    static QPoint mousePosition();
    static QPoint mouseDelta();

private:
    // Update States
    static void update();
    static void registerKeyPress( int key );
    static void registerKeyRelease( int key );
    static void registerMousePress( Qt::MouseButton button );
    static void registerMouseRelease( Qt::MouseButton button );
    static void reset();

    friend class OGLWidget;
};

#endif  //  INPUT_H