#include "Map.h"
#include "TextureManager.h"

int lvl_test[20][25] = {
{0,2,2,1,1,2,0,2,2,0,0,1,2,0,2,2,2,1,1,0,0,0,0,1,2},
{2,0,0,2,2,2,0,0,1,0,0,0,2,2,1,0,1,0,0,1,0,1,0,0,1},
{1,1,2,2,0,1,2,2,1,0,0,0,1,2,0,1,2,0,0,2,0,2,2,1,1},
{2,1,2,1,1,1,1,0,2,2,0,0,1,1,0,0,0,2,0,2,2,0,1,1,0},
{1,1,0,1,2,1,0,2,0,2,1,2,2,2,0,0,0,0,1,0,0,2,2,0,0},
{1,0,2,0,1,1,1,2,2,0,1,0,1,2,1,2,2,2,0,0,0,2,0,0,0},
{2,0,1,1,1,1,2,2,1,0,0,1,1,2,0,1,0,1,2,1,1,1,2,1,2},
{1,1,2,0,2,0,2,1,0,2,0,1,2,0,0,2,1,2,0,2,0,1,0,1,0},
{2,2,2,1,2,0,1,0,2,1,1,0,1,1,0,0,1,2,1,1,1,0,1,2,2},
{2,1,1,2,1,2,0,0,2,1,0,1,0,0,1,1,0,1,0,2,2,2,1,0,2},
{2,0,1,0,0,0,1,1,2,0,2,0,0,0,2,2,1,2,0,0,0,0,2,1,1},
{2,1,0,1,0,0,2,2,1,1,0,2,0,2,1,1,2,1,2,0,0,0,0,0,1},
{2,0,2,0,0,0,1,2,1,1,0,2,1,1,1,1,0,0,0,0,0,0,1,1,2},
{2,0,1,1,1,2,2,0,1,0,1,2,0,0,2,0,0,1,2,2,1,1,1,2,2},
{0,1,2,0,0,0,0,0,1,2,2,0,1,0,0,1,0,0,2,1,1,0,1,0,2},
{2,0,1,0,0,0,1,1,1,0,1,1,0,0,0,2,2,1,2,0,1,2,0,2,1},
{0,2,2,0,2,0,1,0,2,1,0,2,0,2,1,0,1,2,1,0,1,1,2,0,0},
{2,1,2,1,1,0,2,0,1,1,2,1,2,0,2,1,1,1,1,0,0,1,2,0,1},
{2,2,0,0,2,1,1,1,1,1,2,0,2,1,2,0,0,0,0,1,0,0,0,1,2},
{1,2,1,2,1,0,1,2,0,2,1,1,2,2,1,0,0,1,2,1,0,0,1,2,2}
};

Map::Map()
{
    dirt = TextureManager::LoadTexture("media/background/dirt.png");
    grass = TextureManager::LoadTexture("media/background/grass.png");
    water = TextureManager::LoadTexture("media/background/water.png");

    LoadMap(lvl_test);
    src.x = 0;
    src.y = 0;

    src.w = 32;
    dest.w = 32;
    
    src.h = 32;
    dest.h = 32;

    dest.x = 0;
    dest.y = 0;
} // Map

Map::~Map()
{
}

void Map::LoadMap(int arr[20][25])
{
    for (int row = 0; row < 20; row++)
    {
        for (int column = 0; column < 25; column++)
        {
            map[row][column] = arr[row][column];
            dest.x = column * 32;
            dest.y = row * 32;
        } // column
    }     // row
} // LoadMap

void Map::DrawMap()
{
    int type = 0;

    for (int row = 0; row < 20; row++)
    {
        for (int column = 0; column < 25; column++)
        {
            type = map[row][column];
            
            dest.x = column * 32;
            dest.y = row * 32;

            switch (type)
            {
            case 0:
                TextureManager::Draw(water, src, dest);
                break;
            case 1:
                TextureManager::Draw(dirt, src, dest);
                break;
            case 2:
                TextureManager::Draw(grass, src, dest);
                break;
            default:
                break;
            }


        } // column
    }     // row

} // DrawMap