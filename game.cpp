#include <iostream>
#include "game.h"

using namespace std;

// constructor
Game::Game(){}

// destructor
Game::~Game(){}

void Game::initialize(char* title, int xpos, int ypos, int width, int height){
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        // string t = title;
        cout << "SDL Initialized correctly.\n";
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
        
        if(window){
            cout << "Window created successfully!\n";
        }
        else{
            cout << "Error: " << SDL_GetError() << endl;
            exit(-1);
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
            cout << "Renderer created successfully!\n";
        }
        else{
            cout << "ERROR: " << SDL_GetError() << endl;
            exit(-1);
        }
    }
    else{
        cout << "ERROR: " << SDL_GetError() << endl;
        exit(-1);
    }
    isRunning = true;
}

void Game::EventHandler(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::update(){
    // test_counter++;
    // cout << test_counter << endl;
}

void Game::render(){
    SDL_RenderClear(renderer);
    
    // we would add stuff to render here

    SDL_RenderPresent(renderer);
}

void Game::close(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned!\n";
}

bool Game::running(){
    return isRunning;
}


void Game::test_print(){
    cout << "Hello world!\n";
}