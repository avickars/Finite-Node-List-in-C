#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void freeItem(void *item) {
    free(item);
}

int main() {


    printf("Hello, World!\n");


//    List *ptr = List_create();
    int x= 5;
//    int y = 6;
//    int z = 7;
//    List_append(ptr, &x);
//    List_append(ptr, &y);
//    List_append(ptr, &z);
//    printf("List 1: ");
//    print(ptr);
//
//    List *ptr2 = List_create();
//    int a= 8;
//    int b = 9;
//    int c = 10;
//    List_append(ptr2, &a);
//    List_append(ptr2, &b);
//    List_append(ptr2, &c);
//    printf("List 2: ");
//    print(ptr2);
//    List_concat(ptr,ptr2);
//    printf("%d \n", ptr->size);
//    printf("List 1 & 2: ");
//    print(ptr);
//    ptr2 = NULL;
//    printf("%p \n", ptr2);
    printf("1 %p \n", &x);
free((int*) x);
printf("2 %p", &x);
    printf("3 %d", x);

    return 0;
}
