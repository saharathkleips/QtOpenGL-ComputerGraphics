#include "glWidget.h"

#include <QApplication>
#include <QDebug>
#include <QString>
#include <QOpenGLShaderProgram>
#include <QPainter>
#include <QRect>
#include <QtMath>

#include <QMouseEvent>
#include <QKeyEvent>

#include "vertex.h"
#include "sg_vertexes.h"

//
//  CONSTRUCTORS    ////////////////////////////////////////////////////////////
//

GLWidget::GLWidget()
{
    //  Update the Widget after a frameswap
    connect( this, SIGNAL( frameSwapped() ), 
        this, SLOT( update() ) );
    //  Exit the application
    connect( this, SIGNAL( exitFlag() ),
        QApplication::instance(), SLOT( quit() ) );
    //  Rotate Clockwise
    connect( this, SIGNAL( rotateClockwise( bool ) ),
        this, SLOT( set_rotate_cw( bool ) ) );
    connect( this, SIGNAL( rotateClockwiseMoon( bool ) ),
        this, SLOT( set_rotate_cw_moon( bool ) ) );
    //  Translate Clockwise
    connect( this, SIGNAL( translateClockwise( bool ) ),
        this, SLOT( set_translate_cw( bool ) ) );
    connect( this, SIGNAL( translateClockwiseMoon( bool ) ),
        this, SLOT( set_translate_cw_moon( bool ) ) );

    //  Context Menu
    context_menu = new QMenu();
    setContextMenuPolicy(Qt::CustomContextMenu);
    action_pause = context_menu->addAction("Unpause All");
    action_exit = context_menu->addAction("Exit Program");

    //  Context Menu Request
    connect( this, SIGNAL( customContextMenuRequested( const QPoint ) ), 
        this, SLOT( contextMenuRequested( QPoint ) ) );
    //  Context Menu Pause All
    connect( action_pause, SIGNAL( triggered() ),
        this, SLOT( pause() ) );
    //  Context Menu Quit
    connect( action_exit, SIGNAL( triggered() ),
        QApplication::instance(), SLOT( quit() ) );


    //  Set the initial scene
    transform3d.setTranslation( 3.0 * sin( 0.0f ), 0, 3.0 * cos( 0.0f ) );
    transform3d.translate( 0.0f, 0.0f, -10.0f );
    transform3d_2.scale( 0.5f );
    transform3d_2.setTranslation(
        transform3d.translation().x() + 2.0f * sin( 0.0f ),
        transform3d.translation().y(),
        transform3d.translation().z() + 2.0f * cos( 0.0f ) );
    camera3d.rotate( -25.0f, 1.0f, 0.0f, 0.0f );
    camera3d.translate( 0.0f, 3.5f, 0.0f );

    //  Initialize planet system helper variables
    is_paused = true;
    rotate_cw = false;
    translate_cw = true;
    rotate_cw_moon = true;
    translate_cw_moon = false;

    setOrbitString();
}

GLWidget::~GLWidget()
{
    makeCurrent();
    teardownGL();
}

//
//  OPENGL FUNCTIONS    ////////////////////////////////////////////////////////
//
void GLWidget::initializeGL()
{
    //  Initialize OpenGL Backend
    initializeOpenGLFunctions();
    printContextInformation();

    //  Application Specific Initialization
    {
        //  Create Shader (No release until VAO)
        program = new QOpenGLShaderProgram();
        program->addShaderFromSourceFile( QOpenGLShader::Vertex, 
            ":/shaders/simple.vs" );
        program->addShaderFromSourceFile( QOpenGLShader::Fragment,
            ":/shaders/simple.fs" );
        program->link();
        program->bind();

        //  Cache Uniform Locations
        model_to_world = program->uniformLocation( "model_to_world" );
        world_to_eye = program->uniformLocation( "world_to_eye" );
        eye_to_clip = program->uniformLocation( "eye_to_clip" );

        //  Create Buffer (No release until VAO)
        vertex_buffer.create();
        vertex_buffer.bind();
        vertex_buffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
        vertex_buffer.allocate( sg_vertexes, sizeof( sg_vertexes ) );

        //  Create Vertex Array Object (VAO)
        vao.create();
        vao.bind();
        program->enableAttributeArray( 0 );
        program->enableAttributeArray( 1 );
        program->setAttributeBuffer( 0, GL_FLOAT, Vertex::positionOffset(), 
            Vertex::PositionTupleSize, Vertex::stride() );
        program->setAttributeBuffer( 1, GL_FLOAT, Vertex::colorOffset(), 
            Vertex::ColorTupleSize, Vertex::stride() );

        //  Release All (Order matters!!!)
        vao.release();
        vertex_buffer.release();
        program->release();
    }
}

