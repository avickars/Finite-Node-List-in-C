#include <stdio.h>
#include "list.h"

int main() {
    printf("Hello, World!\n");


    List*ptr = List_create();
    List_append(ptr, (int *) 5);
    printf("%d \n", ptr->size);
    print(ptr);
    List_remove(ptr);
    printf("%d \n", ptr->size);
    List_insert(ptr, (int *) 10);
    print(ptr);



//    List*ptr2 = List_create();
//    List*ptr3 = List_create();
//    List*ptr4 = List_create();
//    List*ptr5 = List_create();

    return 0;
}
