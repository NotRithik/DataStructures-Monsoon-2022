#include "LinkedList.h"

void main()
{
    int n = 0;
    printf("Enter the size of the LinkedList to create and reverse: ");
    scanf("%d", &n);
    int array[n];

    printf("Enter the values to add to the LinkedList:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", array + i);
    }

    Node list = createLinkedList(array, n);
    printf("Created LinkedList at memory address %d.\n", list);

    Node head = list;

    while (list != NULL)
    {
        printf("%d ", list->value);
        list = list->next;
    }

    printf("is the list before reversal\n");

    list = reverseLinkedList(head);

    while (list != NULL)
    {
        printf("%d ", list->value);
        list = list->next;
    }

    printf("is the list after reversal\n");
}
