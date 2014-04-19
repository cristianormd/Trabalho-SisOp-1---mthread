 /* file : thread.h
    Defines the TCB abstract data type and all it's underlaying types and enums*/

#ifndef THREAD_H
#define THREAD_H


/*TYPE DEFINITIONS*/


/*describes the possible states of a thread*/
enum mThread_State
{
    invalid,    //a state for recently created threads
    created,    //Created means the thread has been created, but is still not ready to run
    ready,      //Ready means the thread is waiting to be scheduled for execution
    running,    //Running means the thread is running - duh
    zombie,     //Zombie means the thread has been terminated, but still exsts
    asleep      //Asleep means the thread is waiting for something to be able to run again - possibly the end of another thread or a system call
}

/*    A TCB is a thread control block, which is a structure
    that defines a thread, containing all the information
    needed to describe it and controll it  */

typedef struct mTCB
{
    /*thread identifier code. zero is a default value for recently created TCBs. Negative number is an error
    and positive numbers are valid tid's*/
    int tid = 0;

    /*expected CPU time that this thread will use each time it's scheduled*/
    unsigned int expected_run_time = 0;

    /*how long this thread has been running*/
    unsigned int current_run_time = 0;

    /*current state of this thread, description of each state in the definition of Thread_State*/
    mThread_State current_state = invalid;
}mTCB;


/*FUNCTION DEFINITIONS*/


#endif
