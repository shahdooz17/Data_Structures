#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "../Stack/stack.h"

void createTree(Tree *tree)
{
    *tree = NULL;
}

int isTreeEmpty(Tree *tree)
{
    return (*tree == NULL);
}

void fillTree(Tree *tree)
{
    TreeNode *n81 = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *n22 = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *n6 = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *n41 = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *n18 = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *n9 = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *n17 = (TreeNode *)malloc(sizeof(TreeNode));

    n81->data = 81;
    n81->right = NULL;
    n81->left = NULL;
    n22->data = 22;
    n22->right = n81;
    n22->left = NULL;
    n6->data = 6;
    n6->right = NULL;
    n6->left = NULL;
    n41->data = 41;
    n41->right = n6;
    n41->left = n22;
    n18->data = 18;
    n18->right = NULL;
    n18->left = NULL;
    n9->data = 9;
    n9->right = NULL;
    n9->left = n18;
    n17->data = 17;
    n17->right = n9;
    n17->left = n41;
    *tree = n17;
}

void inOrderTrav(Tree tree, void (*pvisit)(TreeType *))
{
    Stack s;
    createStack(&s); // Assuming this function is implemented correctly

    TreeNode *travNode = tree;
    while (travNode != NULL || !isStackEmpty(s))
    {
        while (travNode != NULL)
        {
            push(&s, travNode); // Assuming push function is implemented correctly

            travNode = travNode->left;
        }
        
        travNode = (TreeNode*)pop(&s); // Assuming pop function is implemented correctly
        (*pvisit)(&(travNode->data));
        travNode = travNode->right;
    }
}

void inOrderTravRec(Tree tree, void (*pvisit)(TreeType *))
{
    if (tree != NULL)
    {
        inOrderTravRec(tree->left, pvisit);
        (*pvisit)(&(tree->data));
        inOrderTravRec(tree->right, pvisit);
    }
}

void preOrderTravRec(Tree tree, void (*pvisit)(TreeType *))
{
    if (tree != NULL)
    {
        (*pvisit)(&(tree->data));
        preOrderTravRec(tree->left, pvisit);
        preOrderTravRec(tree->right, pvisit);
    }
}

void postOrderTravRec(Tree tree, void (*pvisit)(TreeType *))
{
    if (tree != NULL)
    {
        postOrderTravRec(tree->left, pvisit);
        postOrderTravRec(tree->right, pvisit);
        (*pvisit)(&(tree->data));
    }
}

void printNode(TreeType *data)
{
    printf("%d ", *data);
}

int treeSize(Tree tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    return 1 + treeSize(tree->left) + treeSize(tree->right);
}

int treeHeight(Tree tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    int leftHeight = treeHeight(tree->left);
    int rightHeight = treeHeight(tree->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}