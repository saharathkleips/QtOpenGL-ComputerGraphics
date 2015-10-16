#include "oglWidget.h"

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
    // Exit the application
    connect( this, SIGNAL( exitFlag() ),
        QApplication::instance(), SLOT( quit() ) );

    // Setup the Camera
    camera.rotate( -40.0f, 1.0f, 0.0f, 0.0f );
    camera.translate( 0.0f, 30.0f, 50.0f );

    renderables.push_back( new Sun() );
}

/**
 * @brief      Destructor class to unallocate OpenGL information.
 */
OGLWidget::~OGLWidget()
{
    makeCurrent();
    teardownGL();
}

//
// OPENGL FUNCTIONS ////////////////////////////////////////////////////////////
// 

void OGLWidget::initializeGL()
{
    // Init OpenGL Backend
    initializeOpenGLFunctions();
    printContextInfo();

    QVectorIterator<Renderable*> i_renderable( renderables );
    while( i_renderable.hasNext() )
    {
        ( i_renderable.next() )->initializeGL();
    }
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
    projection.perspective( 45.0f,  // Field of view angle
                            float( width ) / float( height ),   // Aspect Ratio
                            0.01f,  // Near Plane (MUST BE GREATER THAN 0)
                            1000.0f );  // Far Plane
}

/**
 * @brief      OpenGL function to draw elements to the surface.
 */
void OGLWidget::paintGL()
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glEnable( GL_CULL_FACE );
    glClearColor( 0.0f, 0.0f, 0.2f, 1.0f );

    // Clear the screen
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    QVectorIterator<Renderable*> i_renderable( renderables );
    while( i_renderable.hasNext() )
    {
        ( i_renderable.next() )->paintGL( camera, projection );
    }
}

/**
 * @brief      Destroys any OpenGL data.
 */
void OGLWidget::teardownGL()
{
    QVectorIterator<Renderable*> i_renderable( renderables );
    while( i_renderable.hasNext() )
    {
        ( i_renderable.next() )->teardownGL();
    }
}

//
// QT SLOTS ////////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Updates any user interactions and model transformations.
 */
void OGLWidget::update()
{
    Input::update();
    if( Input::keyPressed( Qt::Key_Escape ) )
        emit exitFlag();

    // Camera Transforms
    if( Input::buttonPressed( Qt::RightButton ) )
    {
        static const float cameraTranslationSpeed = 0.1f;
        static const float cameraRotationSpeed = 0.1f;

        camera.rotate( -cameraRotationSpeed * Input::mouseDelta().x(), 
            Camera3D::LocalUp );
        camera.rotate( -cameraRotationSpeed * Input::mouseDelta().y(),
            camera.right() );

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

    QVectorIterator<Renderable*> i_renderable( renderables );
    while( i_renderable.hasNext() )
    {
        ( i_renderable.next() )->update();
    }

    QOpenGLWidget::update();
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