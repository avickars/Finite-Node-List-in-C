#include <stdio.h>
#include "list.h"

int main() {
    printf("Hello, World!\n");


    List *ptr = List_create();
    List_append(ptr, (int *) 5);
    List_append(ptr, (int *) 6);
    print(ptr);

    List *ptr1 = List_create();
    List_append(ptr1, (int *) 7);
    List_append(ptr1, (int *) 8);
    print(ptr1);
    printf("%p \n", ptr1);
    List_concat(ptr, ptr1);
    printf("%p \n", ptr1);
    print(ptr1);
    print(ptr);




//    List*ptr2 = List_create();
//    List*ptr3 = List_create();
//    List*ptr4 = List_create();
//    List*ptr5 = List_create();

    return 0;
}
