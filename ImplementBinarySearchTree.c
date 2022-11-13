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

    /*
        *** something written just to see if the binary tree
        *** print function is working properly or not!

        *

        BinaryTreeNode BST = createBinaryTreeNode(10);
        BST->left = createBinaryTreeNode(4);
        BST->left->left = createBinaryTreeNode(3);
        BST->left->right = createBinaryTreeNode(5);

        BST->right = createBinaryTreeNode(15);
        BST->right->left = createBinaryTreeNode(13);
        BST->right->right = createBinaryTreeNode(16);

        */

    printf("The BST is: ");

    BinaryTreeNode BST = createBinaryTreeFromArray(array, n);

    printBinaryTree(BST);
}