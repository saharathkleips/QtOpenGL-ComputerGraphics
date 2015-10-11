#include "input.h"

//
// STATIC HELPER STRUCTURES ////////////////////////////////////////////////////
// 


template<typename T>
struct InputInstance : std::pair<T, Input::InputState>
{
    typedef std::pair<T, Input::InputState> base_class;
    inline InputInstance( T value ) 
        : base_class( value, Input::InputInvalid ){}
    inline InputInstance( T value , Input::InputState state ) 
        : base_class( value, state ){}
    inline bool operator==( const InputInstance& rhs ) const
    {
        return this->first == rhs.first;
    }
};

typedef InputInstance<Qt::Key> KeyInstance;
typedef InputInstance<Qt::MouseButton> ButtonInstance;

typedef std::vector<KeyInstance> KeyContainer;
typedef std::vector<ButtonInstance> ButtonContainer;

static KeyContainer keyInstances;
static ButtonContainer buttonInstances;
static QPoint mouseCurrentPosition;
static QPoint mousePreviousPosition;
static QPoint mouseDeltaXy;

//
// STATIC HELPER FUNCTIONS /////////////////////////////////////////////////////
// 


static inline KeyContainer::iterator FindKey( Qt::Key value )
{
    return std::find( keyInstances.begin(), keyInstances.end(), value );
}

static inline ButtonContainer::iterator FindButton( Qt::MouseButton value )
{
    return std::find( buttonInstances.begin(), buttonInstances.end(), value );
}

template<typename TPair>
static inline void UpdateStates( TPair& instance )
{
    switch( instance.second )
    {
        case Input::InputRegistered:
            instance.second = Input::InputTriggered;
            break;
        case Input::InputTriggered:
            instance.second = Input::InputPressed;
            break;
        case Input::InputUnregistered:
            instance.second = Input::InputReleased;
            break;
        default:
            break;   
    }
}

template <typename TPair>
static inline bool CheckReleased( const TPair& instance )
{
    return instance.second == Input::InputReleased;
}

template <typename Container>
static inline void Update( Container& container )
{
    typedef typename Container::iterator Iter;
    typedef typename Container::value_type TPair;

    // Remove old data
    Iter remove = std::remove_if( container.begin(), container.end(), 
        &CheckReleased<TPair> );
    container.erase( remove, container.end() );

    // Update existing data
    std::for_each( container.begin(), container.end(), &UpdateStates<TPair> );
}

//
// STATE CHECKING FUNCTIONS ////////////////////////////////////////////////////
// 


bool Input::keyTriggered( Qt::Key key )
{
    return keyState(key) == InputTriggered;
}

bool Input::keyPressed( Qt::Key key )
{
    return keyState(key) == InputPressed;
}

bool Input::keyReleased( Qt::Key key )
{
    return keyState(key) == InputReleased;
}

bool Input::buttonTriggered( Qt::MouseButton button )
{
    return buttonState(button) == InputTriggered;
}

bool Input::buttonPressed( Qt::MouseButton button )
{
    return buttonState(button) == InputPressed;
}

bool Input::buttonReleased( Qt::MouseButton button )
{
    return buttonState(button) == InputReleased;
}

//
// INPUT IMPLEMENTATIONS ///////////////////////////////////////////////////////
// 

Input::InputState Input::keyState( Qt::Key k )
{
    KeyContainer::iterator it = FindKey( k );
    return ( it != keyInstances.end() ) ? it->second : InputInvalid;
}

Input::InputState Input::buttonState( Qt::MouseButton k )
{
    ButtonContainer::iterator it = FindButton( k );
    return ( it != buttonInstances.end() ) ? it->second : InputInvalid;
}

QPoint Input::mousePosition()
{
    return QCursor::pos();
}

QPoint Input::mouseDelta()
{
    return mouseDeltaXy;
}

void Input::update()
{
    mousePreviousPosition = mouseCurrentPosition;
    mouseCurrentPosition = QCursor::pos();
    mouseDeltaXy = mouseCurrentPosition - mousePreviousPosition;

    Update( buttonInstances );
    Update( keyInstances );
}

void Input::registerKeyPress( int k )
{
    KeyContainer::iterator it = FindKey( ( Qt::Key)k );
    if( it == keyInstances.end() )
        keyInstances.push_back( KeyInstance( (Qt::Key)k, InputRegistered ) );
}

void Input::registerKeyRelease( int k )
{
    KeyContainer::iterator it = FindKey( ( Qt::Key)k );
    if( it != keyInstances.end() )
        it->second = InputUnregistered;
}

void Input::registerMousePress( Qt::MouseButton btn )
{
    ButtonContainer::iterator it = FindButton( btn );
    if( it == buttonInstances.end() )
        buttonInstances.push_back( ButtonInstance( btn, InputRegistered ) );
}

void Input::registerMouseRelease( Qt::MouseButton btn )
{
    ButtonContainer::iterator it = FindButton( btn );
    if( it != buttonInstances.end() )
        it->second = InputUnregistered;
}

void Input::reset()
{
    keyInstances.clear();
    buttonInstances.clear();
}