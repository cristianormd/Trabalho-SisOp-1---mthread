#include "threadlist.h"

#include <stdio.h>
#include <stdlib.h>

const mThreadList mInitializedThreadList = {NULL};

mThreadListElement* newmThreadListElement(mTCB thread)
{
    mThreadListElement* new_element = malloc(sizeof(mThreadListElement));
    new_element->thread = thread;
    new_element->previous = NULL;
    new_element->next = NULL;

    return new_element;
}

mThreadList* newmThreadList()
{
    mThreadList* new_list = malloc(sizeof(mThreadList));
    new_list->first_element = NULL;
    return new_list;
}

/*  returns 1 if the element was successfully added to the list. Else, returns an error code
    which is a negative number, described after the function*/
int addElementBeggining(mThreadListElement* new_element, mThreadList* target_list)
{
    new_element->previous = NULL;                        //the previous element of the new first element is NULL

    if(target_list->first_element!=NULL)
        target_list->first_element->previous = new_element;   //the previous element of the old first element is the new first element

    new_element->next = target_list->first_element;        //the next element of the first element is the previous first element
    target_list->first_element = new_element;             //finnally, the first element of the list becomes the new element

    /* ADICIONAR LOGICA DE CONTROLE DE ERROS*/
    return 1;
}

/*  returns 1 if the element was successfully added to the list. Else, returns an error code
    which is a negative number, described after the function*/
int addElementPriority(mThreadListElement* new_element, mThreadList* target_list)
{
    mThreadListElement* current_element;
    mThreadListElement* previous_current_element;

    current_element = target_list->first_element;
    previous_current_element = target_list->first_element;

    while(current_element!= NULL && new_element->thread.expected_run_time > current_element->thread.expected_run_time)    //while the priority of the current_element is bigger than the new_element
    {
        previous_current_element = current_element;      //we walk the list
        current_element = current_element->next;
    }
    printf("============\n");
    //now we have to insert the element after previous_current_element and before current_element (between them)

    if(current_element == previous_current_element)   //if we have to insert new element as the first on the list
    {
        target_list->first_element = new_element;
    }

    new_element->next = current_element;
    new_element->previous = previous_current_element;       //new element is linked to both elements

    if(current_element!=NULL)
        current_element->previous = new_element;            //if the current element exists, it's sucessor is new_element
    if(previous_current_element!=NULL && current_element != previous_current_element)
        previous_current_element->next = new_element;            //if the previous_current_element exists, it's sucessor is new_element

    return 1;

    /*OLD CODE*/
                                         /*
                                         mThreadListElement* current_element;
                                         mThreadListElement* old_current_element;

                                         current_element = target_list->first_element;    //current_element points to the first element on the list
                                         old_current_element = current_element;          //initially, old_current_element is equal to our current element

                                         while(current_element!= NULL && new_element->thread.expected_run_time > current_element->thread.expected_run_time)   //while the expected run time of the current element is less than the expected run time of this element
                                         {
                                             old_current_element = current_element;
                                             current_element = current_element->next;     //walks on the list untill you find the insertion point
                                         }

                                         //at this point, current_element points to the first element that has a bigger expected run time than the new element
                                         //the new_element should be inserted before this one - it has a priority bigger than current_element

                                         if(current_element == target_list->first_element) //if the insertion point is the beginning of the list
                                         {
                                             return addElementBeggining(new_element, target_list);

                                         }
                                         else
                                         {

                                         new_element->previous = current_element->previous;  //the previous element of the new element is the previous element of the current element
                                         current_element->previous->next = new_element;      //because of the reflexivity, the next element of the previous element is the new element
                                         current_element->previous = new_element;            //the previous element of the curent element is the new element
                                         new_element->next = current_element;                //ænd because of the reflexivity again, the next element of the new element is the current element

                                         /*ADICIONAR LOGICA DE CONTROLE DE ERROS
                                         return 1;
                                         }*/
    }

/*removes the element withoud deallocating the memory - the elment still exists, but is removed from the list*/
int removeElement(mThreadListElement* removed_element, mThreadList* input_list)
{
    if(input_list->first_element == NULL)
        return REMOVE_ELEMENT_ERROR;
    else
    {
        if(input_list->first_element == removed_element)    //if it is the first element on the list
            input_list->first_element = removed_element->next;  //updates the info on input_list
        else                                                      //if it is not the first element, it has a previous element
            removed_element->previous->next = removed_element->next;   //and it's next element is the removed_element's next element

        removed_element->next->previous = removed_element->previous;    //the previous element of the next element is the previous element of the removed element (WAT)

        removed_element->next = NULL;
        removed_element->previous = NULL;   //the removed element points nowhere
    }
    /*ADICIONAR LOGICA DE CONTROLE DE ERROS*/
    return 1;
}

void printmThreadList(mThreadList input_list)
{
    mThreadListElement* aux = input_list.first_element;

    while(aux!= NULL)
    {
        printmTCB(aux->thread);
        aux = aux->next;
    }

    return;
}