void GLWidget::resizeGL( int width, int height )
{
    projection.setToIdentity();
    projection.perspective( 45.0f, float( width ) / float( height ), 
        0.01f, 1000.0f );
}

void GLWidget::paintGL()
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask(GL_TRUE);
    glEnable( GL_CULL_FACE );
    glClearColor( 0.0f, 0.0f, 0.2f, 1.0f );

    //  Clear Screen
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    //  Render Using Shader
    program->bind();
    program->setUniformValue( world_to_eye, camera3d.toMatrix() );
    program->setUniformValue( eye_to_clip, projection );

    {
        vao.bind();
        program->setUniformValue( model_to_world, transform3d.toMatrix() );
        glDrawArrays( GL_TRIANGLES, 0, 
            sizeof( sg_vertexes ) / sizeof( sg_vertexes[0] ) );
        vao.release();
        vao.bind();
        program->setUniformValue( model_to_world, transform3d_2.toMatrix() );
        glDrawArrays( GL_TRIANGLES, 0, 
            sizeof( sg_vertexes ) / sizeof( sg_vertexes[0] ) );
        vao.release();
    }

    program->release();

    //  Draw 2D Elements
    QPainter painter(this);
    painter.setPen(QColor(255, 255, 255, 255));
    QRect rect(QWidget::width() / 2 - 100, 10, 200, 100);
    painter.beginNativePainting();
    painter.drawText(rect, Qt::AlignHCenter, orbit_string);
    painter.endNativePainting();

}

void GLWidget::teardownGL()
{
    //  Destroy OpenGL Information
    vao.destroy();
    vertex_buffer.destroy();
    delete program;
}

//
//  QT SLOTS    ////////////////////////////////////////////////////////////////
//
void GLWidget::update()
{
    static float angle = 0.0;
    static float moonAngle = 0.0;
    float rotationSpeed = 0.0;
    float moonRotationSpeed = 0.0;

    if( !is_paused )
    {
        if( translate_cw )
            angle -= .03;
        else
            angle += .03;

        if( translate_cw_moon )
            moonAngle -= .09;
        else
            moonAngle += .09;

        if( rotate_cw )
            rotationSpeed = -1.5;
        else
            rotationSpeed = 1.5;

        if( rotate_cw_moon )
            moonRotationSpeed = -3.0;
        else
            moonRotationSpeed = 3.0;

        transform3d.setTranslation( 3.0 * sin( angle ), 0, 3.0 * cos( angle ) );
        transform3d.translate( 0.0f, 0.0f, -10.0f );

        transform3d_2.setTranslation(
            transform3d.translation().x() + 2.0f * sin( moonAngle ),
            transform3d.translation().y(),
            transform3d.translation().z() + 2.0f * cos( moonAngle ) );

        transform3d.rotate( rotationSpeed, 0.0f, 1.0f, 0.0f );
        transform3d_2.rotate( moonRotationSpeed, 0.0f, 1.0f, 0.0f );
    }

    //Schedule a redraw
    QOpenGLWidget::update();
}

