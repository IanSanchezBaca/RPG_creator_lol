#include<iostream>
#include "main_menu.h"

MainMenu::MainMenu(){}

void MainMenu::print(std::string &test){
    test = "Hello world!\n";
}

bool MainMenu::initalize(){
    bool succ = true;

    // if(SDL_Init(SDL_INIT_VIDEO) < 0){
    //     // make sure that sdl initializes
    //     printf("SDL could not initialize! SDL_Error: %s", SDL_GetError());
        
    //     succ = false;
    // }
    // else{
    //     // create window
    //     mainmenu_window = SDL_CreateWindow("RpgCreator")
    // }
    return succ;
}

