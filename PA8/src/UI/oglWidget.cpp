#include "oglWidget.h"






#define BIT(x) (1<<(x))
const short COL_TABLE = BIT(0);
const short COL_CUBE = BIT(1);

short tableCollidesWith = COL_CUBE;
short cubeCollidesWith = COL_TABLE;


//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Default constructor for OGLWidget.
 */
OGLWidget::OGLWidget()
{
    // Update the widget after a frameswap
    connect( this, SIGNAL( frameSwapped() ),
        this, SLOT( update() ) );

    // Allows keyboard input to fall through
    setFocusPolicy( Qt::ClickFocus );

    // Default camera view
    camera.rotate( -25.0f, 1.0f, 0.0f, 0.0f );
    camera.translate( 0.0f, 8.0f, 15.0f );

    renderables["Cube"] = new Cube();
    renderables["Cylindar"] = new Cylindar();
    ((BaseEntity*)renderables["Cylindar"])->Transform.translate( -3, 3, 0 );
    renderables["Sphere"] = new Sphere();
    ((BaseEntity*)renderables["Sphere"])->Transform.translate( 3, 3, 0 );
    renderables["Board"] = new Board();
}

/**
 * @brief      Destructor class to unallocate OpenGL information.
 */
OGLWidget::~OGLWidget()
{
    makeCurrent();
    teardownGL();
    teardownBullet();
}

//
// OPENGL FUNCTIONS ////////////////////////////////////////////////////////////
// 

/**
 * @brief      Initializes any OpenGL operations.
 */
void OGLWidget::initializeGL()
{
    // Init OpenGL Backend
    initializeOpenGLFunctions();
    printContextInfo();
    initializeBullet();

    for( QMap<QString, Renderable*>::iterator iter = renderables.begin(); 
        iter != renderables.end(); iter++ )
    {
        (*iter)->initializeGL();
    }

    m_dynamicsWorld->addRigidBody(
        ((Board*)renderables["Board"])->RigidBody, COL_TABLE, tableCollidesWith );
    m_dynamicsWorld->addRigidBody( 
        ((Cube*)renderables["Cube"])->RigidBody, COL_CUBE, cubeCollidesWith );
}

/**
 * @brief      Sets the prespective whenever the window is resized.
 *
 * @param[in]  width   The width of the new window.
 * @param[in]  height  The height of the new window.
 */
void OGLWidget::resizeGL( int width, int height )
{
    projection.setToIdentity();
    projection.perspective( 55.0f,  // Field of view angle
                            float( width ) / float( height ),   // Aspect Ratio
                            0.001f,  // Near Plane (MUST BE GREATER THAN 0)
                            1500.0f );  // Far Plane
}

/**
 * @brief      OpenGL function to draw elements to the surface.
 */
void OGLWidget::paintGL()
{
    // Set the default OpenGL states
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glEnable( GL_CULL_FACE );
    glClearColor( 0.0f, 0.0f, 0.2f, 1.0f );

    // Clear the screen
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    for( QMap<QString, Renderable*>::iterator iter = renderables.begin(); 
        iter != renderables.end(); iter++ )
    {
        (*iter)->paintGL( camera, projection );
    }

}

/**
 * @brief      Destroys any OpenGL data.
 */
void OGLWidget::teardownGL()
{
    for( QMap<QString, Renderable*>::iterator iter = renderables.begin(); 
        iter != renderables.end(); iter++ )
    {
        (*iter)->teardownGL();
    }
}

//
// SLOTS ///////////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Updates any user interactions and model transformations.
 */
void OGLWidget::update()
{
    Input::update();

    flyThroughCamera();

    for( QMap<QString, Renderable*>::iterator iter = renderables.begin(); 
        iter != renderables.end(); iter++ )
    {
        (*iter)->update();
    }

    btScalar rawMatrix[16];
    m_dynamicsWorld->stepSimulation( 1, 10 );

    ((PhysicsEntity*)renderables["Cube"])->
        RigidBody->getWorldTransform().getOpenGLMatrix(rawMatrix);

    QMatrix4x4 newMatrix = QMatrix4x4(rawMatrix);
    newMatrix = newMatrix.transposed();

    ((PhysicsEntity*)renderables["Cube"])->Transform = newMatrix;


    QOpenGLWidget::update();
}

void OGLWidget::setObjectControl(){

    selectedObject = !selectedObject;

}
//
// INPUT EVENTS ////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Default slot for handling key press events.
 *
 * @param      event  The key event information.
 */
void OGLWidget::keyPressEvent( QKeyEvent* event )
{
    if( event->isAutoRepeat() )
        event->ignore();
    else
        Input::registerKeyPress( event->key() );
}

