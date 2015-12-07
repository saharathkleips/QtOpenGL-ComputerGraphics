#include "labyrinth.h"
#include <QFileInfo>
Labyrinth::Labyrinth( Environment env, int seed, int width, int height )
    :   m_env( env ), m_seed( seed ), m_width( width ), m_height( height )
{
    m_maze = MazeGenerator::makeMaze( m_seed, m_width, m_height );


    player = new QMediaPlayer(); 
      
    QString file;  
    if( m_env == Environment::Rock ){
        file = "sounds/rock.mp3";
    }
    else{
        file = "sounds/ice.mp3";
    }

    QUrl url = QUrl::fromLocalFile(QFileInfo(file).absoluteFilePath());
    player->setMedia(url);
    player->setVolume(800); 
    player->play();
}

void Labyrinth::addRigidBodys( btDiscreteDynamicsWorld* dynamicsWorld )
{
    for( Cell* cell : m_cells )
        dynamicsWorld->addRigidBody( cell->RigidBody );
}

void Labyrinth::initializeGL()
{
    float xpos = 0.0f, zpos = 0.0f;
    for( unsigned int y = 0; y < m_maze[0].size(); ++y )
    {
        for( unsigned int x = 0; x < m_maze.size(); ++x )
        {
            if( m_maze[x][y] == MazeGenerator::WALL )
            {
                if( m_env == Environment::Rock )
                    m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3( xpos, 2.0f, zpos ) ), Cell::getRandomRockWall() ) );
                else if( m_env == Environment::Ice )
                    m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3( xpos, 2.0f, zpos ) ), Cell::getRandomIceWall() ) );
            }
            else if ( m_maze[x][y] == MazeGenerator::FLOOR || m_maze[x][y] == MazeGenerator::START )
            {
                if( m_env == Environment::Rock )
                    m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3( xpos, 0.0f, zpos ) ), Texture::DirtFloor ) );
                else if( m_env == Environment::Ice )
                    m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3( xpos, 0.0f, zpos ) ), Texture::SnowFloor ) );
            }
            xpos += 2.0f;
        }
        xpos = 0.0f;
        zpos += 2.0f;
    }

    if( m_env == Environment::Rock )
    {
        // North
        for( float i = -2.0f; i <= m_maze.size() * 2.0f; i += 2.0f )
            m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3( i, 2.0f, -2.0f ) ), Cell::getRandomRockWall() ) );
        // South
        for( float i = -2.0f; i <= m_maze.size() * 2.0f; i += 2.0f )
            m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3( i, 2.0f, m_maze[0].size() * 2.0f ) ), Cell::getRandomRockWall() ) );
        // East
        for( float i = 0.0f; i < m_maze.size() * 2.0f; i += 2.0f )
            m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3( -2.0, 2.0f, i ) ), Cell::getRandomRockWall() ) );
        // West
        for( float i = -2.0f; i < m_maze.size() * 2.0f; i += 2.0f )
            m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3(  m_maze[0].size() * 2.0f, 2.0f, i ) ), Cell::getRandomRockWall() ) );
    }
    else if( m_env == Environment::Ice )
    {
        // North
        for( float i = -2.0f; i <= m_maze.size() * 2.0f; i += 2.0f )
            m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3( i, 2.0f, -2.0f ) ), Cell::getRandomIceWall() ) );
        // South
        for( float i = -2.0f; i <= m_maze.size() * 2.0f; i += 2.0f )
            m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3( i, 2.0f, m_maze[0].size() * 2.0f ) ), Cell::getRandomIceWall() ) );
        // East
        for( float i = 0.0f; i < m_maze.size() * 2.0f; i += 2.0f )
            m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3( -2.0, 2.0f, i ) ), Cell::getRandomIceWall() ) );
        // West
        for( float i = -2.0f; i < m_maze.size() * 2.0f; i += 2.0f )
            m_cells.push_back( new Cell( btTransform( getRandomRotation(), 
                        btVector3(  m_maze[0].size() * 2.0f, 2.0f, i ) ), Cell::getRandomIceWall() ) );
    }
    

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

    if(QMediaPlayer::StoppedState){
        player->play();
    }
}

void Labyrinth::teardownGL()
{
    for( Cell* cell : m_cells )
        cell->teardownGL();
}

Environment Labyrinth::getRandomEnvironment()
{
    switch( rand() % 2 )
    {
        case 0:
            return Environment::Rock;
            break;
        case 1:
            return Environment::Ice;
            break;
        default:
            return Environment::Rock;
            break;
    }
}

btQuaternion Labyrinth::getRandomRotation()
{
    switch( rand() % 4 )
    {
        case 0:
            return btQuaternion( 1, 0, 0, 1 );
            break;
        case 1:
            return btQuaternion( 0, 1, 0, 1 );
            break;
        case 2:
            return btQuaternion( 0, 0, 1, 1 );
            break;
        case 3:
            return btQuaternion( 0, 0, 0, 1 );
            break;
        default:
            return btQuaternion( 0, 0, 0, 1 );
            break;
    }
}