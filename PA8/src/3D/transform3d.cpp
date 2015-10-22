#include "transform3d.h"

const QVector3D Transform3D::LocalForward( 0.0f, 0.0f, 1.0f );
const QVector3D Transform3D::LocalUp( 0.0f, 1.0f, 0.0f );
const QVector3D Transform3D::LocalRight( 1.0f, 0.0f, 0.0f );

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Default constructor, sets the scale to 1.
 */
Transform3D::Transform3D()
    :   m_scale( 1.0f, 1.0f, 1.0f )
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
void Transform3D::translate( const QVector3D& dt )
{
    m_translation += dt;
}

/**
 * @brief     Overloaded translate function.
 * @see       Transform3D::translate( const QVector3D& dt )
 *
 * @param[in]  dx    X-axis offset.
 * @param[in]  dy    Y-axis offset.
 * @param[in]  dz    Z-axis offset.
 */
void Transform3D::translate( float dx, float dy, float dz )
{
    translate( QVector3D( dx, dy, dz ) );
}

/**
 * @brief      Scales the matrix based on its current size.
 *
 * @param[in]  ds    The scale to add onto the current matrix.
 */
void Transform3D::scale( const QVector3D& ds )
{
    m_scale *= ds;
}

/**
 * @brief      Overloaded scale function.
 * @see        Transform3D::scale( const QVector3D& ds )
 *
 * @param[in]  dx    X-axis scale.
 * @param[in]  dy    Y-axis scale.
 * @param[in]  dz    Z-axis scale.
 */
void Transform3D::scale( float dx, float dy, float dz )
{
    scale( QVector3D( dx, dy, dz ) );
}

/**
 * @brief      Overloaded scale function.
 * @see        Transform3D::scale( const QVector3D& ds )
 *
 * @param[in]  factor  X-Y-Z-axis scale.
 */
void Transform3D::scale( float factor )
{
    scale( QVector3D( factor, factor, factor ) );
}

/**
 * @brief      Rotates the matrix based on its current rotation.
 *
 * @param[in]  dr    The rotation to add onto the current matrix.
 */
void Transform3D::rotate( const QQuaternion& dr )
{
    m_rotation = dr * m_rotation;
}

/**
 * @brief      Overloaded rotate function.
 * @see        Transform3D::rotate( const QQuaternion& dr )
 *
 * @param[in]  angle  The angle to add onto the current angle.
 * @param[in]  axis   The axis of rotation for the angle.
 */
void Transform3D::rotate( float angle, const QVector3D& axis )
{
    rotate( QQuaternion::fromAxisAndAngle( axis, angle ) );
}

/**
 * @brief      Overloaded rotate function.
 * @see        Transform3D::rotate( const QQuaternion& dr )
 *
 * @param[in]  angle  The angle to add onto the current angle.
 * @param[in]  ax     The x-axis of rotation.
 * @param[in]  ay     The y-axis of rotation.
 * @param[in]  az     The z-axis of rotation.
 */
void Transform3D::rotate( float angle, float ax, float ay, float az )
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
void Transform3D::setTranslation( const QVector3D& t )
{
    m_translation = t;
}

/**
 * @brief      Overloaded setTranslation function.
 * @see        Transform3D::setTranslation( const QVector3D& t )
 *
 * @param[in]  x     The new x-axis location.
 * @param[in]  y     The new y-axis location.
 * @param[in]  z     The new z-axis location.
 */
void Transform3D::setTranslation( float x, float y, float z )
{
    setTranslation( QVector3D( x, y, z ) );
}

/**
 * @brief      Sets the matrix to a new scale.
 *
 * @param[in]  s     The new scale.
 */
void Transform3D::setScale( const QVector3D& s )
{
    m_scale = s;
}

/**
 * @brief      Overloaded setScale function.
 * @see        Transform3D::setScale( const QVector3D& s )
 *
 * @param[in]  x     The new x-axis scale.
 * @param[in]  y     The new y-axis scale.
 * @param[in]  z     The new z-axis scale.
 */
