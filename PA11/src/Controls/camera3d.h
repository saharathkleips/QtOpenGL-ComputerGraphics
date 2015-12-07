#ifndef CAMERA_3D_H
#define CAMERA_3D_H

#include <QVector3D>
#include <QQuaternion>
#include <QMatrix4x4>

class Camera3D
{
public:
    // Constants
    static const QVector3D LocalForward;
    static const QVector3D LocalUp;
    static const QVector3D LocalRight;

    // Constructors
    Camera3D();

    // Transform (Add / Scale)
    void translate( const QVector3D& dt );
    void translate( float dx, float dy, float dz );
    void rotate( const QQuaternion& dr );
    void rotate( float angle, const QVector3D& axis );
    void rotate( float angle, float ax, float ay, float az );

    // Transform Mutators
    void setTranslation( const QVector3D& t );
    void setTranslation( float x, float y, float z );
    void setRotation( const QQuaternion& r );
    void setRotation( float angle, const QVector3D& axis );
    void setRotation( float angle, float ax, float ay, float az );
    void lookAt( const QVector3D &target );

    // Accessors
    const QVector3D& translation() const;
    const QQuaternion& rotation() const;
    const QMatrix4x4& toMatrix();

    // Query
    QVector3D forward() const;
    QVector3D up() const;
    QVector3D right() const;

private:
    QVector3D m_translation;
    QQuaternion m_rotation;
    QMatrix4x4 m_world;

    bool m_matrixWasSet = false;
};

#ifndef QT_DEBUG_TRANSFORM_STREAM
QDebug operator<<( QDebug dbg, const Camera3D& transform );
#endif

#endif  //  CAMERA_3D_H