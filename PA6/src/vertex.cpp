#include "vertex.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Default constructor for Vertex.
 */
Vertex::Vertex()
{
}

/**
 * @brief      Overloaded constructor for Vertex.
 *
 * @param[in]  position  The position data for the vertex.
 */
Vertex::Vertex( const QVector3D& position )
    :   m_position( position )
{
}

/**
 * @brief      Overloaded constructor for Vertex.
 *
 * @param[in]  position  The position data for the vertex.
 * @param[in]  color     The color data for the vertex.
 */
Vertex::Vertex( const QVector3D& position, const QVector3D& color )
    :   m_position( position ), m_color( color )
{
}

//
// ACCESSORS & MUTATORS ////////////////////////////////////////////////////////
// 

/**
 * @brief      Gets the position.
 *
 * @return     The position.
 */
const QVector3D& Vertex::position() const
{
    return m_position;
}

/**
 * @brief      Gets the color.
 *
 * @return     The color.
 */
const QVector3D& Vertex::color() const
{
    return m_color;
}

/**
 * @brief      Sets position to a new position.
 *
 * @param[in]  position  The new position.
 */
void Vertex::setPosition( const QVector3D& position )
{
    m_position = position;
}

/**
 * @brief      Sets color to a new color.
 *
 * @param[in]  color  The new color.
 */
void Vertex::setColor( const QVector3D& color )
{
    m_color = color;
}

//
// OPENGL HELPERS //////////////////////////////////////////////////////////////
// 

/**
 * @brief      Calculates the position offset within Vertex.
 *
 * @return     The position offset.
 */
int Vertex::positionOffset()
{
    return offsetof( Vertex, m_position );
}

/**
 * @brief      Calcualtes the color offset within Vertex.
 *
 * @return     The color offset.
 */
int Vertex::colorOffset()
{
    return offsetof( Vertex, m_color );
}

/**
 * @brief      Calculates the stride of Vertex.
 *
 * @return     The stride of Vertex.
 */
int Vertex::stride()
{
    return sizeof( Vertex );
}