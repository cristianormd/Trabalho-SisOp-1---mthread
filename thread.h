 /* file : thread.h
    Defines the TCB abstract data type and all it's underlaying types and enums*/

#ifndef THREAD_H
#define THREAD_H


/*TYPE DEFINITIONS*/

/*    A TCB is a thread control block, which is a structure
    that defines a thread, containing all the information
    needed to describe it and controll it  */

struct mTCB
{
    /*thread identifier code. Negative number is an error
    and positive numbers are valid tid's*/
    int tid;

    /*expected CPU time that this thread will use each time it's scheduled*/
    unsigned int expected_run_time;

    /*how long this thread has been running*/
    unsigned int last_run_time;

    /*the task to be executed*/
    void (*start_routine)(void*);

    /*the arguments*/
    void *arg;
};

typedef struct mTCB mTCB;

/*FUNCTION DEFINITIONS*/

//returns a new mTCB
mTCB* newmTCB(int tid, void (*start_routine)(void*), void *arg);

//prints a thread
void printmTCB(mTCB thread);

#endif
