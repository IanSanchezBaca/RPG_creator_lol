#include <iostream>
#include "game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2d.h"
#include "Collision.h"
using namespace std;

Map *myMap;
Manager manager;

SDL_Renderer *Game::renderer = NULL;

SDL_Event Game::event;

std::vector<ColliderComponent *> Game::colliders;

auto &player(manager.addEntity());
auto &wall(manager.addEntity());

enum groupLabels : std::size_t
{
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders
};

// constructor
Game::Game()
{
}

// destructor
Game::~Game() {}

void Game::initialize(char *title, int xpos, int ypos, int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        // string t = title;
        cout << "SDL Initialized correctly.\n";

        window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);

        if (window)
        {
            cout << "Window created successfully!\n";
        }
        else
        {
            cout << "Error: " << SDL_GetError() << endl;
            exit(-1);
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created successfully!\n";
        }
        else
        {
            cout << "ERROR: " << SDL_GetError() << endl;
            exit(-1);
        }
        isRunning = true;
    }
    else
    {
        cout << "ERROR: " << SDL_GetError() << endl;
        exit(-1);
    }

    myMap = new Map();

    /* ecs implementation */

    Map::LoadMap("media/TileMaps/TestTileMap.txt", 16, 16); // change the map

    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("media/characters/RitoAnim.png", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("Player");
    player.addGroup(groupPlayers);

    wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
    wall.addComponent<SpriteComponent>("media/background/dirt.png");
    wall.addComponent<ColliderComponent>("wall");
    wall.addGroup(groupMap);

} // initialize

void Game::EventHandler()
{
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;
    }
} // EventHandler

void Game::update()
{
    // test_counter++; // just a simple counter
    manager.refresh();
    manager.update();

    for (auto cc : colliders)
    {
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
        // {
        // player.getComponent<TransformComponent>().scale = 1;
        player.getComponent<TransformComponent>().velocity * -1;
        // std::cout << "Wall Hit!\n";
        // }
    }

} // update

auto &tiles(manager.getGroup(groupMap));
auto &players(manager.getGroup(groupPlayers));
auto &enemies(manager.getGroup(groupEnemies));

/* So the way drawing works is
 * that whatever you draw first
 * is behind whatever you draw next */
void Game::render()
{
    SDL_RenderClear(renderer);

    for (auto &t : tiles)
    {
        t->draw();
    }
    for (auto &p : players)
    {
        p->draw();
    }
    for (auto &e : enemies)
    {
        e->draw();
    }

    SDL_RenderPresent(renderer);
} // render

void Game::close()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned!\n";
    // cout << "Counter: " << test_counter << endl;
} // close

bool Game::running()
{
    return isRunning;
} // running

void Game::AddTile(int id, int x, int y)
{
    auto &tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, id);
    tile.addGroup(groupMap);
} // AddTile

void Game::test_print()
{
    cout << "Hello world!\n";
} // test_print