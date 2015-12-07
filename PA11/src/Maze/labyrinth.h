#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <QMatrix4x4>
#include <vector>

#include "Maze/cell.h"
#include "Maze/mazeGenerator.h"

#include "Controls/camera3d.h"

#include <QMediaPlayer>


enum Environment
{
    Rock,
    Ice
};

class Labyrinth     :   public Renderable
{
public:
    Labyrinth( Environment env, int seed, int width, int height );
    void addRigidBodys( btDiscreteDynamicsWorld* dynamicsWorld );

    // Renderable Functions
    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();

    static Environment getRandomEnvironment();

private:

    QMediaPlayer *player;

    btQuaternion getRandomRotation();

    Environment m_env;

    std::vector< Cell* > m_cells;
    std::vector< std::vector<int> > m_maze;
    int m_seed;
    int m_width, m_height;
};

#endif  //  LABYRINTH_H