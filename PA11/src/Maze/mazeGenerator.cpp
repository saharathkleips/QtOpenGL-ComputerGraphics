#include "mazeGenerator.h"
#include <iostream>
#include <QDebug>

/**
 * @brief      Creates a randomly generated maze which guarantees only one path
 * from one point of the maze to another point. 
 * @details  Start = 0, End = 1, Floor = 2, Wall = 3.
 * 
 * @param[in]  seed    The seed to generate the maze with.
 * @param[in]  width   The width of the maze.
 * @param[in]  height  The height of the maze.
 *
 * @return     A 2D Vector containing integer representations for each element.
 */
std::vector< std::vector< int > > MazeGenerator::makeMaze( int seed, int width, 
    int height )
{
    srand(seed);

    std::vector< std::vector< int > > maze;
    std::list< std::tuple< int, int > > workers;

    maze.resize( width );
    for( int x = 0; x < width; ++x )
        maze[x].resize( height );

    for( int x = 0; x < width; ++x )
        for( int y = 0; y < height; ++y )
            maze[x][y] = WALL;

    workers.push_back( std::make_tuple( width / 2, height / 2 ) );
    while( workers.size() > 0 )
    {
        std::list< std::tuple< int, int > >::iterator iBegin, iEnd,temp;
        iBegin = workers.begin();
        iEnd = workers.end();

        while( iBegin != iEnd )
        {
            bool removeWorker = false;

            switch( rand() % 4 )
            {
                case 0:
                    std::get<0>( *iBegin ) -= 2;
                    if( std::get<0>( *iBegin ) <= 0 || 
                        maze[ std::get<0>( *iBegin ) ]
                            [ std::get<1>( *iBegin ) ] == FLOOR )
                    {
                        removeWorker = true;
                        break;
                    }
                    maze[ std::get<0>( *iBegin ) + 1 ][ std::get<1>( *iBegin ) ]
                        = FLOOR;
                    break;
                case 1:
                    std::get<0>( *iBegin ) += 2;
                    if( std::get<0>( *iBegin ) >= width || 
                        maze[ std::get<0>( *iBegin ) ]
                            [ std::get<1>( *iBegin ) ] == FLOOR )
                    {
                        removeWorker = true;
                        break;
                    }
                    maze[ std::get<0>( *iBegin ) - 1 ][ std::get<1>( *iBegin ) ]
                        = FLOOR;
                    break;
                case 2:
                    std::get<1>( *iBegin ) -= 2;
                    if( std::get<1>( *iBegin ) <= 0 || 
                        maze[ std::get<0>( *iBegin ) ]
                            [ std::get<1>( *iBegin ) ] == FLOOR )
                    {
                        removeWorker = true;
                        break;
                    }
                    maze[ std::get<0>( *iBegin ) ][ std::get<1>( *iBegin ) + 1 ]
                        = FLOOR;
                    break;
                case 3:
                    std::get<1>( *iBegin ) += 2;
                    if( std::get<1>( *iBegin ) >= height || 
                        maze[ std::get<0>( *iBegin ) ]
                            [ std::get<1>( *iBegin ) ] == FLOOR )
                    {
                        removeWorker = true;
                        break;
                    }
                    maze[ std::get<0>( *iBegin ) ][ std::get<1>( *iBegin ) - 1 ]
                        = FLOOR;
                    break;
                default:
                    break;
            }
            if( removeWorker == true ){
                iBegin = workers.erase( iBegin );
            }
            else
            {
                workers.push_back( std::make_tuple( 
                    std::get<0>( *iBegin ), std::get<1>( *iBegin ) ) );
                workers.push_back( std::make_tuple( 
                    std::get<0>( *iBegin ), std::get<1>( *iBegin ) ) );
                
                maze[ std::get<0>( *iBegin ) ][ std::get<1>( *iBegin ) ]
                    = FLOOR;

                ++iBegin;
            }
        }
    }

    for( int y = 0; y < height; ++y )
    {
        for( int x = 0; x < width; ++x )
        {
            if( maze[x][y] == FLOOR )
                std::cout << " ";
            else if( maze[x][y] == WALL )
                std::cout << "|";
            else
                std::cout << "*";
        }
        std::cout << std::endl;
    }

    return maze;
}