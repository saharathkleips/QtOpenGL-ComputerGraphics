#include "ShaderLoader.h"

ShaderLoader::ShaderLoader(std::string _pathVertexShader, 
    std::string _pathFragmentShader)
{
    pathVertexShader = _pathVertexShader;
    pathFragmentShader = _pathFragmentShader;
}

GLuint ShaderLoader::loadShader()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    //Read Shader
    std::string strVertexShader = loadFile(pathVertexShader);
    std::string strFragmentShader = loadFile(pathFragmentShader);
    const char* cStrVertexShader = strVertexShader.c_str();
    const char* cStrFragmentShader = strFragmentShader.c_str();

    GLint result = GL_FALSE;
    int logLength;

    //Compile Vertex Shader
    glShaderSource(vertexShader, 1, &cStrVertexShader, NULL);
    glCompileShader(vertexShader);

    //Check Vertex Shader
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> vertexShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(vertexShader, logLength, NULL, &vertexShaderError[0]);
    std::cerr << &vertexShaderError[0] << std::endl;

    //Compile Fragment Shader
    glShaderSource(fragmentShader, 1, &cStrFragmentShader, NULL);
    glCompileShader(fragmentShader);

    //Check Fragment Shader
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> fragmentShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(fragmentShader, logLength, NULL, 
        &fragmentShaderError[0]);
    std::cerr << &fragmentShaderError[0] << std::endl;

    //Link Program
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> programError( (logLength > 1) ? logLength : 1);
    glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
    std::cerr << &programError[0] << std::endl;

    //Return Program
    return program;
}

std::string ShaderLoader::loadFile(std::string path)
{
    std::ifstream file;
    file.open(path);
    if(!file.is_open())
        throw std::runtime_error("Could not open file: " + path);

    std::string fileContents;
    while(file.good())
    {
        fileContents += file.get();
    }

    return fileContents;
}