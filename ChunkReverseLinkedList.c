#include "LinkedList.h"

void main()
{
    int n, k;
    printf("Enter the size of the LinkedList to create and chunk-reverse: ");
    scanf("%d", &n);
    int array[n];

    printf("ENter the chunk size for list reversal: ");
    scanf("%d", &k);

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

    printf("is the list before chunk-reversal\n");

    list = chunkReverseLinkedList(head, k);

    while (list != NULL)
    {
        printf("%d ", list->value);
        list = list->next;
    }

    printf("is the list after chunk-reversal\n");
}
