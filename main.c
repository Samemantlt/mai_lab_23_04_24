#include "list.h"
#include "stdio.h"
#include "stdlib.h"

void printList(tList *list)
{
    printf("List: ");
    tListIterator iter = ListIterator_Create(list);
    if (iter.node == getBarrier())
    {
        printf("<empty>\n");
        return;
    }

    printf("%u", iter.node->element);

    while (ListIterator_HasNext(&iter))
    {
        ListIterator_Next(&iter);
        printf(", %u", iter.node->element);
    }
    printf("\n");
}

void appendElement(tList *list, ELEMENT_TYPE element, int index)
{
    List_Insert(list, element, index);
    printf("Appended at: %i!\n", index);
    printList(list);
}

void removeElement(tList *list, int index)
{
    List_RemoveAt(list, index);
    printf("Removed at: %i!\n", index);
    printList(list);
}

void countList(tList *list)
{
    int size = List_Length(list);
    printf("List length: %i\n", size);
}

void repeatToLength(tList *list, ELEMENT_TYPE element, int targetLength)
{
    while (List_Length(list) < targetLength)
    {
        List_Append(list, element);
    }
    printList(list);
    printf("List length: %i\n", List_Length(list));
}

void printMenu()
{
    printf("[0] - Exit\n");
    printf("[1] - Print list\n");
    printf("[2] - Append\n");
    printf("[3] - Remove\n");
    printf("[4] - Count\n");
    printf("[5] - Repeat to length\n");
}

int main()
{
    tList *list = List_Create();

    while (true)
    {
        int command;
        printf("\n");
        printMenu();
        printf("Enter command index: ");
        scanf("%i", &command);

        if (command == 0)
            break;

        if (command == 1)
        {
            printList(list);
            continue;
        }

        if (command == 2)
        {
            int index;
            ELEMENT_TYPE element;

            printf("Index: ");
            scanf("%i", &index);

            printf("Value: ");
            scanf("%ui", &element);

            appendElement(list, element, index);
            continue;
        }

        if (command == 3)
        {
            int index;
            printf("Index: ");
            scanf("%i", &index);

            removeElement(list, index);
            continue;
        }

        if (command == 4)
        {
            countList(list);
            continue;
        }

        if (command == 5)
        {
            int targetLength;
            ELEMENT_TYPE element;

            printf("Target length: ");
            scanf("%i", &targetLength);

            printf("Value: ");
            scanf("%ui", &element);

            repeatToLength(list, element, targetLength);
            continue;
        }
    }

    List_Free(list);
    return 0;
}