class SpriteManager : public Module
{
    SpriteManager();
    std::vector<void*> mSprites;
    virtual void init();
    virtual void uninit();
    virtual void run();
    void addSprite(Sprite*);
    void removeSprite(Sprite*);
    Sprite* getSprite(int);
};
