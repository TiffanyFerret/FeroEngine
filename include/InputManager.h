#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
class InputCode
{
public:
    unsigned int code;
    bool pressed;
};
class Input
{
public:
    Input();
    ~Input();
    void* v_codeList;
    void* data;
    bool interfer;
    unsigned int type;
    void addInputCode(unsigned int);
    void removeInputCode();
    virtual void pressAction();
    virtual void unpressAction();
};
class InputChecker
{
    public:
    virtual bool keyPress(unsigned int) = 0;
    virtual bool keyUnpress(unsigned int) = 0;
    virtual bool eventHappened(unsigned int) = 0;
    virtual unsigned int keyUp() = 0;
    virtual unsigned int keyDown() = 0;
    virtual bool poll() = 0;
};
class InputManager
{
private:
    void* v_inputList;
    InputChecker* event;
public:
    InputManager(InputChecker* event);
    ~InputManager();
    void addInput(Input*);
    //void removeInput(Input*);
    void poll();
};


#endif // INPUTMANAGER_H
