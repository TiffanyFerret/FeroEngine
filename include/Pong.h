#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<vector>
#include<string>
#include"../include/InputManager.h"
#include"../include/eventSDL.hpp"
#include"../include/Image.h"
#include"../include/ImageSDL.h"
#include"../include/Rect.h"
#include"../include/CollisionDetector.h"
#include"../include/Image.h"
#include"../include/MsgCarrier.h"
#include"../include/RandomNumber.h"
#include"../include/Sprite.h"
#include"../include/Ball.h"
#include"../include/Paddle.h"
#include"../include/Program.h"
#include"../include/Inputs.h"
class Pong : public Program
{
protected:
    int mWidth;
    int mHeight;
    int mBpp;
    int mStartTime;
    int CurrentTime;
    int mTickRate;
    CollisionDetector* mColDet;
    RandomNumber* mRandomNumber;
public:
    Pong(int,int,int);
    ~Pong();
    void setWidth(int);
    void setHeight(int);
    void setBpp(int);

    int getWidth();
    int getHeight();
    int getBpp();

    void gameLoop();

    Image* mScreen;

    GraphicEntity* mBallImage;
    GraphicEntity* mPaddleImage;

    std::vector<Sprite*>* mSprites;
    InputManager* mInputManager;
    virtual void notify(int);
};
