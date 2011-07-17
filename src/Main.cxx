#include"../include/Pong.h"
int main(int argc,char** argv)
{
    Program* pong = new Pong(640,480,32);
    delete pong;
    return 0;
}
