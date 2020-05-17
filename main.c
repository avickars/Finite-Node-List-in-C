#include <stdio.h>
#include "list.h"

int main() {
    printf("Hello, World!\n");


    List*ptr = List_create();
    List_append(ptr, (int *) 5);
    List_append(ptr, (int *) 6);
    List_append(ptr, (int *) 7);
    List_prepend(ptr, (int *) 8);
    print(ptr);
    printf("\n Current: %d", ptr->current->data);
    List_prev(ptr);
//    List_next(ptr);
//    List_next(ptr);
//    List_next(ptr);
//    List_next(ptr);
//    printf("\n Current: %d", ptr->current->data);
    printf("\n %d", ptr->currentOutOfBoundsFront);
    List_insert(ptr,(int *) 10);
    print(ptr);



//    List*ptr2 = List_create();
//    List*ptr3 = List_create();
//    List*ptr4 = List_create();
//    List*ptr5 = List_create();

    return 0;
}
