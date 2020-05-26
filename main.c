//#include <stdio.h>
//#include "list.h"
//
//static void freeItem(void *item) {
////    printf("Here");
//}
//
//static bool itemEquals(void *pItem, void *pArg) {
//    return (*(int*) pItem == *(int*) pArg);
//}
//
//int main() {
//
//
//    printf("Hello, World!\n");
//
//
//    List *ptr = List_create();
//    int x= 5;
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
//    int k = 10;
//
//    printf("List 1 and 2: ");
//    print(ptr);
//
//
//    printf("%p", List_search(ptr, &itemEquals, &k));
//
//
//    return 0;
//}
