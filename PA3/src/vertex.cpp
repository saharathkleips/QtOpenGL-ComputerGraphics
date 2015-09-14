#include "vertex.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//
Q_DECL_CONSTEXPR Vertex::Vertex()
{

}

Q_DECL_CONSTEXPR Vertex::Vertex(const QVector3D &position)
    :   m_position(position)
{

}

Q_DECL_CONSTEXPR Vertex::Vertex(const QVector3D &position, 
    const QVector3D &color)
    :   m_position(position), m_color(color)
{

}

//
// GETTERS / SETTERS ///////////////////////////////////////////////////////////
//
Q_DECL_CONSTEXPR const QVector3D& Vertex::position() const
{
    return m_position;
}

Q_DECL_CONSTEXPR const QVector3D& Vertex::color() const
{
    return m_color;
}

void Vertex::setPosition(const QVector3D& position)
{
    m_position = position;
}

void Vertex::setColor(const QVector3D& color)
{
    m_color = color;
}

//
// OPENGL HELPERS //////////////////////////////////////////////////////////////
//
Q_DECL_CONSTEXPR int Vertex::positionOffset()
{
    return offsetof(Vertex, m_position);
}

Q_DECL_CONSTEXPR int Vertex::colorOffset()
{
    return offsetof(Vertex, m_color);
}

Q_DECL_CONSTEXPR int Vertex::stride()
{
    return sizeof(Vertex);
}