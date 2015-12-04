#include "labyrinth.h"

Labyrinth::Labyrinth( int seed, int width, int height )
    :   m_seed( seed ), m_width( width ), m_height( height )
{
    m_maze = MazeGenerator::makeMaze( m_seed, m_width, m_height );
    MazeGenerator::printMaze( m_maze );
}

void Labyrinth::addRigidBodys( btDiscreteDynamicsWorld* dynamicsWorld )
{
    for( Cell* cell : m_cells )
        dynamicsWorld->addRigidBody( cell->RigidBody );
}

void Labyrinth::initializeGL()
{
    m_cells.push_back( new Cell( btTransform( btQuaternion( 0, 0, 0, 1 ), 
            btVector3( 5.0, 5.0, 5.0 ) ), "textures/Cube_RockWall.jpg" ) );

    for( Cell* cell : m_cells )
        cell->initializeGL();
}

void Labyrinth::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    for( Cell* cell : m_cells )
        cell->paintGL( camera, projection );
}

void Labyrinth::update()
{
    for( Cell* cell : m_cells )
        cell->update();
}

void Labyrinth::teardownGL()
{
    for( Cell* cell : m_cells )
        cell->teardownGL();
}