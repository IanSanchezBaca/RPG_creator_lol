#ifndef GAME_H
#define GAME_H

class Game
{
    Game();
    ~Game();

    void initialize(std::string title,
                    int xpos,
                    int ypos,
                    int width,
                    int height);
};

#endif