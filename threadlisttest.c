#include "threadlist.h"

#include <stdlib.h>
#include <stdio.h>
int main(int argc , const char* argv[])
{
    mThreadList main_list;
    main_list.first_element = NULL;
    mTCB thread_1;

     thread_1.tid = 23423525;
    thread_1.expected_run_time = 0;
    thread_1.last_run_time = 0;

    mThreadListElement* first_element = newmThreadListElement(thread_1);
    addElementPriority(first_element,&main_list);

    thread_1.tid = 12534;
    thread_1.expected_run_time = 0;
    thread_1.last_run_time = 0;

    first_element = newmThreadListElement(thread_1);
    addElementPriority(first_element,&main_list);

    thread_1.tid = 9999;
    thread_1.expected_run_time = 0;
    thread_1.last_run_time = 0;

    first_element = newmThreadListElement(thread_1);
    addElementPriority(first_element,&main_list);

    removeElement(first_element, &main_list);
    printmThreadList(main_list);
    return 0;
}
