#include"../include/InputManager.h"
#include"../include/Inputs.h"
#include"../include/MsgCarrier.h"
//Window Close button****************************
void WindowClosed::pressAction()
{
    bool* running =(bool*) data;
    *running = false;
}
void WindowClosed::unpressAction()
{
}
//Paddle Down Button******************************
void PaddleDown::pressAction()
{
    MsgCarrier* tmp = (MsgCarrier*)data;
    tmp->notify(2);
}
void PaddleDown::unpressAction()
{
    MsgCarrier* tmp = (MsgCarrier*)data;
    tmp->notify(3);
}
//Paddle Up button***********************************
void PaddleUp::pressAction()
{
    MsgCarrier* tmp = (MsgCarrier*)data;
    tmp->notify(0);
}
void PaddleUp::unpressAction()
{
    MsgCarrier* tmp = (MsgCarrier*)data;
    tmp->notify(1);
}
