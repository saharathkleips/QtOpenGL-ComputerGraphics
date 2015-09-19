#ifndef TRANSFORM3D_H
#define TRANSFORM3D_H

#include <QVector3D>
#include <QQuaternion>
#include <QMatrix4x4>

class Transform3D
{
public:
    //Constatns
    static const QVector3D LocalForward;
    static const QVector3D LocalUp;
    static const QVector3D LocalRight;

    // Constructors
    Transform3D();

    // Transform With Add / Scale
    void translate(const QVector3D &dt);
    void translate(float dx, float dy, float dz);
    void scale(const QVector3D& ds);
    void scale(float dx, float dy, float dz);
    void scale(float factor);
    void rotate(const QQuaternion &dr);
    void rotate(float angle, const QVector3D& axis);
    void rotate(float angle, float ax, float ay, float az);
    void grow(const QVector3D& ds);
    void grow(float dx, float dy, float dz);
    void grow(float factor);

    // Transform To (Mutator)
    void setTranslation(const QVector3D& t);
    void setTranslation(float x, float y, float z);
    void setScale(const QVector3D& s);
    void setScale(float x, float y, float z);
    void setScale(float k);
    void setRotation(const QQuaternion& r);
    void setRotation(float angle, const QVector3D& axis);
    void setRotation(float angle, float ax, float ay, float az);

    // Accessors
    const QVector3D& translation() const;
    const QVector3D& scale() const;
    const QQuaternion& rotation() const;
    const QMatrix4x4& toMatrix();

    // Query
    QVector3D forward() const;
    QVector3D up() const;
    QVector3D right() const;

private:
    bool m_dirty;
    QVector3D m_translation;
    QVector3D m_scale;
    QQuaternion m_rotation;
    QMatrix4x4 m_world;

#ifndef QT_NO_DATASTREAM
    friend QDataStream& operator<<(QDataStream& out, 
        const Transform3D& transform);
    friend QDataStream& operator>>(QDataStream& in, 
        Transform3D &transform);
#endif
};

Q_DECLARE_TYPEINFO(Transform3D, Q_MOVABLE_TYPE);
#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const Transform3D &transform);
#endif

#ifndef QT_NO_DATASTREAM
QDataStream& operator<<(QDataStream& out, const Transform3D& transform);
QDataStream& operator>>(QDataStream& in, Transform3D &transform);
#endif

#endif  //  TRANSFORM3D_H