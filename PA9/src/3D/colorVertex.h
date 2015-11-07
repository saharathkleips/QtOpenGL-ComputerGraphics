#ifndef COLOR_VERTEX_H
#define COLOR_VERTEX_H

#include <QVector3D>
#include <QVector4D>

class ColorVertex
{
public:
    // Constructors
    ColorVertex();
    explicit ColorVertex( const QVector3D& position );
    ColorVertex( const QVector3D& position, const QVector4D& color );

    // Accessors & Mutators
    const QVector3D& position() const;
    const QVector4D& color() const;
    void setPosition( const QVector3D& position );
    void setColor( const QVector4D& color );

    // OpenGL Helpers
    static const int PositionTupleSize = 3;
    static const int ColorTupleSize = 4;
    static int positionOffset();
    static int colorOffset();
    static int stride();

private:
    QVector3D m_position;
    QVector4D m_color;
};

#endif  // COLOR_VERTEX_H