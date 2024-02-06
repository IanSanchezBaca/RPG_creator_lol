#include <iostream>
#include <SDL2/SDL.h> // The sdl library
#include <stdio.h>

// h files
// #include "main_menu.h"
#include "game.h"

using namespace std;



int main(int argc, char *args[])
{
    Game key;
    key.initialize("RPG_Creator",
                    0,
                    0,
                    600,
                    400);
    
    

    return 0;
}