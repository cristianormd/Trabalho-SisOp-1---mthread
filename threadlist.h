#ifndef THREADLIST_H
#define THREADLIST_H

#include "thread.h"


/*TYPE DEFINITIONS*/

typedef struct mThreadListElement
{
    mTCB thread;                     //the thread associated with this element
    struct mThreadListElement* next;        //the element next to this one
    struct mThreadListElement* previous;    //the element previous to this one
}mThreadListElement;

typedef struct mThreadList
{
    mThreadListElement* first_element;
}mThreadList;


extern const mThreadList mInitializedThreadList;


/*FUNCTION DEFINITIONS*/

/* USE AS A CONSTRUCTOR TO A THREAD LIST ELEMENT*/
mThreadListElement* newmThreadListElement(mTCB thread);


/* USE AS A CONSTRUCTOR TO A THREAD LIST */
mThreadList* newmThreadList();

 /*returns 1 if the element was successfully added to the list. Else, returns an error code
    which is a negative number, described after the function*/
int addElementBeggining(mThreadListElement* new_element, mThreadList* target_list);

/*adds an element using expected_run_time as a priority, the smaller the time the higher the priority
 returns 1 if the element was successfully added to the list. Else, returns an error code
    which is a negative number, described after the function*/
int addElementPriority(mThreadListElement* new_element, mThreadList* target_list);

/*error codes*/
#define ADD_ELEMENT_ERROR -1

/*removes a given element from the list. Returns 1 if the element was successfully removed. Else, returns an error code
    which is a negative number. Error codes are after the function definition.

     THE FUNCTION DOS NOT DEALLOCATE THE ELEMENT,
    ONLY REMOVES FROM THE LIST IT'S IN  */
int removeElement(mThreadListElement* removed_element, mThreadList* input_list);

/*prints a thread list*/
void printmThreadList(mThreadList input_list);


/*error codes*/
#define REMOVE_ELEMENT_ERROR -1


#endif
