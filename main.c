#include <stdio.h>
#include "list.h"

int main() {
    printf("Hello, World!\n");


    List*ptr1 = List_create();
    print(ptr1->head, ptr1->head->data);

//    List*ptr2 = List_create();
//    List*ptr3 = List_create();
//    List*ptr4 = List_create();
//    List*ptr5 = List_create();

    return 0;
}
