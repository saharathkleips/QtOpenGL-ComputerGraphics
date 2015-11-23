#include "colorVertex.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Default constructor for ColorVertex.
 */
ColorVertex::ColorVertex()
{
}

/**
 * @brief      Overloaded constructor for ColorVertex.
 *
 * @param[in]  position  The position data for the ColorVertex.
 */
ColorVertex::ColorVertex( const QVector3D& position )
    :   m_position( position )
{
}

/**
 * @brief      Overloaded constructor for ColorVertex.
 *
 * @param[in]  position  The position data for the ColorVertex.
 * @param[in]  color     The color data for the ColorVertex.
 */
ColorVertex::ColorVertex( const QVector3D& position, const QVector4D& color )
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
const QVector3D& ColorVertex::position() const
{
    return m_position;
}

/**
 * @brief      Gets the color.
 *
 * @return     The color.
 */
const QVector4D& ColorVertex::color() const
{
    return m_color;
}

/**
 * @brief      Sets position to a new position.
 *
 * @param[in]  position  The new position.
 */
void ColorVertex::setPosition( const QVector3D& position )
{
    m_position = position;
}

/**
 * @brief      Sets color to a new color.
 *
 * @param[in]  color  The new color.
 */
void ColorVertex::setColor( const QVector4D& color )
{
    m_color = color;
}

//
// OPENGL HELPERS //////////////////////////////////////////////////////////////
// 

/**
 * @brief      Calculates the position offset within ColorVertex.
 *
 * @return     The position offset.
 */
int ColorVertex::positionOffset()
{
    return offsetof( ColorVertex, m_position );
}

/**
 * @brief      Calcualtes the uv offset within ColorVertex.
 *
 * @return     The uv offset.
 */
int ColorVertex::colorOffset()
{
    return offsetof( ColorVertex, m_color );
}

/**
 * @brief      Calculates the stride of ColorVertex.
 *
 * @return     The stride of ColorVertex.
 */
int ColorVertex::stride()
{
    return sizeof( ColorVertex );
}