#include "list.h"
#include "stdlib.h"

tListNode *ListNode_Create(ELEMENT_TYPE element)
{
    tListNode *node = malloc(sizeof(tListNode));

    node->element = element;
    node->previous = BARRIER_PTR;
    node->next = BARRIER_PTR;

    return node;
}

void ListNode_Free(tListNode *node)
{
    tListNode *prev = node->previous;
    tListNode *next = node->next;

    if (prev != BARRIER_PTR)
        prev->next = next;

    if (next != BARRIER_PTR)
        next->previous = prev;

    free(node);
}

tList *List_Create()
{
    tList *list = malloc(sizeof(tList));
    list->first = BARRIER_PTR;
    return list;
}

void List_Append(tList *list, ELEMENT_TYPE element)
{
    tListNode *newNode = ListNode_Create(element);
    if (list->first == BARRIER_PTR)
    {
        list->first = newNode;
        return;
    }

    tListNode *after = list->first;
    while (after->next != BARRIER_PTR)
        after = after->next;

    after->next = newNode;
    newNode->previous = after;
}

void List_Free(tList *list)
{
    while (list->first != BARRIER_PTR)
    {
        tListNode *next = list->first->next;
        ListNode_Free(list->first);
        list->first = next;
    }
    free(list);
}

tListNode *List_Insert(tList *list, ELEMENT_TYPE element, int index)
{
    tListNode *newNode = ListNode_Create(element);
    if (index == 0)
    {
        newNode->next = list->first;
        if (list->first != BARRIER_PTR)
            list->first->previous = newNode;
        list->first = newNode;
        return newNode;
    }

    tListIterator iter = ListIterator_Create(list);

    int current = 0;
    while (ListIterator_HasNext(&iter) && current + 1 < index)
    {
        ListIterator_Next(&iter);
        current++;
    }

    tListNode *after = iter.node;

    newNode->previous = after;
    newNode->next = after->next;
    after->next = newNode;

    if (newNode->next != BARRIER_PTR)
        newNode->next->previous = newNode;

    return newNode;
}

void List_RemoveAt(tList* list, int index)
{
    tListIterator iter = ListIterator_Create(list);

    int current = 0;
    while (ListIterator_HasNext(&iter) && current < index)
    {
        ListIterator_Next(&iter);
        current++;
    }

    if (current != index)
        return;

    if (iter.node == list->first) {
        list->first = iter.node->next;
    }

    ListNode_Free(iter.node);
}

int List_Length(tList *list)
{
    if (list->first == BARRIER_PTR)
        return 0;

    tListIterator iter = ListIterator_Create(list);

    int current = 1;
    while (ListIterator_HasNext(&iter))
    {
        ListIterator_Next(&iter);
        current++;
    }
    return current;
}

tListIterator ListIterator_Create(tList *list)
{
    tListIterator iterator;

    iterator.list = list;
    iterator.node = list->first;

    return iterator;
}

void ListIterator_Next(tListIterator *iterator)
{
    iterator->node = iterator->node->next;
}

void ListIterator_Prev(tListIterator *iterator)
{
    iterator->node = iterator->node->previous;
}

bool ListIterator_HasNext(tListIterator *iterator)
{
    return iterator->node != BARRIER_PTR && iterator->node->next != BARRIER_PTR;
}

bool ListIterator_HasPrev(tListIterator *iterator)
{
    return iterator->node != BARRIER_PTR && iterator->node->previous != BARRIER_PTR;
}