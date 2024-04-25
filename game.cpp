#include "game.h"

SDL_Renderer *Game::renderer = NULL;
SDL_Event Game::event;

Game::Game() {}

void Game::initialize(string title, int xpos, int ypos, int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        // string t = title;
        cout << "SDL Initialized correctly.\n";

        window = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, SDL_WINDOW_SHOWN);

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
    }
    else
    {
        cout << "ERROR: " << SDL_GetError() << endl;
        exit(-1);
    }
    isRunning = true;
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

        if (event.button.button == SDL_BUTTON_LEFT)
        {
            // Get the mouse coordinates
            x = event.button.x;
            y = event.button.y;
            cout << "mouse was clicked at pos: " << x << " " << y << "\n";
            round();
            cout << "rounded up it's: " << x << " " << y << "\n";
        }

        break;

    default:
        break;
    }
}

void Game::update()
{
    // cout << "Updating...\n";
}

void Game::render()
{
    // cout << "Rendering...\n";
}

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

void Game::round()
{
    // double dx = x;
    // double dy = y;

    x = (x / 32);
    x = x * 32;
    y = (y / 32);
    y = y * 32;

    // x = dx;
    // y = dy;

} // round