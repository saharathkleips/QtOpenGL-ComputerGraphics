#include "transform3d.h"
#include <QDebug>

const QVector3D Transform3D::LocalForward(0.0f, 0.0f, 1.0f);
const QVector3D Transform3D::LocalUp(0.0f, 1.0f, 0.0f);
const QVector3D Transform3D::LocalRight(1.0f, 0.0f, 0.0f);

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//
Transform3D::Transform3D()
    :   m_dirty(true),
        m_scale(1.0f, 1.0f, 1.0f)
{

}

//
// TRANSFORM WITH ADD / SCALE //////////////////////////////////////////////////
//
void Transform3D::translate(const QVector3D& dt)
{
    m_dirty = true;
    m_translation += dt;
}

void Transform3D::translate(float dx, float dy, float dz)
{
    translate( QVector3D( dx, dy, dz ) );
}

void Transform3D::scale(const QVector3D& ds)
{
    m_dirty = true;
    m_scale *= ds;
}

void Transform3D::scale(float dx, float dy, float dz)
{
    scale( QVector3D( dx, dy, dz) );
}

void Transform3D::scale(float factor)
{
    scale( QVector3D( factor, factor, factor ));
}

void Transform3D::rotate(const QQuaternion& dr)
{
    m_dirty = true;
    m_rotation = dr * m_rotation;
}

void Transform3D::rotate(float angle, const QVector3D& axis)
{
    rotate( QQuaternion::fromAxisAndAngle( axis,angle ) );
}

void Transform3D::rotate(float angle, float ax, float ay, float az)
{
    rotate( QQuaternion::fromAxisAndAngle( ax, ay, az, angle ) );
}

void Transform3D::grow(const QVector3D &ds)
{
    m_dirty = true;
    m_scale += ds;
}

void Transform3D::grow(float dx, float dy, float dz)
{
    grow( QVector3D( dx, dy, dz ) );
}

void Transform3D::grow(float factor)
{
    grow( QVector3D( factor, factor, factor ) );
}

//
// TRANSFORM TO (MUTATORS)
//
void Transform3D::setTranslation(const QVector3D& t)
{
    m_dirty = true;
    m_translation = t;
}

void Transform3D::setTranslation(float x, float y, float z)
{
    setTranslation( QVector3D( x, y, z ) );
}

void Transform3D::setScale(const QVector3D& s)
{
    m_dirty = true;
    m_scale = s;
}

void Transform3D::setScale(float x, float y, float z)
{
    setScale( QVector3D( x, y, z ) );
}

void Transform3D::setScale(float k)
{
    setScale( QVector3D( k, k, k ) );
}

void Transform3D::setRotation(const QQuaternion& r)
{
    m_dirty = true;
    m_rotation = r;
}

void Transform3D::setRotation(float angle, const QVector3D& axis)
{
    setRotation( QQuaternion::fromAxisAndAngle( axis, angle ) );
}

void Transform3D::setRotation(float angle, float ax, float ay, float az)
{
    setRotation( QQuaternion::fromAxisAndAngle( ax, ay, az, angle ) );
}

//
// ACCESSORS ///////////////////////////////////////////////////////////////////
//
const QVector3D& Transform3D::translation() const
{
    return m_translation;
}

const QVector3D& Transform3D::scale() const
{
    return m_scale;
}

const QQuaternion& Transform3D::rotation() const 
{ 
    return m_rotation; 
}

const QMatrix4x4& Transform3D::toMatrix()
{
    if( m_dirty )
    {
        m_dirty = false;
        m_world.setToIdentity();
        m_world.translate(m_translation);
        m_world.rotate(m_rotation);
        m_world.scale(m_scale);
    }
    return m_world;
}

//
// Query ///////////////////////////////////////////////////////////////////////
//
QVector3D Transform3D::forward() const
{
    return m_rotation.rotatedVector(LocalForward);
}
 
QVector3D Transform3D::up() const
{
    return m_rotation.rotatedVector(LocalUp);
}
 
QVector3D Transform3D::right() const
{
    return m_rotation.rotatedVector(LocalRight);
}

//
// QT OUTPUT STREAMS ///////////////////////////////////////////////////////////
//
QDebug operator<<(QDebug dbg, const Transform3D& transform)
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

QDataStream& operator<<(QDataStream& out, const Transform3D& transform)
{
    out << transform.m_translation;
    out << transform.m_scale;
    out << transform.m_rotation;
    return out;
}

QDataStream& operator>>(QDataStream& in, Transform3D& transform)
{
    in >> transform.m_translation;
    in >> transform.m_scale;
    in >> transform.m_rotation;
    transform.m_dirty = true;
    return in;
}