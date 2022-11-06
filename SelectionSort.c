#include <stdio.h>
#include <conio.h>

void selectionSort(int *array, int size);

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

    selectionSort(array, n);

    printf("The array after sorting with selection sort is: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

void selectionSort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j =  i + 1; j < size; j++)
        {
            if(array[j] < array[i]) {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}