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
 * @param[in]  uv        The uv data for the vertex.
 */
Vertex::Vertex( const QVector3D& position, const QVector2D& uv )
    :   m_position( position ), m_uv( uv )
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
 * @brief      Gets the uv.
 *
 * @return     The uv.
 */
const QVector2D& Vertex::uv() const
{
    return m_uv;
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
 * @brief      Sets uv to a new uv.
 *
 * @param[in]  color  The new uv.
 */
void Vertex::setUV( const QVector2D& uv )
{
    m_uv = uv;
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
 * @brief      Calcualtes the uv offset within Vertex.
 *
 * @return     The uv offset.
 */
int Vertex::uvOffset()
{
    return offsetof( Vertex, m_uv );
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