void Transform3D::setScale( float x, float y, float z )
{
    setScale( QVector3D( x, y, z ) );
}

/**
 * @brief      Overloaded setScale function.
 * @see        Transform3D::setScale( const QVector3D& s )
 *
 * @param[in]  k     The new scale based on a factor of k.
 */
void Transform3D::setScale( float k )
{
    setScale( QVector3D( k, k, k ) );
}

/**
 * @brief      Sets the matrix to a new rotation.
 *
 * @param[in]  r     The new rotation.
 */
void Transform3D::setRotation( const QQuaternion& r )
{
    m_rotation = r;
}

/**
 * @brief      Overloaded setRotation function.
 * @see        Transform3D::setRotation( const QQuaternion& r )
 *
 * @param[in]  angle  The new angle of rotation.
 * @param[in]  axis   The axis of rotation for the new angle.
 */
void Transform3D::setRotation( float angle, const QVector3D& axis )
{
    setRotation( QQuaternion::fromAxisAndAngle( axis, angle ) );
}

/**
 * @brief      Overloaded setRotation function.
 * @see        Transform3D::setRotation( const QQuaternion& r )
 * 
 * @param[in]  angle  The new angle of rotation.
 * @param[in]  x      The x-axis of rotation for the new angle.
 * @param[in]  y      The y-axis of rotation for the new angle.
 * @param[in]  z      The z-axis of rotation for the new angle.
 */
void Transform3D::setRotation( float angle, float x, float y, float z )
{
    setRotation( QQuaternion::fromAxisAndAngle( x, y, z, angle ) );
}

void Transform3D::setMatrix( QMatrix4x4 matrix )
{
    m_world = matrix;
}

//
// ACCESSORS ///////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Getter function for m_translation.
 *
 * @return     The current translation of the matrix.
 */
const QVector3D& Transform3D::translation() const
{
    return m_translation;
}

/**
 * @brief      Getter function for m_scale.
 *
 * @return     The current scale of the matrix.
 */
const QVector3D& Transform3D::scale() const
{
    return m_scale;
}

/**
 * @brief      Getter function for m_rotation.
 *
 * @return     The current rotation of the matrix.
 */
const QQuaternion& Transform3D::rotation() const
{
    return m_rotation;
}

/**
 * @brief      Getter function for m_world.
 *
 * @return     The full matrix with current translations.
 */
const QMatrix4x4& Transform3D::toMatrix()
{
    m_world.setToIdentity();
    m_world.translate( m_translation );
    m_world.rotate( m_rotation );
    m_world.scale( m_scale );

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
QVector3D Transform3D::forward() const
{
    return m_rotation.rotatedVector(LocalForward);
}
 
/**
 * @brief      The relative up position of this matrix.
 *
 * @return     An up vector based on this matrix.
 */
QVector3D Transform3D::up() const
{
    return m_rotation.rotatedVector(LocalUp);
}
 
/**
 * @brief      The relative right position of this matrix.
 *
 * @return     A right vector based on this matrix.
 */
QVector3D Transform3D::right() const
{
    return m_rotation.rotatedVector(LocalRight);
}

//
// DEBUG ///////////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Overloaded operator<< for the Transform3D class.
 *
 * @param[in]  dbg        The QDebug context to output to.
 * @param[in]  transform  The Transform3D class to output.
 *
 * @return     The formatted QDebug output of Transform3D's properties
 */
QDebug operator<<( QDebug dbg, const Transform3D& transform )
{
    dbg << "Transform3D\n{\n";
    dbg << "\tPosition: <" << transform.translation().x() << ", " <<
                            transform.translation().y() << ", " <<
                            transform.translation().z() << ">\n";
    dbg << "\tScale: <" << transform.scale().x() << ", " <<
                            transform.scale().y() << ", " <<
                            transform.scale().z() << ">\n";
    dbg << "\tRotation: <" << transform.rotation().x() << ", " <<
                            transform.rotation().y() << ", " <<
                            transform.rotation().z() << " | " <<
                            transform.rotation().scalar() << ">\n}";
    return dbg;
}