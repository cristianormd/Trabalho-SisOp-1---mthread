#ifndef THREADLIST_H
#define THREADLIST_H

#include "thread.h"
/*TYPE DEFINITIONS*/

typedef struct mThreadListElement
{
    mTCB thread;
    mThreadListElement* next = NULL;
    mThreadListElement* previous = NULL;
}mThreadListElement;

typedef struct mThreadList
{
    mThreadListElement* firstElement;
}

/*FUNCTION DEFINITIONS*/

/*  returns 1 if the element was successfully added to the list. Else, returns an error code
    which is a negative number, described after the function*/
int addElement(mTCB new_thread, mThreadList target_list);

/*error codes*/
#define ADD_ELEMENT_ERROR -1

/*removes a given element from the list. Returns 1 if the element was successfully removed. Else, returns an error code
    which is a negative number. Error codes are after the function definition*/
int removeElement(mTCB element, mThreadList target_list);

/*error codes*/
#define REMOVE_ELEMENT_ERROR -1


#endif
