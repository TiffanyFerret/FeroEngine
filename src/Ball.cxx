#include"../include/Rect.h"
#include"../include/Image.h"
#include"../include/MsgCarrier.h"
#include<math.h>
#include"../include/RandomNumber.h"
#include"../include/CollisionDetector.h"
#include"../include/Sprite.h"
#include"../include/Ball.h"
Ball::Ball(CollisionDetector* colDet) : Sprite(colDet)
{
    mSpriteType = 0;
    mClassLayer = 1;
    mRect->mW = 32;
    mRect->mH = 32;
    Init();
    sleep = 0;
}
void Ball::Init()
{
    mRect->mX = 240;
    mRect->mY = 240;

    mVector->mDirection[0] = -4;
    mVector->mDirection[1] = 4;
}
void Ball::run()
{
    Sprite* collidedWith;
    double cosine;
    float speed;
    speed = sqrt(pow(mVector->mDirection[0],2) + pow(mVector->mDirection[1],2));
    //mColDet->requestMove(this,mVector);
    mRect->mX = mRect->mX + mVector->mDirection[0];
    mRect->mY = mRect->mY + mVector->mDirection[1];
    collidedWith =(Sprite*) mColDet->collider(this,mVector);
    if(collidedWith != 0)
    {
        //mVector->mDirection[0] = 0.7853981633 + cos(mVector->mDirection[0] / mVector->mDirection[1]);

        //Check if hitting left
        if(mRect->mX < (collidedWith->mRect->mX + collidedWith->mRect->mW))
        {
            mVector->mDirection[0] = mVector->mDirection[0] * -1;
        }
        //Check if Hitting right
        if((mRect->mX > + mRect->mW) > collidedWith->mRect->mX)
        {

            mVector->mDirection[0] = mVector->mDirection[0] * -1;
        }
        //Check if Hitting top
        if(mRect->mY < (collidedWith->mRect->mY - collidedWith->mRect->mH))
        {
            mVector->mDirection[1] = mVector->mDirection[1] * -1;
        }
        //Check if Hitting bottom
        if((mRect->mY > + mRect->mH) > collidedWith->mRect->mY )
        {
            mVector->mDirection[1] = mVector->mDirection[1] * -1;
        }
    }
    if(mRect->mX < 0 || mRect->mX > 640)
    {
        Init();
    }
}
