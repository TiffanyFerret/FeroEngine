class Module
{
    virtual void init();
    virtual void run();
    virtual void uninit();
    virtual void* getData();
    virtual void giveData(void*);
}
