#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SDL2/SDL.h> // THE SDL LIBRARY

class MainMenu
{
public:
    MainMenu();
    
    void print(std::string &test); // test function

    /* create main_menu surface */
    bool initalize(SDL_Window *);
    

    /* loads the media */
    bool loadMedia();

    /* Frees media and shuts down SDL */
    void close();

private:
    /* the window to render to */
    // SDL_Window* mainmenu_window = NULL;

    /* The surface containd by the window */
    SDL_Surface* mainmenu_surface = NULL;

    

};

#endif
