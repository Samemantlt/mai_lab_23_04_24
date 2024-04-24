#ifndef LIST_H
#define LIST_H

#define ELEMENT_TYPE unsigned int
#define BARRIER_PTR NULL

#include "stdbool.h"

struct ListNode {
    ELEMENT_TYPE element;
    struct ListNode *previous;
    struct ListNode *next;
};

struct List {
    struct ListNode* first;
};

struct ListIterator {
    struct List* list;
    struct ListNode* node;
};

typedef struct ListNode tListNode;
typedef struct List tList;
typedef struct ListIterator tListIterator;

tListNode *ListNode_Create(ELEMENT_TYPE element);

void ListNode_Free(tListNode *node);

tList *List_Create();

void List_Append(tList* list, ELEMENT_TYPE element);

void List_Free(tList* list);

tListNode *List_Insert(tList* list, ELEMENT_TYPE element, int index);

void List_RemoveAt(tList* list, int index);

int List_Length(tList* list);

tListIterator ListIterator_Create(tList* list);

void ListIterator_Next(tListIterator* iterator);

void ListIterator_Prev(tListIterator* iterator);

bool ListIterator_HasNext(tListIterator* iterator);

bool ListIterator_HasPrev(tListIterator* iterator);

#endif