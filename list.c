#include "list.h"
#include "stdlib.h"

tListNode *ListNode_Create(ELEMENT_TYPE element)
{
    tListNode *node = malloc(sizeof(tListNode));

    node->element = element;
    node->previous = getBarrier();
    node->next = getBarrier();

    return node;
}

void ListNode_Free(tListNode *node)
{
    tListNode *prev = node->previous;
    tListNode *next = node->next;

    if (prev != getBarrier())
        prev->next = next;

    if (next != getBarrier())
        next->previous = prev;

    free(node);
}

tList *List_Create()
{
    tList *list = malloc(sizeof(tList));
    list->first = getBarrier();
    return list;
}

void List_Append(tList *list, ELEMENT_TYPE element)
{
    tListNode *newNode = ListNode_Create(element);
    if (list->first == getBarrier())
    {
        list->first = newNode;
        return;
    }

    tListNode *after = list->first;
    while (after->next != getBarrier())
        after = after->next;

    after->next = newNode;
    newNode->previous = after;
}

void List_Free(tList *list)
{
    while (list->first != getBarrier())
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
        if (list->first != getBarrier())
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

    if (newNode->next != getBarrier())
        newNode->next->previous = newNode;

    return newNode;
}

void List_RemoveAt(tList *list, int index)
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

    if (iter.node == list->first)
    {
        list->first = iter.node->next;
    }

    ListNode_Free(iter.node);
}

int List_Length(tList *list)
{
    if (list->first == getBarrier())
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
    return iterator->node != getBarrier() && iterator->node->next != getBarrier();
}

bool ListIterator_HasPrev(tListIterator *iterator)
{
    return iterator->node != getBarrier() && iterator->node->previous != getBarrier();
}

tListNode *getBarrier()
{
    static tListNode *BARRIER_PTR;
    if (BARRIER_PTR == NULL)
    {
        BARRIER_PTR = malloc(sizeof(tListNode));
    }
    return BARRIER_PTR;
}