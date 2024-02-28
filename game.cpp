#include <iostream>
#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
// #include "SDL2/SDL_image.h"

using namespace std;

GameObject * player;
GameObject * player2;
// these are for examples

Map* map;

SDL_Renderer* Game::renderer = NULL;



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
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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

    // SDL_Surface* tempSurface = IMG_Load("media/characters/test_char.png");
    // playerTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    // SDL_FreeSurface(tempSurface);

    // playerTex = TextureManager::LoadTexture("media/characters/test_char.png", renderer);  
    // no longer needed 

    player = new GameObject("media/characters/test_char.png", 0, 0);
    player2 = new GameObject("media/characters/test_char_P2.png", 50, 50);
    map = new Map();

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
    test_counter++;
    
    // destR.h = 100;
    // destR.w = 100;
    // destR.x = test_counter;
    // cout << test_counter << endl;
    // no longer needed as gameobect takes care of this

    player->Update();
    player2->Update();
}

void Game::render(){
    SDL_RenderClear(renderer);
    // we would add stuff to render here

    map->DrawMap();
    // draw the map first

    player->Render();
    player2->Render();
    // then draw players on top of it

    SDL_RenderPresent(renderer);
}

void Game::close(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned!\n";
    cout << "Counter: " << test_counter << endl;
}

bool Game::running(){
    return isRunning;
}


void Game::test_print(){
    cout << "Hello world!\n";
}