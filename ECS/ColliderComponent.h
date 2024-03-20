#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <string>
#include "SDL2/SDL.h"
#include "Components.h"

class ColliderComponent : public Component
{
private:
    /* data */
public:
    ColliderComponent(/* args */);
    ~ColliderComponent();

    SDL_Rect collider;
    std::string tag;

    TransformComponent *transform;

    void init() override
    {
        if (!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override
    {
        collider.x = transform->position.x;
        collider.y = transform->position.y;

        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }
};

ColliderComponent::ColliderComponent(/* args */)
{
}

ColliderComponent::~ColliderComponent()
{
}

#endif