#include <vector>
#include"include/Frames2d.h"
void Frames2d::addFrame(Image* image);
{
    mFrames.push_back(image)
}

void Frames2d::removeFrame(Image* image)
{
    vector<Image*>::iterator it;
    for(it = mFrames.begin();it < mFrames.end();it++)
    {
        if(image == it)
        {
            break;
        }
    }
    mFrames.erase(it);
}
Frames2d::~Frames2d()
{
    mFrames.clear();
}
