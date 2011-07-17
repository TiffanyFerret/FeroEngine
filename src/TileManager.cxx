#include"../include/Rect.h"
#include"../include/Image.h"
#include"../include/MsgCarrier.h"
#include"../include/RandomNumber.h"
#include"../include/CollisionDetector.h"
#include"../include/Sprite.h"
#include <vector>
#include"../include/SpriteManager.h"


void SpriteManager::addSprite(Sprite* sprite)
{
    mSprite->push_back(sprite);
}

void SpriteManager::removeSprite(Sprite* sprite)
{
    std::vector<Sprite*>::iterator it;
    for(it = mSprites->begin(); it < mSprites->end(); it++)
    {
        if(sprite == it)
        {
            break;
        }
    }
    mSprite->erase(it);
}
void SpriteManager::getSprite(Sprite* sprite)
{

}
