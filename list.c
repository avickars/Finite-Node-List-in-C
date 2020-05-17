#include "list.h"
#include <stdio.h>
#include <assert.h>

static List heads[LIST_MAX_NUM_HEADS];
int numHeads = 0;

static Node nodes[LIST_MAX_NUM_NODES];
int numNodes = 0;

static Node* availableNodes;

static bool firstCreate = true;

// Creates a singly linked list of available nodes
void Constructor() {
    availableNodes = &nodes[0];
    Node *nodePtr = availableNodes;
    for (int i = 1; i < LIST_MAX_NUM_NODES; ++i) {
        nodePtr->next = &nodes[i];
        nodePtr = nodePtr->next;
    }
}

void initializeList(List *pList) {
    pList->current = NULL;
    pList->currentOutOfBoundsBack = true;
    pList->currentOutOfBoundsFront = true;
    pList->head = NULL;
    pList->size = 0;
    pList->tail = NULL;
}

void initializeNode(Node *pNode, void *pItem) {
    pNode->next = NULL;
    pNode->previous = NULL;
    pNode->data = pItem;
}

void *Get_new_node(void *pItem) {
    assert(numNodes < LIST_MAX_NUM_NODES);
    Node  * newNode = availableNodes;
    availableNodes = availableNodes->next;
    numNodes++;

    initializeNode(newNode, pItem);
    return newNode;

}

void print(List *pList) {
    Node *temp = pList->head;
    printf("In Print \n");
    while (temp != NULL) {
        printf("%p \n", (int*) temp->data);
        temp = temp->next;
    }
}



// Makes a new, empty list, and returns its reference on success.
// Returns a NULL pointer on failure.
List* List_create() {
    if (firstCreate) {
        Constructor();
    }
    List *newList = &heads[numHeads];
    initializeList(newList);
    numHeads++;

    return newList;
}

// Returns the number of items in pList.
int List_count(List* pList) {
    return pList->size;
}

// Returns a pointer to the first item in pList and makes the first item the current item.
// Returns NULL and sets current item to NULL if list is empty.
void* List_first(List* pList) {
    if (pList->size == 0) {
        pList->current = NULL;
        return NULL;
    } else {
        pList->current = pList->head;
        return pList->current;
    }
}

// Returns a pointer to the last item in pList and makes the last item the current item.
// Returns NULL and sets current item to NULL if list is empty.
void* List_last(List* pList);

// Advances pList's current item by one, and returns a pointer to the new current item.
// If this operation advances the current item beyond the end of the pList, a NULL pointer
// is returned and the current item is set to be beyond end of pList.
void* List_next(List* pList);

// Backs up pList's current item by one, and returns a pointer to the new current item.
// If this operation backs up the current item beyond the start of the pList, a NULL pointer
// is returned and the current item is set to be before the start of pList.
void* List_prev(List* pList);

// Returns a pointer to the current item in pList.
// Returns NULL if current is before the start of the pList, or after the end of the pList.
void* List_curr(List* pList);

// Adds the new item to pList directly after the current item, and makes item the current item.
// If the current pointer is before the start of the pList, the item is added at the start. If
// the current pointer is beyond the end of the pList, the item is added at the end.
// Returns 0 on success, -1 on failure.
int List_add(List* pList, void* pItem);

// Adds item to pList directly before the current item, and makes the new item the current one.
// If the current pointer is before the start of the pList, the item is added at the start.
// If the current pointer is beyond the end of the pList, the item is added at the end.
// Returns 0 on success, -1 on failure.
int List_insert(List* pList, void* pItem);

// Adds item to the end of pList, and makes the new item the current one.
// Returns 0 on success, -1 on failure.
int List_append(List* pList, void* pItem) {
    if (numNodes >= LIST_MAX_NUM_NODES) {
        return 0;
    } else if (pList->size == 0) {
        pList->current = Get_new_node(pItem);
        pList->head = pList->current;
        pList->tail = pList->current;
        pList->size++;
        pList->currentOutOfBoundsFront = false;
        pList->currentOutOfBoundsBack = false;
    } else {
        pList->current = Get_new_node(pItem);
        pList->current->previous = pList->tail;
        pList->tail->next = pList->current;
        pList->tail = pList->current;
        pList->size++;
        if (pList->currentOutOfBoundsBack || pList->currentOutOfBoundsFront) {
            if (pList->currentOutOfBoundsFront)
                pList->currentOutOfBoundsFront = false;
            else
                pList->currentOutOfBoundsBack = false;
        }
    }
}


// Adds item to the front of pList, and makes the new item the current one.
// Returns 0 on success, -1 on failure.
int List_prepend(List* pList, void* pItem) {
    if (numNodes >= LIST_MAX_NUM_NODES) {
        return 0;
    } else if (pList->size == 0) {
        pList->current = Get_new_node(pItem);
        pList->head = pList->current;
        pList->tail = pList->current;
        pList->size++;
        pList->currentOutOfBoundsFront = false;
        pList->currentOutOfBoundsBack = false;
    } else {
        pList->current = Get_new_node(pItem);
        pList->current->next = pList->head;
        pList->head->previous = pList->current;
        pList->head = pList->current;
        pList->size++;
        if (pList->currentOutOfBoundsBack || pList->currentOutOfBoundsFront) {
            if (pList->currentOutOfBoundsFront)
                pList->currentOutOfBoundsFront = false;
            else
                pList->currentOutOfBoundsBack = false;
        }
    }
}

// Return current item and take it out of pList. Make the next item the current one.
// If the current pointer is before the start of the pList, or beyond the end of the pList,
// then do not change the pList and return NULL.
void* List_remove(List* pList);

// Adds pList2 to the end of pList1. The current pointer is set to the current pointer of pList1.
// pList2 no longer exists after the operation; its head is available
// for future operations.
void List_concat(List* pList1, List* pList2);

// Delete pList. itemFree is a pointer to a routine that frees an item.
// It should be invoked (within List_free) as: (*pItemFree)(itemToBeFreedFromNode);
// pList and all its nodes no longer exists after the operation; its head and nodes are
// available for future operations.
void List_free(List* pList, void* pItemFree);

// Return last item and take it out of pList. Make the new last item the current one.
// Return NULL if pList is initially empty.
void* List_trim(List* pList);

// Search pList, starting at the current item, until the end is reached or a match is found.
// In this context, a match is determined by the comparator parameter. This parameter is a
// pointer to a routine that takes as its first argument an item pointer, and as its second
// argument pComparisonArg. Comparator returns 0 if the item and comparisonArg don't match,
// or 1 if they do. Exactly what constitutes a match is up to the implementor of comparator.
//
// If a match is found, the current pointer is left at the matched item and the pointer to
// that item is returned. If no match is found, the current pointer is left beyond the end of
// the list and a NULL pointer is returned.
typedef bool (*COMPARATOR_FN)(void* pItem, void* pComparisonArg);
void* List_search(List* pList, COMPARATOR_FN pComparator, void* pComparisonArg);
