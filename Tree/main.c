#include <stdio.h>
#include "Tree.h"
typedef int TYPE;
void printData(TYPE *data) {
    printf("%d ", *data);
}

int main() {
    TreeType myTree;
    createTree(&myTree);
    fillTree(&myTree);
    // Print the data using Inorder traversal
    printf("Inorder traversal: ");
    inOrderTrav(myTree, printData);
    // Add more function calls or create your logic here
    
    return 0;
}
