#ifndef MAZE_GENERATOR
#define MAZE_GENERATOR

#include <vector>
#include <list>
#include <tuple>

#define START 0
#define END 1
#define FLOOR 2
#define WALL 3

namespace MazeGenerator
{
    std::vector< std::vector< int > > makeMaze( int seed, int width, 
        int height );
}

#endif  //  MAZE_GENERATOR