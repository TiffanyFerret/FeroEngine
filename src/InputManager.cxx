#include "../include/InputManager.h"
#include <list>
void Input::pressAction(){}
void Input::unpressAction(){}
Input::Input()
{
    v_codeList = new std::list<InputCode*>;
    interfer = false;
}
Input::~Input()
{
    std::list<InputCode*>* codeList = (std::list<InputCode*>*)v_codeList;
    codeList->clear();
    delete codeList;
}
void Input::addInputCode(unsigned int code)
{
    std::list<InputCode*>* codeList = (std::list<InputCode*>*)v_codeList;
    InputCode* inputCode = new InputCode;
    inputCode->pressed = false;
    inputCode->code = code;
    codeList->push_back(inputCode);
}
void Input::removeInputCode()
{
    std::list<InputCode*>* codeList = (std::list<InputCode*>*)v_codeList;
    codeList->clear();
}
InputManager::InputManager(InputChecker* e)
{
    v_inputList = new std::list<Input*>;
    event = e;
}
InputManager::~InputManager()
{
    std::list<Input*>* inputList = (std::list<Input*>*) v_inputList;
    inputList->clear();
    delete inputList;
}
void InputManager::addInput(Input* input)
{
    std::list<Input*>* inputList = (std::list<Input*>*) v_inputList;
    inputList->push_back(input);
}
void InputManager::poll()
{
    std::list<Input*>* inputList = (std::list<Input*>*) v_inputList;
    std::list<InputCode*>::iterator itTmp;
    bool tmp;
    unsigned int keyTmp;
    InputCode* inputCodeTmp;
    Input* inputTmp;
    while(event->poll())
    {
        for(std::list<Input*>::iterator it = inputList->begin();it != inputList->end();++it)
        {
            inputTmp = *it;
            std::list<InputCode*>* codeList = (std::list<InputCode*>*) inputTmp->v_codeList;
            itTmp = codeList->begin();
            inputCodeTmp = *itTmp;
            if(event->eventHappened(inputCodeTmp->code))
            {
                inputTmp->pressAction();
            }
            //assume it is interfering
            inputTmp->interfer = true;
            keyTmp = event->keyDown();
            for(std::list<InputCode*>::iterator it2 = codeList->begin();it2 != codeList->end();++it2)
            {
                inputCodeTmp = *it2;
                if(event->keyPress(inputCodeTmp->code))
                {
                        inputCodeTmp->pressed = true;
                }
            }
            tmp = true;
            for(std::list<InputCode*>::iterator it2 = codeList->begin();it2 != codeList->end();++it2)
            {
                inputCodeTmp = *it2;
                if(inputCodeTmp->pressed == false)
                {
                    tmp = false;
                }
            }
            if(tmp == true)
            {
                if(event->keyDown() > 0)
                {
                    inputTmp->pressAction();
                    for(std::list<InputCode*>::iterator it2 = codeList->begin();it2 != codeList->end();++it2)
                    {
                        inputCodeTmp = *it2;
                        inputCodeTmp->pressed = false;
                    }
                }
            }
            tmp = false;
            for(std::list<InputCode*>::iterator it2 = codeList->begin();it2 != codeList->end();++it2)
            {
                inputCodeTmp = *it2;
                if(event->keyUnpress(inputCodeTmp->code))
                {
                    inputCodeTmp->pressed = false;
                    if(tmp == false)
                    {
                        inputTmp->unpressAction();
                    }
                    tmp = true;
                }
            }
        }
    }
}
