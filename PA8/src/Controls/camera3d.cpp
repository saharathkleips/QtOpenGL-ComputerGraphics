#include "camera3d.h"

//
// STATIC CONSTANTS ////////////////////////////////////////////////////////////
//
const QVector3D Camera3D::LocalForward( 0.0f, 0.0f, -1.0f );
const QVector3D Camera3D::LocalUp( 0.0f, 1.0f, 0.0f );
const QVector3D Camera3D::LocalRight( 1.0f, 0.0f, 0.0f );

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Default constructor.
 */
Camera3D::Camera3D()
{
}

//
// TRANSFORM (ADD / SCALE) /////////////////////////////////////////////////////
// 

/**
 * @brief      Moves the matrix based on its current location.
 * 
 * @param[in]  dt    The location to add onto the current matrix.
 */
void Camera3D::translate( const QVector3D& dt )
{
    m_translation += dt;
}

/**
 * @brief     Overloaded translate function.
 * @see       Camera3D::translate( const QVector3D& dt )
 *
 * @param[in]  dx    X-axis offset.
 * @param[in]  dy    Y-axis offset.
 * @param[in]  dz    Z-axis offset.
 */
void Camera3D::translate( float dx, float dy, float dz )
{
    translate( QVector3D( dx, dy, dz ) );
}

/**
 * @brief      Rotates the matrix based on its current rotation.
 *
 * @param[in]  dr    The rotation to add onto the current matrix.
 */
void Camera3D::rotate( const QQuaternion& dr )
{
    m_rotation = dr * m_rotation;
}

/**
 * @brief      Overloaded rotate function.
 * @see        Camera3D::rotate( const QQuaternion& dr )
 *
 * @param[in]  angle  The angle to add onto the current angle.
 * @param[in]  axis   The axis of rotation for the angle.
 */
void Camera3D::rotate( float angle, const QVector3D& axis )
{
    rotate( QQuaternion::fromAxisAndAngle( axis, angle ) );
}

/**
 * @brief      Overloaded rotate function.
 * @see        Camera3D::rotate( const QQuaternion& dr )
 *
 * @param[in]  angle  The angle to add onto the current angle.
 * @param[in]  ax     The x-axis of rotation.
 * @param[in]  ay     The y-axis of rotation.
 * @param[in]  az     The z-axis of rotation.
 */
void Camera3D::rotate( float angle, float ax, float ay, float az )
{
    rotate( QQuaternion::fromAxisAndAngle( ax, ay, az, angle ) );
}

//
// TRANSFORM MUTATORS //////////////////////////////////////////////////////////
// 

/**
 * @brief      Sets the matrix to a new location.
 *
 * @param[in]  t     The new location.
 */
void Camera3D::setTranslation( const QVector3D& t )
{
    m_translation = t;
}

/**
 * @brief      Overloaded setTranslation function.
 * @see        Camera3D::setTranslation( const QVector3D& t )
 *
 * @param[in]  x     The new x-axis location.
 * @param[in]  y     The new y-axis location.
 * @param[in]  z     The new z-axis location.
 */
void Camera3D::setTranslation( float x, float y, float z )
{
    setTranslation( QVector3D( x, y, z ) );
}

/**
 * @brief      Sets the matrix to a new rotation.
 *
 * @param[in]  r     The new rotation.
 */
void Camera3D::setRotation( const QQuaternion& r )
{
    m_rotation = r;
}

/**
 * @brief      Overloaded setRotation function.
 * @see        Camera3D::setRotation( const QQuaternion& r )
 *
 * @param[in]  angle  The new angle of rotation.
 * @param[in]  axis   The axis of rotation for the new angle.
 */
void Camera3D::setRotation( float angle, const QVector3D& axis )
{
    setRotation( QQuaternion::fromAxisAndAngle( axis, angle ) );
}

/**
 * @brief      Overloaded setRotation function.
 * @see        Camera3D::setRotation( const QQuaternion& r )
 * 
 * @param[in]  angle  The new angle of rotation.
 * @param[in]  x      The x-axis of rotation for the new angle.
 * @param[in]  y      The y-axis of rotation for the new angle.
 * @param[in]  z      The z-axis of rotation for the new angle.
 */
void Camera3D::setRotation( float angle, float x, float y, float z )
{
    setRotation( QQuaternion::fromAxisAndAngle( x, y, z, angle ) );
}

//
// ACCESSORS ///////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Getter function for m_translation.
 *
 * @return     The current translation of the matrix.
 */
const QVector3D& Camera3D::translation() const
{
    return m_translation;
}

/**
 * @brief      Getter function for m_rotation.
 *
 * @return     The current rotation of the matrix.
 */
const QQuaternion& Camera3D::rotation() const
{
    return m_rotation;
}

/**
 * @brief      Getter function for m_world.
 *
 * @return     The full matrix with current translations.
 */
const QMatrix4x4& Camera3D::toMatrix()
{
    m_world.setToIdentity();
    m_world.rotate( m_rotation.conjugate() );
    m_world.translate( -m_translation );

    return m_world;
}

//
// QUERIES /////////////////////////////////////////////////////////////////////
// 

/**
 * @brief      The relative forward position of this matrix.
 *
 * @return     A foward vector based on this matrix.
 */
QVector3D Camera3D::forward() const
{
    return m_rotation.rotatedVector(LocalForward);
}
 
/**
 * @brief      The relative up position of this matrix.
 *
 * @return     An up vector based on this matrix.
 */
QVector3D Camera3D::up() const
{
    return m_rotation.rotatedVector(LocalUp);
}
 
/**
 * @brief      The relative right position of this matrix.
 *
 * @return     A right vector based on this matrix.
 */
QVector3D Camera3D::right() const
{
    return m_rotation.rotatedVector(LocalRight);
}

//
// DEBUG ///////////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Overloaded operator<< for the Camera3D class.
 *
 * @param[in]  dbg        The QDebug context to output to.
 * @param[in]  transform  The Camera3D class to output.
 *
 * @return     The formatted QDebug output of Camera3D's properties
 */
QDebug operator<<( QDebug dbg, const Camera3D& transform )
{
    dbg << "Camera3D\n{\n";
    dbg << "\tPosition: <" << transform.translation().x() << ", " <<
                            transform.translation().y() << ", " <<
                            transform.translation().z() << ">\n";
    dbg << "\tRotation: <" << transform.rotation().x() << ", " <<
                            transform.rotation().y() << ", " <<
                            transform.rotation().z() << " | " <<
                            transform.rotation().scalar() << ">\n}";
    return dbg;
}