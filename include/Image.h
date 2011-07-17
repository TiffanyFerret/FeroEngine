#ifndef IMAGE_H
#define IMAGE_H


class Image
public:
    virtual void setImage(void*) = 0;
    virtual void* getImage() = 0;
};

#endif // IMAGE_H
