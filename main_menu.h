#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SDL2/SDL.h> // THE SDL LIBRARY

class MainMenu
{
public:
    MainMenu();
    void print(); // test function

    /* start up SDL and create window */
    // bool initalize();

    /* loads the media */
    bool loadMedia();

    /* Frees media and shuts down SDL */
    void close();

// private:
    /* the window to render to */
    SDL_Window* mainmenu_window = NULL;

    /* The surface containd by the window */
    SDL_Surface* mainmenu_surface = NULL;

    

};

#endif
