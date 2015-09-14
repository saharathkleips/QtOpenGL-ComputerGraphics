#include "camera3d.h"
#include <QDebug>

const QVector3D Camera3D::LocalForward(0.0f, 0.0f, -1.0f);
const QVector3D Camera3D::LocalUp(0.0f, 1.0f, 0.0f);
const QVector3D Camera3D::LocalRight(1.0f, 0.0f, 0.0f);

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//
Camera3D::Camera3D()
    :   m_dirty(true)
{

}

//
// Transform with Add / Scale //////////////////////////////////////////////////
//
void Camera3D::translate(const QVector3D& dt)
{
    m_dirty = true;
    m_translation += dt;
}

void Camera3D::translate(float dx, float dy,float dz) 
{ 
    translate(QVector3D(dx, dy, dz)); 
}

void Camera3D::rotate(const QQuaternion &dr)
{
  m_dirty = true;
  m_rotation = dr * m_rotation;
}

void Camera3D::rotate(float angle, const QVector3D &axis) 
{ 
    rotate(QQuaternion::fromAxisAndAngle(axis, angle)); 
}

void Camera3D::rotate(float angle, float ax, float ay,float az) 
{ 
    rotate(QQuaternion::fromAxisAndAngle(ax, ay, az, angle)); 
}
 
//
// Transform To (Setters) //////////////////////////////////////////////////////
//
void Camera3D::setTranslation(const QVector3D &t)
{
  m_dirty = true;
  m_translation = t;
}

void Camera3D::setTranslation(float x, float y, float z) 
{ 
    setTranslation(QVector3D(x, y, z)); 
}

void Camera3D::setRotation(const QQuaternion &r)
{
  m_dirty = true;
  m_rotation = r;
}

void Camera3D::setRotation(float angle, const QVector3D &axis) 
{ 
    setRotation(QQuaternion::fromAxisAndAngle(axis, angle)); 
}

void Camera3D::setRotation(float angle, float ax, float ay, float az) 
{ 
    setRotation(QQuaternion::fromAxisAndAngle(ax, ay, az, angle)); 
}
 
//
// Accessors ///////////////////////////////////////////////////////////////////
//
const QVector3D& Camera3D::translation() const 
{ 
    return m_translation; 
}

const QQuaternion& Camera3D::rotation() const 
{ 
    return m_rotation; 
}

const QMatrix4x4 &Camera3D::toMatrix()
{
  if (m_dirty)
  {
    m_dirty = false;
    m_world.setToIdentity();
    m_world.rotate(m_rotation.conjugate());
    m_world.translate(-m_translation);
  }
  return m_world;
}

//
// Query ///////////////////////////////////////////////////////////////////////
//
QVector3D Camera3D::forward() const
{
    return m_rotation.rotatedVector(LocalForward);
}

QVector3D Camera3D::right() const
{
  return m_rotation.rotatedVector(LocalRight);
}

QVector3D Camera3D::up() const
{
  return m_rotation.rotatedVector(LocalUp);
}

//
// QT OUTPUT STREAMS ///////////////////////////////////////////////////////////
//
QDebug operator<<(QDebug dbg, const Camera3D& transform)
{
    dbg << "Transform3D\n{\n";
    dbg << "\tPosition: <" << transform.translation().x() << ", " <<
                            transform.translation().y() << ", " <<
                            transform.translation().z() << ">\n";
    dbg << "\tRotation: <" << transform.rotation().x() << ", " <<
                            transform.rotation().y() << ", " <<
                            transform.rotation().z() << " | " <<
                            transform.rotation().scalar() << ">\n}";
    return dbg;
}

QDataStream& operator<<(QDataStream& out, const Camera3D& transform)
{
    out << transform.m_translation;
    out << transform.m_rotation;
    return out;
}

QDataStream& operator>>(QDataStream& in, Camera3D& transform)
{
    in >> transform.m_translation;
    in >> transform.m_rotation;
    transform.m_dirty = true;
    return in;
}