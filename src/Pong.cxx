#include"../include/Pong.h"
SDL_Surface* load_image(std::string filename)
{
    //The image that's loaded
    SDL_Surface* loadedImage = 0;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image using SDL_image
    loadedImage = IMG_Load(filename.c_str());
    //If the image loaded
    if(loadedImage != 0)
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat(loadedImage);

        //Free the old image
        SDL_FreeSurface(loadedImage);
    }
    //Return the optimized image
    return optimizedImage;
}
Pong::Pong(int width,int height,int bpp)
{
    setWidth(width);
    setHeight(height);
    setBpp(bpp);

    mCarrier = new MsgCarrier(this);
    //init input flags

    SDL_Init(SDL_INIT_EVERYTHING);
    DataCentral* dataCenter = new DataCentral();

    dataCenter->addData("paddlea" ,(void*)new Paddle());
    dataCenter->addData("paddleb" ,(void*)new PaddleAI());
    dataCenter->addData("ball"    ,(void*)new Ball());
    dataCenter->addData("smanager",(void*)new EntityManager());
    Entity* paddleA = (Entity*)dataCenter->getData("paddlea");
    Entity* paddleB = (Entity*)dataCenter->getData("paddleb");
    Entity* ball    = (Entity*)dataCenter->getData("ball");
    SpriteManager* entityManager =
        (SpriteManager*)dataCenter->getData("emanager"));

    entityManager->addEntity(paddleA);
    entityManager->addEntity(paddleB);
    emtityManager->addEntity(ball);

    mScreen =(Image*) new ImageSDL(SDL_SetVideoMode(mWidth,mHeight, mBpp,SDL_SWSURFACE));

    dataCenter->addData("iball",(void*)new ImageSDL(load_image("data/ball.png"));)
    dataCenter->addData("ipaddle",(void*)new ImageSDL(load_image("data/paddle.png"));

    Frames2d* frames = new Frames2d;

    frames->addFrame((Image*)dataCenter->getData("iball"));
    ball->currentGraphicEntity = (GraphicEntity*) frames;

    frames = new Frames2d;

    frames->addFrame((Image*)dataCenter->getData("ipaddle"));
    paddleA->currentGraphicEntity = (GraphicEntity*) frames);
    paddleB->currentGraphicEntity = (GraphicEntity*) frames);

    mInputManager = new InputManager(new SDLInputChecker(new SDL_Event));
    mColDet = new CollisionDetector(mSprites);
    mRandomNumber = new RandomNumber(102432);

    dataCenter->addData("imanager" ,mInputManager);
    dataCenter->addData("coldet"   ,mColDet);
    dataCenter->addData("randomnum",mRandomNumber);

    Sprite* tmp = (Sprite*)new Paddle(mColDet);
    tmp->mImage = mPaddleImage;

    tmp->mRect->mX = 0;
    tmp->mRect->mY = 32;
    tmp->mRect->mZ = 0;
    mSprites->push_back(tmp);

    tmp =(Sprite*) new Wall(mColDet);
    tmp->mRect->mX = 0;
    tmp->mRect->mY = 0;
    tmp->mRect->mZ = 0;

    tmp->mRect->mW = mWidth;
    tmp->mRect->mH = 0;
    tmp->mRect->mT = 0;
    mSprites->push_back(tmp);

    tmp = (Sprite*) new Wall(mColDet);
    tmp->mRect->mX = 0;
    tmp->mRect->mY = mHeight;
    tmp->mRect->mZ = 0;

    tmp->mRect->mW = mWidth;
    tmp->mRect->mH = 0;
    tmp->mRect->mT = 0;
    mSprites->push_back(tmp);
    PaddleAI* paddle;
    tmp = (Sprite*)new PaddleAI(mColDet);
    tmp->mImage = mPaddleImage;
    tmp->mRect->mX = getWidth() - 32;
    tmp->mRect->mY = 0;
    tmp->mRect->mZ = 0;
    mSprites->push_back(tmp);
    paddle =(PaddleAI*) tmp;

    tmp = (Sprite*)new Ball(mColDet);
    tmp->mImage = mBallImage;
    tmp->mRandomNumber = mRandomNumber;
    mSprites->push_back(tmp);
    paddle->ball = (Ball*)tmp;
    Input* inputTmp;
    bool* running = new bool;
    *running = true;
    inputTmp = new WindowClosed();
    mInputManager->addInput(inputTmp);
    inputTmp->addInputCode(0);
    inputTmp->data = running;

    inputTmp = new PaddleUp();
    mInputManager->addInput(inputTmp);
    inputTmp->addInputCode(SDLK_UP);
    inputTmp->data = mCarrier;

    inputTmp = new PaddleDown();
    mInputManager->addInput(inputTmp);
    inputTmp->addInputCode(SDLK_DOWN);
    inputTmp->data = mCarrier;
    mTickRate = 1000 / 60;
    while(*running)
    {
        mStartTime = SDL_GetTicks();
        while(mStartTime + mTickRate > SDL_GetTicks())
        {
        }
        gameLoop();
    }
    delete mInputManager;
}
void Pong::gameLoop()
{
    mInputManager->poll();

    std::vector<Sprite*>::iterator it;
    for (it = mSprites->begin(); it < mSprites->end();it++)
    {
        Sprite* tmp = *it;
        tmp->run();
        tmp->draw(mScreen);
    }

    SDL_Flip((SDL_Surface*)mScreen->getImage());
    SDL_FillRect((SDL_Surface*)mScreen->getImage(),0,0);
}

void Pong::notify(int msg)
{
    Paddle* tmp =(Paddle*) mSprites->at(0);
    switch(msg)
    {
        case 0:
            tmp->moveUp = true;
            break;
        case 1:
            tmp->moveUp = false;
            break;
        case 2:
            tmp->moveDown = true;
            break;
        case 3:
            tmp->moveDown = false;
            break;
    }
}
void Pong::setWidth(int w)
{
    mWidth = w;
}

void Pong::setHeight(int h)
{
    mHeight = h;
}

void Pong::setBpp(int bpp)
{
    mBpp = bpp;
}

int Pong::getWidth()
{
    return mWidth;
}

int Pong::getHeight()
{
    return mHeight;
}

int Pong::getBpp()
{
    return mBpp;
}

Pong::~Pong()
{
    SDL_Quit();
}
