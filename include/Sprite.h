class Sprite
{
public:
    std::vector<Image>* frames;
    void draw(Image* s);
    void addFrame(Image*);
    void removeFrame(Image*);
    bool mDrawable;
protected:
    void nextFrame();
};





