#include"../include/MsgCarrier.h"
#include"../include/Program.h"

MsgCarrier::MsgCarrier(void* program)
{
    mProgram = program;
}
void MsgCarrier::notify(int msg)
{
    Program* tmp =(Program*) mProgram;
    tmp->notify(msg);
}
