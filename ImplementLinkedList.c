#include "LinkedList.h"

void main()
{
    int n = 0;
    printf("Enter the size of the LinkedList to create: ");
    scanf("%d", &n);
    int array[n];

    printf("Enter the values to add to the LinkedList:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", array + i);
    }
    
    Node list = createLinkedList(array, n);
    printf("Created LinkedList at memory address %d.\n", list);

    while(list != NULL) {
        printf("%d ", list->value);
        list=list->next;
    }

    printf("is the list");
}

/*
void main()
{
    int n = 23, something[n];
    for (int i = 0; i < n; i++)
    {
        something[i] = i;
    }

    Node somethingLinkedList = createLinkedList(something, n);
    Node head = somethingLinkedList;
    while (somethingLinkedList != NULL)
    {
        printf("%d, ", somethingLinkedList->value);
        somethingLinkedList = somethingLinkedList->next;
    }

    somethingLinkedList = head;
    printf("\n");

    // somethingLinkedList = reverseLinkedList(somethingLinkedList);

    somethingLinkedList = chunkReverseLinkedList(somethingLinkedList, 5);
    while (somethingLinkedList != NULL)
    {
        printf("%d, ", somethingLinkedList->value);
        somethingLinkedList = somethingLinkedList->next;
    }
}
*/