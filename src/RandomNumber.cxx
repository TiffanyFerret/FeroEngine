#include"../include/RandomNumber.h"
#include"stdlib.h"
RandomNumber::RandomNumber(int seed)
{
    srand(seed);
}
int RandomNumber::getNumber(int min,int max)
{
    int range = max - min;
    return((rand() % range) + min);
}
