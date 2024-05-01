#include "Map.h"

Map::Map()
{
    for (int i = 0; i < 20; i++) // y?
    {
        vect<int> temp(25, 0);
        grapha.push_back(temp);
    }

    /* temporary preloading */
    rainbow.resize(4);
    rainbow[0] = TextureManager::LoadTexture(DEFAULT);
    rainbow[1] = TextureManager::LoadTexture(WATER);
    rainbow[2] = TextureManager::LoadTexture(DIRT);
    rainbow[3] = TextureManager::LoadTexture(GRASS);

    name.resize(4);
    name[0] = "default";
    name[1] = "water";
    name[2] = "dirt";
    name[3] = "grass";

    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;
    dest.w = 32;
    dest.h = 32;
    dest.x = 0;
    dest.y = 0;
}

void Map::drawMap()
{
    for (int i = 0; i < (int)grapha.size(); i++)
    {
        for (int j = 0; j < (int)grapha[i].size(); j++)
        {
            dest.x = j * 32;
            dest.y = i * 32;
            TextureManager::Draw(rainbow[grapha[i][j]], src, dest);
        }
    }
} // drawMap

void Map::updateMap(int x, int y, int type)
{
    grapha[y][x] = type;
} // updateMap

void Map::whatType(int type)
{
    std::cout << "Currently on " << name[type] << ".\n";
}