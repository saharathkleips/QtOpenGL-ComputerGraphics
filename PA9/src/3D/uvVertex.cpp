#include "uvVertex.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Default constructor for UVVertex.
 */
UVVertex::UVVertex()
{
}

/**
 * @brief      Overloaded constructor for UVVertex.
 *
 * @param[in]  position  The position data for the UVVertex.
 */
UVVertex::UVVertex( const QVector3D& position )
    :   m_position( position )
{
}

/**
 * @brief      Overloaded constructor for UVVertex.
 *
 * @param[in]  position  The position data for the UVVertex.
 * @param[in]  uv        The uv data for the UVVertex.
 */
UVVertex::UVVertex( const QVector3D& position, const QVector2D& uv )
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
const QVector3D& UVVertex::position() const
{
    return m_position;
}

/**
 * @brief      Gets the uv.
 *
 * @return     The uv.
 */
const QVector2D& UVVertex::uv() const
{
    return m_uv;
}

/**
 * @brief      Sets position to a new position.
 *
 * @param[in]  position  The new position.
 */
void UVVertex::setPosition( const QVector3D& position )
{
    m_position = position;
}

/**
 * @brief      Sets uv to a new uv.
 *
 * @param[in]  uv  The new uv.
 */
void UVVertex::setUV( const QVector2D& uv )
{
    m_uv = uv;
}

//
// OPENGL HELPERS //////////////////////////////////////////////////////////////
// 

/**
 * @brief      Calculates the position offset within UVVertex.
 *
 * @return     The position offset.
 */
int UVVertex::positionOffset()
{
    return offsetof( UVVertex, m_position );
}

/**
 * @brief      Calcualtes the uv offset within UVVertex.
 *
 * @return     The uv offset.
 */
int UVVertex::uvOffset()
{
    return offsetof( UVVertex, m_uv );
}

/**
 * @brief      Calculates the stride of UVVertex.
 *
 * @return     The stride of UVVertex.
 */
int UVVertex::stride()
{
    return sizeof( UVVertex );
}