class Ball : public Sprite
{
public:
    Ball(CollisionDetector*);
    void Init();
    float sleep;
    virtual void run();
};
