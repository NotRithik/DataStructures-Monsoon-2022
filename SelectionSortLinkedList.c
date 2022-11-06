#include "LinkedList.h"

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

    printf("The LinkedList after sorting with selection sort is: ");

    Node sortedNode = list;
    Node comparisonNode;

    while (sortedNode != NULL)
    {
        comparisonNode = sortedNode->next;
        while (comparisonNode != NULL)
        {
            if (comparisonNode->value < sortedNode->value)
            {
                swapNodes(sortedNode, comparisonNode);
            }
            comparisonNode = comparisonNode->next;
        }
        sortedNode = sortedNode->next;
    }

    while (list != NULL)
    {
        printf("%d ", list->value);
        list = list->next;
    }
}
