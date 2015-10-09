#include "planet.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 


Planet::Planet()
{
    m_texturePath = ":/texture/earth.jpg";
    m_fShaderPath = ":/shader/simple.fs";
    m_vShaderPath = ":/shader/simple.vs";

    loadModel( MODEL_PATH, *model, numVertices );
}

Planet::Planet( QString texturePath )
    :   m_texturePath( texturePath )
{
    m_fShaderPath = ":/shader/simple.fs";
    m_vShaderPath = ":/shader/simple.vs";

    loadModel( MODEL_PATH, *model, numVertices );
}

Planet::Planet( QString texturePath, QString fShaderPath, QString vShaderPath)
    :   m_texturePath( texturePath ), m_fShaderPath( fShaderPath ),
        m_vShaderPath( vShaderPath )
{
    loadModel( MODEL_PATH, *model, numVertices );
}

Planet::~Planet()
{
    this->teardownGL();
}

//
// RENDERABLE FUNCTIONS ////////////////////////////////////////////////////////
// 

void Planet::initializeGL()
{
}

void Planet::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    (void)camera;
    (void)projection;}

void Planet::update()
{
}

void Planet::teardownGL()
{
}