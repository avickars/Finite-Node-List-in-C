#include <stdio.h>
#include "list.h"

int main() {
    printf("Hello, World!\n");


    List*ptr1 = List_create();
    List_append(ptr1, (int *) 5);
    List_append(ptr1, (int *) 6);
    List_append(ptr1, (int *) 7);
    List_prepend(ptr1, (int *) 8);
    print(ptr1);

//    List*ptr2 = List_create();
//    List*ptr3 = List_create();
//    List*ptr4 = List_create();
//    List*ptr5 = List_create();

    return 0;
}
