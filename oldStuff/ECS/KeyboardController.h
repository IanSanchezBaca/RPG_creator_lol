#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H
#include "../game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;
    void init() override
    {
        std::cout << "Initializing the Keyboard!\n";
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }

    void update() override
    {

        if (Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w: // up
                transform->velocity.y = -1;
                sprite->Play("Walk");
                // std::cout << "walking up.\n";
                break;
            case SDLK_a: // left
                transform->velocity.x = -1;
                sprite->Play("Walk");
                sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                break;
            case SDLK_s: // down
                transform->velocity.y = 1;
                sprite->Play("Walk");
                break;
            case SDLK_d: // right
                transform->velocity.x = 1;
                sprite->Play("Walk");
                break;
            default:
                break;
            }
        }

        if (Game::event.type == SDL_KEYUP)
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->velocity.y = 0;
                sprite->Play("Idle");
                break;
            case SDLK_a:
                transform->velocity.x = 0;
                sprite->Play("Idle");
                sprite->spriteFlip = SDL_FLIP_NONE;
                break;
            case SDLK_s:
                transform->velocity.y = 0;
                sprite->Play("Idle");
                break;
            case SDLK_d:
                transform->velocity.x = 0;
                sprite->Play("Idle");
                break;
            default:
                break;
            }
        }

        /* the mouse stuff */
        if (Game::event.type == SDL_MOUSEBUTTONDOWN)
        {
            std::cout << "mouse clicked ";
            if (Game::event.button.button == SDL_BUTTON_LEFT)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                std::cout << "at position " << x << " " << y << "\n";
                        }
        }
    }
};

#endif