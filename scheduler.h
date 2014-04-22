#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "thread.h"
#include "threadlist.h"

#include <limits.h>

mThreadList ready =  mInitializedThreadList;      //apta
mThreadList running =  mInitializedThreadList;    //executando
mThreadList asleep =  mInitializedThreadList;     //bloqueada

int next_tid = INT_MIN; //starts the tid's to be given in the minimumnumber represented by int

int schedule(void (*start_routine)(void*), void *arg);       //schedules this task to be executed

//returns a tid that will be associated with the new thread
int getTid();

#endif
