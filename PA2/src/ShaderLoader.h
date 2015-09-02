#ifndef _SHADER_LOADER_H
#define _SHADER_LOADER_H

#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#endif

class ShaderLoader
{
public:
    ShaderLoader(std::string, std::string);
    GLuint loadShader();

private:
    std::string loadFile(std::string);

    std::string pathVertexShader;
    std::string pathFragmentShader;
};