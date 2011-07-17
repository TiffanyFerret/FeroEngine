class Frames2d : public GraphicEntity
{
public:
    void addFrame(Image* image);
    void removeFrame(Image* Image);
    std::vector<image*> mFrames;
    ~Frames2d();
}
