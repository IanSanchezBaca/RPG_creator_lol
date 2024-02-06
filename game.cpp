#include <iostream>
#include "game.h"

using namespace std;

// constructor
Game::Game(){}

// destructor
Game::~Game(){}

void Game::initialize(string title, int xpos, int ypos, int width, int height){
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        string t = title;
        cout << "SDL Initialized correctly.\n";
        window = SDL_CreateWindow("RPG_Creator", xpos, ypos, width, height, SDL_WINDOW_SHOWN);
        if(window){
            cout << "Window created successfully!\n";
        }
        else{
            cout << "Error: " << SDL_GetError() << endl;
            exit(-1);
        }
    }
    else{
        cout << "ERROR: " << SDL_GetError() << endl;
        exit(-1);
    }
}

void Game::EventHandler(){}

void Game::update(){}

void Game::render(){}

void Game::close(){}

bool Game::running(){
    return isRunning;
}


void Game::test_print(){
    cout << "Hello world!\n";
}