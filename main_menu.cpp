#include<iostream>
#include "main_menu.h"

MainMenu::MainMenu(){}

void MainMenu::print(std::string &test){
    test = "Hello world!\n";
}

bool MainMenu::initalize(SDL_Window* window){
    bool succ = false;
    // already initialized sdl so dont need to initialize it again.

    mainmenu_surface = SDL_GetWindowSurface(window);

    return succ;
}

