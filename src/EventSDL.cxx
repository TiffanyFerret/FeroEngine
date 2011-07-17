#include "../include/InputManager.h"
#include <SDL/SDL.h>
#include "../include/EventSDL.h"
SDLInputChecker::SDLInputChecker(SDL_Event* _event)
{
    event = _event;
}
bool SDLInputChecker::keyPress(unsigned int key)
{
    if(event->key.type == SDL_KEYDOWN)
    {
        if(event->key.keysym.sym == key)
        {
            return true;
        }
    }
    return false;
}
unsigned int SDLInputChecker::keyUp()
{
    if(event->key.type == SDL_KEYUP)
    {
        return event->key.keysym.sym;
    }
    return 0;
}
unsigned int SDLInputChecker::keyDown()
{
    if(event->key.type == SDL_KEYDOWN)
    {
        return event->key.keysym.sym;
    }
    return 0;
}
bool SDLInputChecker::eventHappened(unsigned int e)
{
    if(event->type == SDL_QUIT)
    {
        return true;
    }
    return false;
}
bool SDLInputChecker::keyUnpress(unsigned int key)
{
    if(event->key.type == SDL_KEYUP)
    {
        if(event->key.keysym.sym == key)
        {
            return true;
        }
    }
    return false;
}
bool SDLInputChecker::poll()
{
    if(SDL_PollEvent(event))
    {
        return true;
    }
    else
    {
        return false;
    }
}
