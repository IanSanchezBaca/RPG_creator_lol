#include "game.h"
#include "TextureManager.h"
#include "Map.h"

SDL_Renderer *Game::renderer = NULL;
SDL_Event Game::event;

Map *graph;

// checking folder
namespace fs = std::experimental::filesystem;

Game::Game() {}

void Game::initialize(std::string title, int xpos, int ypos, int width, int height)
{
    /* INITIALIZING SDL */
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL Initialized correctly.\n";

        window = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, SDL_WINDOW_SHOWN);

        if (window)
        {
            std::cout << "Window created successfully!\n";
        }
        else
        {
            std::cout << "Error: " << SDL_GetError() << std::endl;
            exit(-1);
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created successfully!\n";
        }
        else
        {
            std::cout << "ERROR: " << SDL_GetError() << std::endl;
            exit(-1);
        }
    }
    else
    {
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
        exit(-1);
    }
    isRunning = true;
    graph = new Map();

    fs::path p = "media/background";
    std::cout << "Loading sprites inside of " << p << "\n";
    for (const auto &entry : fs::directory_iterator(p))
    {
        std::string tmpName = entry.path();

        graph->addName(tmpName);
    }
    graph->setTextures();
    // isRunning = false;

    graph->whatType(type);

} // initialize

void Game::EventHandler()
{
    SDL_PollEvent(&event);

    /* Switch statement for the good stuff??? */
    switch (event.type)
    {
    case SDL_QUIT:
        /* check if the user pressed alt-f4 or hit the close button */
        isRunning = false;
        return;
        break;

    case SDL_MOUSEBUTTONDOWN:

        if (event.button.button == SDL_BUTTON_LEFT) // left click
        {
            // Get the mouse coordinates
            x = event.button.x;
            y = event.button.y;
            round();
            leftClick = true;
        }
        if (event.button.button == SDL_BUTTON_RIGHT) // right click
        {
            // std::cout << "Right click is currently a WIP\n";
            x = event.button.x;
            y = event.button.y;
            round();
            rightClick = true;
        }
        break;

    case SDL_MOUSEWHEEL:
        // std::cout << "Sroll wheel moved\n";
        if (event.wheel.y > 0)
        {
            // Scroll up
            if (type != 1)
            {
                type--;
                graph->whatType(type);
            }
        }
        else if (event.wheel.y < 0)
        {
            // Scroll down
            if (type != 3)
            {
                type++;
                graph->whatType(type);
            }
        }
        break;

    default:
        break;
    }
}

void Game::update()
{
    if (leftClick)
    {
        leftClick = false;
        graph->updateMap(x, y, type);
    }
    if (rightClick)
    {
        rightClick = false;
        graph->updateMap(x, y, 0);
    }
}

void Game::render()
{

    SDL_RenderClear(renderer);

    graph->drawMap();

    SDL_RenderPresent(renderer);
}

void Game::close()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!\n";
} // close

bool Game::running()
{
    return isRunning;
} // running

void Game::round()
{
    x = (x / 32);
    y = (y / 32);
} // round
