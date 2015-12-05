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
    float xpos = 0.0f, zpos = 0.0f;
    // m_cells.push_back( new Cell( btTransform( btQuaternion( 0, 0, 0, 1 ), 
    //     btVector3( xpos, 0.0f, zpos ) ), "textures/Cube_RockWall.jpg" ) );
    // m_cells.push_back( new Cell( btTransform( btQuaternion( 0, 0, 0, 1 ), 
    //     btVector3( 2.0f, 0.0f, 2.0f ) ), "textures/Cube_RockWall.jpg" ) );
    for( unsigned int y = 0; y < m_maze[0].size(); ++y )
    {
        for( unsigned int x = 0; x < m_maze.size(); ++x )
        {
            if( m_maze[x][y] == MazeGenerator::WALL )
            {
                m_cells.push_back( new Cell( btTransform( btQuaternion( 0, 0, 0, 1 ), 
                    btVector3( xpos, 2.0f, zpos ) ), "textures/Cube_RockWall.jpg" ) );
            }
            else if ( m_maze[x][y] == MazeGenerator::FLOOR )
            {
                m_cells.push_back( new Cell( btTransform( btQuaternion( 0, 0, 0, 1 ), 
                    btVector3( xpos, 0.0f, zpos ) ), "textures/Cube_DirtFloor.jpg" ) );
            }
            xpos += 2.0f;
        }
        xpos = 0.0f;
        zpos += 2.0f;
    }

    // // North
    // for( float i = -2.0f; i <= m_maze.size() * 2.0f; i += 2.0f )
    //     m_cells.push_back( new Cell( btTransform( btQuaternion( 0, 0, 0, 1 ), 
    //                 btVector3( i, 2.0f, -2.0f ) ), "textures/Cube_RockWall.jpg" ) );
    // // South
    // for( float i = -2.0f; i <= m_maze.size() * 2.0f; i += 2.0f )
    //     m_cells.push_back( new Cell( btTransform( btQuaternion( 0, 0, 0, 1 ), 
    //                 btVector3( i, 2.0f, m_maze[0].size() * 2.0f ) ), "textures/Cube_RockWall.jpg" ) );

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