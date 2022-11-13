#include "LinkedList.h"

void printHalfLinkedList(Node list);

void main()
{

    printf("Enter the size of the list: ");
    int n;
    scanf("%d", &n);

    int array[n];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", array + i);
    }

    Node list = createLinkedList(array, n);

    printf("Half the LinkedList is: ");
    printHalfLinkedList(list);
}

void printHalfLinkedList(Node list)
{
    if (list == NULL)
    {
        return;
    }

    Node harePointer = list;
    Node tortoisePointer = list;

    while (1)
    {
        printf("%d ", tortoisePointer->value);

        if ((harePointer = harePointer->next) != NULL)
        {
            if ((harePointer = harePointer->next) != NULL)
            {
                tortoisePointer = tortoisePointer->next;
                continue;
            }
        }

        return;
    }
}
