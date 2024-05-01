/// loadMap.h
/// This should draw the map from a vector
///
/// @author: Ian Sanchez Baca
/// @lastmodified: 04/30/24

#ifndef MAP_H
#define MAP_H
#include "game.h"
#include "TextureManager.h"
#include <fstream>

class Map
{
public:
    Map();

    void drawMap();

    void whatType(int);

    void updateMap(int, int, int);

    void addName(std::string);

    void setTextures();

    void saveMap();

private:
    SDL_Rect src, dest;

    vect<vect<int>> grapha; // 25 x 20

    vect<std::string> name; // holds the names of the textures

    /* This holds the textures like
     * dirt
     * water
     * grass
     * default */
    vect<SDL_Texture *> rainbow;
};

#endif