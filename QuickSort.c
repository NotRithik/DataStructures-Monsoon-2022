#include <stdio.h>
#include <conio.h>

void quickSort(int *array, int startPos, int endPos);

void moveElemAtXtoPosY(int *array, int x, int y);

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

    quickSort(array, 0, n);

    printf("The array after sorting with quickSort is: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

void quickSort(int *array, int startPos, int endPos)
{

    if (endPos <= startPos)
    {
        return;
    }

    int partition = startPos;

    for (int i = startPos; i < endPos; i++)
    {
        if (array[i] < array[partition])
        {
            moveElemAtXtoPosY(array, i, partition);
            partition += 1;
        }
    }

    quickSort(array, startPos, partition);
    quickSort(array, partition + 1, endPos);
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