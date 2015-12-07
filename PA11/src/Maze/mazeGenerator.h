#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <algorithm>
#include <tuple>
#include <vector>
#include <list>
#include <iostream>

#define Grid std::vector< std::vector<int> >
#define Cell std::tuple<int, int>
#define row( x ) std::get<0>( x ) 
#define col( x ) std::get<1>( x ) 

namespace MazeGenerator
{
    const int START = 0;
    const int END = 1;
    const int WALL = 2;
    const int FLOOR = 3;
    Grid makeMaze( int seed, int width, int height );
    void printMaze( Grid maze );
}

#undef Grid
#undef Cell
#undef row
#undef col

#endif  //  MAZE_GENERATOR_H