#ifndef SHADERPATHS_H
#define SHADERPATHS_H
#include <iostream>

// |-- SHADERS ----------------------------------------------|

#if defined(_WIN32)
    std::string TexturedShadersPath = "shaders\\textured\\";
    std::string FlatShadersPath = "shaders\\flat\\";
#elif defined(__linux__)
    std::string TexturedShadersPath = "shaders/textured/";
    std::string FlatShadersPath = "shaders/flat/";
#endif

std::string tvName = "texturedVertex.glsl";
std::string tfName = "texturedFragment.glsl";
std::string fvName = "flatVertex.glsl";
std::string ffName = "flatFragment.glsl";

// |-- TEXTURES ---------------------------------------------|

#if defined(_WIN32)
    std::string TexturesPath = "textures\\";
#elif defined(__linux__)
    std::string TexturesPath = "textures/";
#endif

std::string defaultTexture = TexturesPath + "texture.png";

#endif