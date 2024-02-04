#include <iostream>
#include <SDL2/SDL.h> // The sdl library
#include <stdio.h>
#include "main_menu.h"
/* i forgot how to use .h files lol */

using namespace std;

// bool main_init(SDL_Window *mw){
//     // only initialize the window
//     bool succ = true;

//     //Initialized SDL
//     if( SDL_Init(SDL_INIT_VIDEO) < 0 ){
//         printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
//         succ = false;
//     }
//     else{
//         //Create Window

        
//     }

//     return succ;
// }

int main(){
    // SDL_Window* main_window = NULL;
    
    // main_init(main_window);

    MainMenu test;
    
    string test_string;
    
    test.print(test_string);

    cout << test_string;

    return 0;
}