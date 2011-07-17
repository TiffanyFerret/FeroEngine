#include "../include/Image.h"
#include "SDL/SDL.h"
#include "../include/ImageSDL.h"

ImageSDL::ImageSDL(SDL_Surface* image)
{
    m_Image = image;
}

void ImageSDL::setImage(void* image)
{
    m_Image =(SDL_Surface*) image;
}

void* ImageSDL::getImage()
{
    return m_Image;
}
