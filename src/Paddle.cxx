#include"../include/Rect.h"
#include"../include/Image.h"
#include"../include/MsgCarrier.h"
#include"../include/RandomNumber.h"
#include"../include/CollisionDetector.h"
#include"../include/Sprite.h"
#include"../include/Ball.h"
#include"../include/Paddle.h"
Paddle::Paddle(CollisionDetector* colDet) : Sprite(colDet)
{
    mSpriteType = 1;
    mClassLayer = 0;
    mRect->mW = 32;
    mRect->mH = 128;
    moveDown = false;
    moveUp = false;
}

void Paddle::run()
{
    if(moveUp)
    {
        mColDet->requestMove(this,new Vector(0,-4));
    }
    if(moveDown)
    {
        mColDet->requestMove(this,new Vector(0,4));
    }
}
PaddleAI::PaddleAI(CollisionDetector* colDet) : Paddle(colDet)
{
    mSpriteType = 1;
    mClassLayer = 1;
}

void PaddleAI::run()
{
    if(ball->mRect->mY < (mRect->mY + (mRect->mH * .5)))
    {
        mColDet->requestMove(this,new Vector(0,-4));
    }

    if(ball->mRect->mY > (mRect->mY + (mRect->mH * .5)))
    {
        mColDet->requestMove(this,new Vector(0,4));
    }
}
