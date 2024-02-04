#include <iostream>
#include <SDL2/SDL.h> // The sdl library
#include <stdio.h>
#include "main_menu.h"
/* i forgot how to use .h files lol */

using namespace std;

bool main_init(){
    bool succ = true;

    //Initialized SDL
    if( SDL_Init(SDL_INIT_VIDEO) < 0 ){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        succ = false;
    }
    else{
        //Create Window

        
    }

    return succ;
}

int main(){
    SDL_Window* main_window = NULL;
    

    MainMenu test;
    test.print();
    return 0;
}