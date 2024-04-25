#include "game.h"

SDL_Renderer *Game::renderer = NULL;
SDL_Event Game::event;

Game::Game() {}

void Game::initialize(std::string title, int xpos, int ypos, int width, int height)
{
    /* INITIALIZING SDL */
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        // string t = title;
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

    /* INITIALIZING THE GRAPH
     * - set all of them to -1 at start */
    for (int i = 0; i < 20; i++) // y?
    {
        vect<int> temp(25, -1);
        grapha.push_back(temp);
    }

} // initialize

void Game::EventHandler()
{
    SDL_PollEvent(&event);
    /* check if the user pressed alt-f4 or hit the close button */
    if (event.type == SDL_QUIT)
    {
        isRunning = false;
        return;
    }

    /* Switch statement for the good stuff??? */
    switch (event.type)
    {

    case SDL_MOUSEBUTTONDOWN:

        if (event.button.button == SDL_BUTTON_LEFT) // left click
        {
            // Get the mouse coordinates
            x = event.button.x;
            y = event.button.y;
            std::cout << "mouse was clicked at pos: (" << x << ", " << y << ")\n";
            round();
            std::cout << "rounded up it's: (" << x << ", " << y << ")\n";

            std::cout << "at that coordinate Grapha is: " << grapha[y][x] << "\n";

            rightClick = true;
        }

        if (event.button.button == SDL_BUTTON_RIGHT) // right click
        {
            std::cout << "Right click is currently a WIP\n";

            // leftClick = true;
        }

        break;

    default:
        break;
    }
}

void Game::update()
{
    if (!(x == -1) && !(y == -1))
    {
        if (rightClick)
        {
            grapha[y][x] = 1;
            rightClick = false;
        }
    }
}

void Game::render()
{

    SDL_RenderClear(renderer);

    // SDL_SetRenderDrawColor(renderer, 0, 0, deleteMe, 0);
    // testing something

    SDL_RenderPresent(renderer);
}

void Game::close()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!\n";
    // std::cout << "Counter: " << test_counter <<std::endl;
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