void GLWidget::pause()
{
    is_paused = !is_paused;

    if( is_paused )
        action_pause->setText("Unpause");
    else
        action_pause->setText("Pause");
}

void GLWidget::set_rotate_cw( bool cw )
{
    rotate_cw = cw;
    setOrbitString();
}

void GLWidget::set_rotate_cw_moon( bool cw )
{
    rotate_cw_moon = cw;
    setOrbitString();
}

void GLWidget::set_translate_cw( bool cw )
{
    translate_cw = cw;
    setOrbitString();
}

void GLWidget::set_translate_cw_moon( bool cw )
{
    translate_cw_moon = cw;
    setOrbitString();
}

void GLWidget::contextMenuRequested( QPoint point )
{
    context_menu->popup( mapToGlobal( point ) );
}

//
//  INPUT EVENTS    ////////////////////////////////////////////////////////////
//
void GLWidget::keyPressEvent( QKeyEvent* event )
{
    switch( event->key() )
    {
        //  Planet Controls
        case Qt::Key_Up:
            emit set_translate_cw( false );
            break;
        case Qt::Key_Down:
            emit set_translate_cw( true );
            break;
        case Qt::Key_Left:
            emit set_rotate_cw( false );
            break;
        case Qt::Key_Right:
            emit set_rotate_cw( true );
            break;
        //  Moon Controls
        case Qt::Key_W:
            emit set_translate_cw_moon( false );
            break;
        case Qt::Key_S:
            emit set_translate_cw_moon( true );
            break;
        case Qt::Key_A:
            emit set_rotate_cw_moon( false );
            break;
        case Qt::Key_D:
            emit set_rotate_cw_moon( true );
            break;
        case Qt::Key_Escape:
            emit exitFlag();
            break;
        default:
            break;
    }
}

void GLWidget::keyReleaseEvent( QKeyEvent* event )
{
    (void)event;
}

void GLWidget::mousePressEvent( QMouseEvent* event )
{
    (void)event;
}

void GLWidget::mouseReleaseEvent( QMouseEvent* event )
{
    switch( event->button() )
    {
        case Qt::LeftButton:
            emit translateClockwise( !translate_cw );
            emit translateClockwiseMoon( !translate_cw_moon );
            break;
        case Qt::RightButton:
            emit contextMenuRequest( event->pos() );
            break;
        default:
            break;
    }
}

//
//  PRIVATE HELPER FUNCTIONS    ////////////////////////////////////////////////
//
void GLWidget::printContextInformation()
{
    QString gl_type;
    QString gl_version;
    QString gl_profile;

    //  Get Version Information
    gl_type = (context()->isOpenGLES()) ? "OpenGL ES" : "OpenGL";
    gl_version = reinterpret_cast<const char*>( glGetString( GL_VERSION ) );

    //  Get Profile Information
    switch( format().profile() )
    {
        case QSurfaceFormat::NoProfile:
            gl_profile = "NoProfile";
            break;
        case QSurfaceFormat::CoreProfile:
            gl_profile = "CoreProfile";
            break;
        case QSurfaceFormat::CompatibilityProfile:
            gl_profile = "CompatibilityProfile";
            break;
    }

    qDebug() << qPrintable( gl_type ) << qPrintable( gl_version ) <<
        "(" << qPrintable( gl_profile ) << ")";
}

void GLWidget::setOrbitString()
{
    QString p_orbit = (translate_cw) ? "Clockwise" : "Counter-Clockwise";
    QString p_rotate = (rotate_cw) ? "Clockwise" : "Counter-Clockwise";
    QString m_orbit = (translate_cw_moon) ? "Clockwise" : "Counter-Clockwise";
    QString m_rotate = (rotate_cw_moon) ? "Clockwise" : "Counter-Clockwise";

    orbit_string = "[Planet]\n" + 
        p_orbit + " Orbit\n" +
        p_rotate + " Rotation\n" +
        "[Moon]\n" +
        m_orbit + " Orbit\n" +
        m_rotate + " Rotation";
}