class Entity
{
public:
    Entity();
    Entity(CollisionDetector*);
    Rect* mRect;
    GraphicEntity* currentGraphicEntity;
    Vector* mVector;
    unsigned int mEntityType;
    unsigned int mClassLayer;
    CollisionDetector* mColDet;
    RandomNumber* mRandomNumber;
    void draw();
    virtual void run() = 0;
    bool mDrawable;
protected:
    Renderer* renderer;
};

class Wall : public Entity
{
public:
    Wall(CollisionDetector*);
    virtual void run();
};

