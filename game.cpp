#include "game.h"

SDL_Renderer *Game::renderer = NULL;
SDL_Event Game::event;

Game::Game() {}

void Game::initialize(string title, int xpos, int ypos, int width, int height)
{
    /* INITIALIZING SDL */
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

    /* INITIALIZING THE GRAPH */
    for (int i = 0; i < 20; i++) // y?
    {
        vector<int> temp(25, -1);
        grapha.push_back(temp);
        // cout << i << ": ";

        // for (int j = 0; j < 25; j++) // x?
        // {
        //     // cout << j << " ";
        // }
        // cout << "\n";
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
            cout << "mouse was clicked at pos: (" << x << ", " << y << ")\n";
            round();
            cout << "rounded up it's: (" << x << ", " << y << ")\n";

            cout << "at that coordinate Grapha is: " << grapha[y][x] << "\n";

            rightClick = true;
        }

        if (event.button.button == SDL_BUTTON_RIGHT) // right click
        {
            cout << "Right click is currently a WIP\n";

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
    cout << "Game cleaned!\n";
    // cout << "Counter: " << test_counter << endl;
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
