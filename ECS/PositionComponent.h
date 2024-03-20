#ifndef POSITIONCOMPONENTS_H
#define POSITIONCOMPONENTS_H

#include "Components.h"

class TransformComponent : public Component
{
private:
    int xpos;
    int ypos;

public:
    TransformComponent()
    {
        xpos = 0;
        ypos = 0;
    }

    TransformComponent(int x, int y)
    {
        xpos = x;
        ypos = y;
    }

    int x() { return xpos; }
    void x(int x) { xpos = x; }
    int y() { return ypos; }
    void y(int y) { ypos = y; }

    void update() override
    {
        xpos++;
        ypos++;
    } // update

    void setPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    } // setPos
};

#endif
