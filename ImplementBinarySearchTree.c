#include "BST.h"

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

    printf("The BST is: ");

    BinaryTreeNode BST = createBinaryTreeFromArray(array, n);

    printBinaryTree(BST);

    printf("\n\n%d is the min and %d is the max\n", findMinimumInBST(BST)->value, findMaximumInBST(BST)->value);
    printf("\n%d is the successor of %d\n\n\n", findSuccessorInBST(findElementInBinaryTree(BST, 4))->value, 4);

    printBinaryTree(BST);
    printf("\n");

    printBinaryTree(BST);
}