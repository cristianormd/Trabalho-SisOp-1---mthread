#include "scheduler.h"

int getTid()
{
    return next_tid++; //returns next_tid and increments it afterwards
}

 //schedules the given task for execution
int schedule(void (*start_routine)(void*), void *arg)
{
    return 1;
}

