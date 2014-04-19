 /* file : thread.h
    Defines the TCB abstract data type and all it's underlaying types and enums*/

#ifndef THREAD_H
#define THREAD_H

/*describes the possible states of a thread*/
enum Thread_State
{
    created,    //Created means the thread has been created, but is still not ready to run
    ready,      //Ready means the thread is waiting to be scheduled for execution
    running,    //Running means the thread is running - duh
    zombie,     //Zombie means the thread has been terminated, but still exsts
    asleep      //Asleep means the thread is waiting for something to be able to run again - possibly the end of another thread or a system call
}

/*    A TCB is a thread control block, which is a structure
    that defines a thread, containing all the information
    needed to describe it and controll it  */

typedef struct TCB
{
    /*thread identifier code*/
    int tid;

    /*expected CPU time that this thread will use each time it's scheduled*/
    unsigned int expected_run_time;

    /*how long this thread has been running*/
    unsigned int current_run_time;

    /*current state of this thread, description of each state in the definition of Thread_State*/
    Thread_State current_state;
}TCB;

/*FUNCTIONS DOWN HERE */


#endif
