#include <stdio.h>
#include <stdlib.h>

void siftUpMax(int *heap, int childPositionToSiftUpFrom)
{
    // Base case, when root is being sifted up
    if (childPositionToSiftUpFrom == 0)
        return;

    // Figure out if the current child is the right child or the left child.
    // We need to do this because we're assuming our heap insertions always populate the left child slot
    // first, then populate the right child.
    // So, if there is only a left child for a particular node, it is guaranteed that the node has only 1
    // child. If it has a right child, then it is guaranteed that there is a left child as well, meaning
    // that node has 2 children.

    // Since our arrays are indexed with 0, the first child of the 0th node would have position 1
    // and the second child of the 0th node would have position 2
    // Thus, even positions are right children and odd positions are left children

    int parentPosition = (int)(childPositionToSiftUpFrom - 1) / 2;
    // From the relation (left child) = (2*parent) + 1
    // and              (right child) = (2*parent) + 2

    if (heap[childPositionToSiftUpFrom] > heap[parentPosition])
    {
        // Swap if heap property is violated for the child
        int temp = heap[childPositionToSiftUpFrom];
        heap[childPositionToSiftUpFrom] = heap[parentPosition];
        heap[parentPosition] = temp;
    }

    // If the child position that was passed to us was a right child,
    // this would ensure the heap property is maintained between the right child
    // and the parent.

    // If the child position that was passed to us was a left child,
    // it would do it for the left child.

    if (childPositionToSiftUpFrom % 2 == 0) // If the child position is a right child,
    // Only the right child was checked. We need to check the left child and make sure it
    // follows the heap property too.
    {
        // Decrement childPosition by 1, so it points to the left child instead of the
        // right child now, and then do the check again

        siftUpMax(heap, childPositionToSiftUpFrom - 1);
    }
    else
    {
        // Now, siftUp again from parent position
        siftUpMax(heap, parentPosition);
    }
}

void siftDownMax(int *heap, int nodeToSiftDownFrom, int size)
{
    // Base case, when lowest level of children has been reached, exit
    // We know we are at the lowest level when the left child position of the current node
    // is out of bounds
    int childToCompareWith = (2 * nodeToSiftDownFrom) + 1;

    if (childToCompareWith >= size)
    {
        return;
    }

    if (heap[nodeToSiftDownFrom] < heap[childToCompareWith])
    {
        // Swap if node is smaller than child
        int temp = heap[nodeToSiftDownFrom];
        heap[nodeToSiftDownFrom] = heap[childToCompareWith];
        heap[childToCompareWith] = temp;

        // Proceed to siftDown from here
        siftDownMax(heap, childToCompareWith, size);
    }

    // Check if right child exists
    childToCompareWith++;
    if (childToCompareWith >= size) // In case right child doesn't exist, just stop here
    {
        return;
    }

    // Swap if node is smaller than child
    if (heap[nodeToSiftDownFrom] < heap[childToCompareWith])
    {
        int temp = heap[nodeToSiftDownFrom];
        heap[nodeToSiftDownFrom] = heap[childToCompareWith];
        heap[childToCompareWith] = temp;

        siftDownMax(heap, childToCompareWith, size); // Sift down from the right child
    }
}

void maxHeapify(int *array, int size)
{
    int currentHeapSize = 0; // The array will be turned into a heap by assuming the heap is of size x
    // and the array is of size (size - x). The first x elements of the array are the heap.
    // the heap grows by 1 element on each iteration of the loop. The heap is created once the
    // size of the heap, x grows to be the same as the size of the initial array (the variable 'size')

    for (currentHeapSize = 0; currentHeapSize < size; currentHeapSize++)
    {
        // insert element from array into heap
        // in this implementation, insertion into heap happens automatically as the size of the heap
        // grows to include the next array element into the heap.
        // thus the last child of the heap is always the element which was implicitly inserted into
        // the heap.

        // So, we just need to siftUp the last child on each iteration
        siftUpMax(array, currentHeapSize);
    }
}

void heapSort(int *heap, int size)
// Takes a heap as input and sorts it with heapSort (selectionSort)
// and converts the heap into a sorted array
{
    // swap root and last child, make the root part of the array and decrement size of heap by 1
    // Now siftDown from the root. This makes it so that the array is built from the highest index
    // of the array down to the lowest index

    for (int heapSize = size - 1; heapSize > 0; heapSize--)
    {
        int temp = heap[0];
        heap[0] = heap[heapSize];
        heap[heapSize] = temp;

        siftDownMax(heap, 0, heapSize);
    }
}

void main()
{
    int arrayToHeapify[] = {19, 64, 73, 69, 41, 29, 78, 8, 2, 0};

    maxHeapify(arrayToHeapify, 10);
    printf("The maxHeap is: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arrayToHeapify[i]);
    }

    printf("\nThe heapSorted array is: ");
    heapSort(arrayToHeapify, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arrayToHeapify[i]);
    }
    printf("\n");
}