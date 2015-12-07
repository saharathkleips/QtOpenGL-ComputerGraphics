#include "mazeGenerator.h"

#define Grid std::vector< std::vector<int> >
#define Cell std::tuple<int, int>
#define row( x ) std::get<0>( x ) 
#define col( x ) std::get<1>( x ) 

Grid MazeGenerator::makeMaze( int seed, int width, int height )
{
    srand( seed );

    Grid maze( width, std::vector<int>( height, WALL ) );
    std::list<Cell> workers;

    workers.push_back( std::make_tuple( width / 2, height / 2 ) );
    while( workers.size() > 0 )
    {
        std::list<Cell>::iterator iter = workers.begin();

        while( iter != workers.end() )
        {
            bool removeWorker = false;

            switch( rand() % 4 )
            {
                case 0:
                    col( *iter ) -= 2;
                    if( col( *iter ) < 0 || 
                        maze[row( *iter )][col( *iter )] == FLOOR )
                    {
                        removeWorker = true;
                        break;
                    }
                    maze[row( *iter )][col( *iter ) + 1] = FLOOR;
                    break;
                case 1:
                    col( *iter ) += 2;
                    if( col( *iter ) >= height || 
                        maze[row( *iter )][col( *iter )] == FLOOR )
                    {
                        removeWorker = true;
                        break;
                    }
                    maze[row( *iter )][col( *iter ) - 1] = FLOOR;
                    break;
                case 2:
                    row( *iter ) -= 2;
                    if( row( *iter ) < 0 || 
                        maze[row( *iter )][col( *iter )] == FLOOR )
                    {
                        removeWorker = true;
                        break;
                    }
                    maze[row( *iter ) + 1][col( *iter )] = FLOOR;
                    break;
                case 3:
                    row( *iter ) += 2;
                    if( row( *iter ) >= width || 
                        maze[row( *iter )][col( *iter )] == FLOOR )
                    {
                        removeWorker = true;
                        break;
                    }
                    maze[row( *iter ) - 1][col( *iter )] = FLOOR;
                    break;
            }

            if( removeWorker )
                iter = workers.erase( iter );
            else
            {
                workers.push_back( 
                    std::make_tuple( row( *iter ), col( *iter ) ) );
                workers.push_back( 
                    std::make_tuple( row( *iter ), col( *iter ) ) );
                workers.push_back( 
                    std::make_tuple( row( *iter ), col( *iter ) ) );
                workers.push_back( 
                    std::make_tuple( row( *iter ), col( *iter ) ) );

                maze[row( *iter )][col( *iter )] = FLOOR;
                ++iter;
            }
        }
    }

    maze[width / 2][height / 2] = START;

    switch( rand() % 4 )
    {
        case 0:
            for(int i = 0; i < std::min(width, height); i++)
            {
                if( maze[i][i] == FLOOR )
                {
                    maze[i][i] = END;
                    break;
                }
            }
            break;
        case 1:
            for(int i = 0; i < std::min(width, height); i++)
            {
                if( maze[width - i - 1][i] == FLOOR )
                {
                    maze[width - i - 1][i] = END;
                    break;
                }
            }
            break;
        case 2:
            for(int i = 0; i < std::min(width, height); i++)
            {
                if( maze[i][height - i - 1] == FLOOR )
                {
                    maze[i][height - i - 1] = END;
                    break;
                }
            }
            break;
        case 3:
            for(int i = 1; i < std::min(width, height); i++)
            {
                if( maze[width - i][height - i] == FLOOR )
                {
                    maze[width - i][height - i] = END;
                    break;
                }
            }
            break;
    }

    return maze;
}

void MazeGenerator::printMaze( Grid maze )
{
    for( unsigned int y = 0; y < maze[0].size(); ++y )
    {
        for( unsigned int x = 0; x < maze.size(); ++x )
        {
            if( maze[x][y] == FLOOR )
                std::cout << "-";
            else if(  maze[x][y] == WALL )
                std::cout << "|";
            else
                std::cout << "*";
        }
        std::cout << std::endl;
    }
}

#undef Grid
#undef Cell
#undef row
#undef col