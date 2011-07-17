#include"include/Fero2dRenderer.h"
void DrawSurface(int x,int y,Image* src,Image* dst)
{
    //Make a temporary rectangle to hold offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface((SDL_Surface*)src->getImage(),NULL,(SDL_Surface*)dst->getImage(), &offset);
}
void Fero2dRenderer::render()
{
    if(mImage != NULL)
    {
        DrawSurface(mRect->mX,mRect->mY,mImage,s);
    }
}
