#include<Vector>
#include"../include/Rect.h"
#include"../include/CollisionDetector.h"
#include"../include/Image.h"
#include"../include/RandomNumber.h"
#include"../include/Sprite.h"

bool inRange(int num,int min,int max)
{
    if(num >= min && num <= max)
    {
        return true;
    }
    return false;
}
Vector::Vector(float direction0,float direction1)
{
    mDirection[0] = direction0;
    mDirection[1] = direction1;
}
CollisionDetector::CollisionDetector(void* sprites)
{
    mSprites = sprites;
}
bool CollisionDetector::collisionCheck(Rect* a,Rect* b)
{
    float left1,left2;
    float right1,right2;
    float top1,top2;
    float bottom1,bottom2;

    left1 = a->mX;
    left2 = b->mX;
    right1 = a->mX + a->mW;
    right2 = b->mX + b->mW;
    top1 = a->mY;
    top2 = b->mY;
    bottom1 = a->mY + a->mH;
    bottom2 = b->mY + b->mH;

    if (bottom1 < top2){ return false; }
    if (top1 > bottom2){ return false; }

    if (right1 < left2){ return false; }
    if (left1 > right2){ return false; }

    return true;
}
void* CollisionDetector::collider(void* sprite,Vector* vector)
{
    std::vector<Sprite*>::iterator it;
    Rect* purposed = new Rect();
    Sprite* a =(Sprite*) sprite;
    Rect* tmp = a->mRect;
    purposed->mX = tmp->mX + vector->mDirection[0];
    purposed->mY = tmp->mY + vector->mDirection[1];
    purposed->mW = tmp->mW;
    purposed->mH = tmp->mH;
    std::vector<Sprite*>* sprites = (std::vector<Sprite*>*)mSprites;
    for (it = sprites->begin(); it < sprites->end();it++)
    {
        Sprite* sTmp = *it;
        Rect* b = sTmp->mRect;
        if(collisionCheck(purposed,b) && sTmp != a)
        {
            return *it;
        }
    }
    return NULL;
}
void* CollisionDetector::requestMove(void* sprite,Vector* vector)
{
    std::vector<Sprite*>::iterator it;
    Rect* purposed = new Rect();
    Sprite* a =(Sprite*) sprite;
    Rect* tmp = a->mRect;
    purposed->mX = tmp->mX + vector->mDirection[0];
    purposed->mY = tmp->mY + vector->mDirection[1];
    purposed->mW = tmp->mW;
    purposed->mH = tmp->mH;
    bool detected = false;
    std::vector<Sprite*>* sprites = (std::vector<Sprite*>*)mSprites;
    for (it = sprites->begin(); it < sprites->end();it++)
    {
        Sprite* sTmp = *it;
        Rect* b = sTmp->mRect;
        if(collisionCheck(purposed,b) && sTmp != a)
        {
            detected = true;
        }
    }
    if(!detected)
    {
        a->mRect->mX = purposed->mX;
        a->mRect->mY = purposed->mY;
    }
}
