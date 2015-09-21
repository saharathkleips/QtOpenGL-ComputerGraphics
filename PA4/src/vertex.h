#ifndef VERTEX_H
#define VERTEX_H

#include <QVector3D>

class Vertex
{
public:
    // Constructors
    Vertex();
    explicit Vertex( const QVector3D& position );
    Vertex( const QVector3D& position, const QVector3D& color );

    // Accessors & Mutators
    const QVector3D& position() const;
    const QVector3D& color() const;
    void setPosition( const QVector3D& position );
    void setColor( const QVector3D& color );

    // OpenGL Helpers
    static const int PositionTupleSize = 3;
    static const int ColorTupleSize = 3;
    static int positionOffset();
    static int colorOffset();
    static int stride();

private:
    QVector3D m_position;
    QVector3D m_color;
};

#endif  // VERTEX_H