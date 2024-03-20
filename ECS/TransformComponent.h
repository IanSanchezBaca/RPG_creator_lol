#ifndef POSITIONCOMPONENTS_H
#define POSITIONCOMPONENTS_H
#include "Components.h"
#include "../Vector2d.h"

struct TransformComponent : public Component
{
public:
    Vector2D position;

    TransformComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    void update() override
    {

    } // update

    //////////////////////////////
    /// Don't need anymore as it is replaced by the Vector2D class
    ///
    // int x() { return xpos; }
    // void x(int x) { xpos = x; }
    // int y() { return ypos; }
    // void y(int y) { ypos = y; }

    // void setPos(int x, int y)
    // {
    //     xpos = x;
    //     ypos = y;
    // } // setPos
};

#endif
