#ifndef UV_VERTEX_H
#define UV_VERTEX_H

#include <QVector3D>
#include <QVector2D>

class UVVertex
{
public:
    // Constructors
    UVVertex();
    explicit UVVertex( const QVector3D& position );
    UVVertex( const QVector3D& position, const QVector2D& uv );

    // Accessors & Mutators
    const QVector3D& position() const;
    const QVector2D& uv() const;
    void setPosition( const QVector3D& position );
    void setUV( const QVector2D& uv );

    // OpenGL Helpers
    static const int PositionTupleSize = 3;
    static const int UVTupleSize = 2;
    static int positionOffset();
    static int uvOffset();
    static int stride();

private:
    QVector3D m_position;
    QVector2D m_uv;
};

#endif  // UV_VERTEX_H