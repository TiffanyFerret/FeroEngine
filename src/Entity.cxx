#include"../include/Image.h"
#include"../include/Rect.h"
#include"../include/CollisionDetector.h"
#include"../include/RandomNumber.h"
Entity::Entity(CollisionDetector* colDet)
{
    mColDet = colDet;
    mClassLayer = 0;
    mRect = new Rect();
    mVector = new Vector(0,0);
}
Entity::Entity()
{
    mColDet = colDet;
    mRect = new Rect();
    mVector = new Vector(0,0);
}
Entity::~Entity()
{

}

void Entity::run()
{
    if(mDrawable)
    {
        draw();
    }
}
void Entity::draw()
{
    renderer->requestDraw(this,currentGraphicEntity);
}



Wall::Wall(CollisionDetector* colDet) : Entity(colDet)
{
}
void Wall::run(){}
