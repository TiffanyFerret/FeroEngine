#ifndef IMAGESDL_H
#define IMAGESDL_H


class ImageSDL : public Image
{
    public:
        ImageSDL(SDL_Surface*);
        virtual void setImage(void*);
        virtual void* getImage();
    private:
        SDL_Surface* m_Image;
};

#endif // IMAGESDL_H
