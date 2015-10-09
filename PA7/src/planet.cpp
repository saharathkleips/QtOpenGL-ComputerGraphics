//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 


Planet::Planet()
{
    m_texturePath = ":/texture/earth.jpg";
    m_fShaderPath = ":/shader/simple.fs";
    m_vShaderPath = ":/shader/simple.vs";

    loadModel( MODEL_PATH, model, numVertices );
}

Planet::Planet( QString texturePath )
    :   m_texturePath( texturePath )
{
    m_fShaderPath = ":/shader/simple.fs";
    m_vShaderPath = ":/shader/simple.vs";

    loadModel( MODEL_PATH, model, numVertices );
}

Planet::Planet( QString texturePath, QString fShaderPath, QString vShaderPath)
    :   m_texturePath( texturePath ), m_fShaderPath( fShaderPath ),
        m_vShaderPath( vShaderPath )
{
    loadModel( MODEL_PATH, model, numVertices );
}

Planet::~Planet()
{
    teardownGL();
}

//
// RENDERABLE FUNCTIONS ////////////////////////////////////////////////////////
// 

void initializeGL()
{

}

void paintGL( Camera3D& camera, QMatrix4x4& projection )
{

}

void update()
{

}

void teardownGL()
{

}