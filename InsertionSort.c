#include <stdio.h>
#include <conio.h>

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

    insertionSort(array, n);

    printf("The array after sorting with insertion sort is: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

void moveElemAtXtoPosY(int *array, int x, int y)
{
    int temp = array[x];
    for (int index = x; index > y; index--)
    {
        array[index] = array[index - 1];
    }
    array[y] = temp;
}

void insertionSort(int *array, int size)
{
    int sortedSublistPosition, index;

    for (sortedSublistPosition = 0; sortedSublistPosition < size; sortedSublistPosition++)
    {
        for (index = 0; index <= sortedSublistPosition; index++)
        {
            if (array[sortedSublistPosition + 1] > array[index])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        moveElemAtXtoPosY(array, sortedSublistPosition + 1, index);
    }
}