#ifndef CAMERA3D_H
#define CAMERA3D_H

#include "transform3d.h"

class Camera3D
{
public:
    static const QVector3D LocalForward;
    static const QVector3D LocalUp;
    static const QVector3D LocalRight;

    //Constructors
    Camera3D();

    //Transform with Add / Scale
    void translate(const QVector3D& dt);
    void translate(float dx, float dy, float dz);
    void rotate(const QQuaternion& dr);
    void rotate(float angle, const QVector3D& axis);
    void rotate(float angle, float ax, float ay, float az);

    //Mutators
    void setTranslation(const QVector3D& t);
    void setTranslation(float x, float y, float z);
    void setRotation(const QQuaternion& r);
    void setRotation(float angle, const QVector3D& axis);
    void setRotation(float angle, float ax, float ay, float az);

    //Accessors
    const QVector3D& translation() const;
    const QQuaternion& rotation() const;
    const QMatrix4x4& toMatrix();

    //Query
    QVector3D forward() const;
    QVector3D right() const;
    QVector3D up() const;

private:
    bool m_dirty;
    QVector3D m_translation;
    QQuaternion m_rotation;
    QMatrix4x4 m_world;

#ifndef QT_NO_DATASTREAM
    friend QDataStream& operator<<(QDataStream& out, const Camera3D& transform);
    friend QDataStream& operator>>(QDataStream& in, Camera3D& transform);
#endif
};

Q_DECLARE_TYPEINFO(Camera3D, Q_MOVABLE_TYPE);

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const Camera3D& transform);
#endif

#ifndef QT_NO_DATASTREAM
QDataStream& operator<<(QDataStream& out, const Camera3D& transform);
QDataStream& operator>>(QDataStream& in, Camera3D& transform);
#endif

#endif  //  CAMERA3D_H