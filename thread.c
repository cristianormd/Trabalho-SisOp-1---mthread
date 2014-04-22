#include "thread.h"

#include <stdlib.h>
#include <stdio.h>

mTCB* newmTCB(int tid, void (*start_routine)(void*), void *arg)
{
    mTCB* new_thread = malloc(sizeof(mTCB));
    new_thread->tid = tid;
    new_thread->start_routine = start_routine;
    new_thread->arg = arg;

    return new_thread;
}

void printmTCB(mTCB thread)
{
    printf("tid = %d ; expected_run_time = %d ; last_run_time = %d\n", thread.tid, thread.expected_run_time, thread.last_run_time);
    return;
}


