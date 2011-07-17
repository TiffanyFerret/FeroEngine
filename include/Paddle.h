
class Paddle : public Sprite
{
public:
    Paddle(CollisionDetector*);
    bool moveDown;
    bool moveUp;
    virtual void run();
};

class PaddleAI : public Paddle
{
public:
    PaddleAI(CollisionDetector*);
    Ball* ball;
    virtual void run();
};
