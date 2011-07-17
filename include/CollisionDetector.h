class Vector
{
public:
    Vector(float,float);
    float mDirection[2];
};

class CollisionDetector
{
public:
    CollisionDetector(void* sprites);
    void* collider(void*,Vector* );

    void* mSprites;
    bool collisionCheck(Rect*,Rect*);
    void* requestMove(void* a,Vector* vector);
};
