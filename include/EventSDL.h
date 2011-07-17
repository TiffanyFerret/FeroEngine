#ifndef EVENT_SDL_HPP
#define EVENT_SDL_HPP
class SDLInputChecker : public InputChecker
{
private:
    SDL_Event* event;
public:
    SDLInputChecker(SDL_Event*);
    virtual bool poll();
    virtual unsigned int keyUp();
    virtual unsigned int keyDown();
    virtual bool keyPress(unsigned int);
    virtual bool keyUnpress(unsigned int);
    virtual bool eventHappened(unsigned int);
};
#endif