/**
 * @brief      Default slot for handling key release events.
 *
 * @param      event  The key event information.
 */
void OGLWidget::keyReleaseEvent( QKeyEvent* event )
{
    if( event->isAutoRepeat() )
        event->ignore();
    else
        Input::registerKeyRelease( event->key() );
}

/**
 * @brief      Default slot for handling mouse press events.
 *
 * @param      event  The mouse event information.
 */
void OGLWidget::mousePressEvent( QMouseEvent* event )
{
    Input::registerMousePress( event->button() );
}

/**
 * @brief      Default slot for handling mouse release events.
 *
 * @param      event  The mouse event information.
 */
void OGLWidget::mouseReleaseEvent( QMouseEvent* event )
{
    Input::registerMouseRelease( event->button() );
}

//
// PRIVATE HELPER FUNCTIONS ////////////////////////////////////////////////////
//

void OGLWidget::initializeBullet()
{
    m_broadphase = new btDbvtBroadphase();
    m_collisionConfig = new btDefaultCollisionConfiguration();
    m_dispatcher = new btCollisionDispatcher( m_collisionConfig );
    m_solver = new btSequentialImpulseConstraintSolver();
    m_dynamicsWorld = new btDiscreteDynamicsWorld( m_dispatcher, m_broadphase,
        m_solver, m_collisionConfig );

    m_dynamicsWorld->setGravity( btVector3( 0, -0.5, 0 ) );
}

void OGLWidget::teardownBullet()
{
    delete m_dynamicsWorld;
    delete m_solver;
    delete m_dispatcher;
    delete m_collisionConfig;
    delete m_broadphase;
}

/**
 * @brief      Updates the main camera to behave like a Fly-Through Camera.
 */
void OGLWidget::flyThroughCamera()
{
    static const float cameraTranslationSpeed = 0.03f;
    static const float cameraRotationSpeed = 0.2f;

    if( Input::buttonPressed( Qt::RightButton ) )
    {
        // Rotate the camera based on mouse movement
        camera.rotate( -cameraRotationSpeed * Input::mouseDelta().x(), 
            Camera3D::LocalUp );
        camera.rotate( -cameraRotationSpeed * Input::mouseDelta().y(),
            camera.right() );
    }

    // Translate the camera based on keyboard input
    QVector3D cameraTranslations;
    if( Input::keyPressed( Qt::Key_W ) )
        cameraTranslations += camera.forward();
    if( Input::keyPressed( Qt::Key_S ) )
        cameraTranslations -= camera.forward();
    if( Input::keyPressed( Qt::Key_A ) )
        cameraTranslations -= camera.right();
    if( Input::keyPressed( Qt::Key_D ) )
        cameraTranslations += camera.right();
    if( Input::keyPressed( Qt::Key_Q ) )
        cameraTranslations -= camera.up();
    if( Input::keyPressed( Qt::Key_E ) )
        cameraTranslations += camera.up();
    camera.translate( cameraTranslationSpeed * cameraTranslations );
} 

/**
 * @brief      Updates either the sphere or cylinder object to move based on arrow input.
 */
 void OGLWidget::controlObject()
 {
    // if( object == true )
    //     // set object equal to sphere
    //     // else set equal to cylinder

    // // QVector3D objectTranslations;
    // if( Input::keyPressed( Qt::Key_Up ) )
    //     objectTranslations += object.forward();
    // if( Input::keyPressed( Qt::Key_Down ) )
    //     objectTranslations -= object.forward();
    // if( Input::keyPressed( Qt::Key_Left ) )
    //     objectTranslations -= object.right();
    // if( Input::keyPressed( Qt::Key_Right ) )
    //     objectTranslations += object.right();
    // object.translate()


 }



/**
 * @brief      Helper function to print OpenGL Context information to the debug.
 */
void OGLWidget::printContextInfo()
{
    QString glType;
    QString glVersion;
    QString glProfile;

    // Get Version Information
    glType = ( context()->isOpenGLES() ) ? "OpenGL ES" : "OpenGL";
    glVersion = reinterpret_cast<const char*>( glGetString( GL_VERSION ) );

    // Get Profile Information
    switch( format().profile() )
    {
        case QSurfaceFormat::NoProfile:
            glProfile = "No Profile";
            break;
        case QSurfaceFormat::CoreProfile:
            glProfile = "Core Profile";
            break;
        case QSurfaceFormat::CompatibilityProfile:
            glProfile = "Compatibility Profile";
            break;
    }

    qDebug() << qPrintable( glType ) << qPrintable( glVersion ) << 
        "(" << qPrintable( glProfile ) << ")";
}