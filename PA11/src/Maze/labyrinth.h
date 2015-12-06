#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <QMatrix4x4>
#include <vector>

#include "Maze/cell.h"
#include "Maze/mazeGenerator.h"

#include "Controls/camera3d.h"


class Labyrinth     :   public Renderable
{
public:
    Labyrinth( int seed, int width, int height );
    void addRigidBodys( btDiscreteDynamicsWorld* const dynamicsWorld, const short group, const short mask );

    // Renderable Functions
    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();

private:
    std::vector< Cell* > m_cells;
    std::vector< std::vector<int> > m_maze;
    int m_seed;
    int m_width, m_height;
};

#endif  //  LABYRINTH_H