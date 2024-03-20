#include <iostream>
#include "game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2d.h"
#include "Collision.h"
using namespace std;

Map *map;
Manager manager;

SDL_Renderer *Game::renderer = NULL;

SDL_Event Game::event;

auto &player(manager.addEntity());
auto &wall(manager.addEntity());

// constructor
Game::Game() {}

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

    map = new Map();

    // ecs implementation
    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>("media/characters/Rito.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("Player");

    wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
    wall.addComponent<SpriteComponent>("media/background/dirt.png");
    wall.addComponent<ColliderComponent>("wall");

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
    test_counter++;
    // just a simple counter
    manager.refresh();
    manager.update();

    // player.getComponent<TransformComponent>().position.Add(Vector2D(5, 0));

    // if (player.getComponent<TransformComponent>().position.x > 100)
    // {
    //     player.getComponent<SpriteComponent>().setTex("media/characters/Rito_P2.png");
    // }
} // update

/* So the way drawing works is
 * that whatever you draw first
 * is behind whatever you draw next */
void Game::render()
{
    SDL_RenderClear(renderer);
    // we would add stuff to render here

    map->DrawMap();

    manager.draw();

    SDL_RenderPresent(renderer);
} // render

void Game::close()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned!\n";
    cout << "Counter: " << test_counter << endl;
} // close

bool Game::running()
{
    return isRunning;
} // running

void Game::test_print()
{
    cout << "Hello world!\n";
} // test_print