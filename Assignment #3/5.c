/*
 5. Write a code to construct a red-black tree by successively inserting the keys 41, 38, 31, 12, 19, 8 into an
    initially empty red-black tree. You are required to implement functions to build the tree, such as leftChild-rotate and
    right-rotate. Each key should be accompanied by its corresponding color (red or black) in your code. Then,
    show the in-order/pre-order/post-order traversal results in your console.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    struct NODE *parent;
    struct NODE *leftChild;
    struct NODE *rightChild;
    int data;
    int color;
}node;

typedef struct TREE{
    node *root;
    node *NIL;
}tree;

node *newNode(int data){
    node *tempNode = malloc(sizeof(node));

    tempNode->parent = NULL;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;
    tempNode->data = data;
    tempNode->color = 1;

    return tempNode;
}

void leftRotation(tree *targetTree, node *targetNode){
    node *tempNode = targetNode->rightChild;
    targetNode->rightChild = tempNode->leftChild;

    if (tempNode->leftChild != targetTree->NIL){
        tempNode->leftChild->parent = targetNode;
    }

    tempNode->parent = targetNode->parent;

    if (targetNode->parent == targetTree->NIL){
        targetTree->root = tempNode;
    }
    else if (targetNode == targetNode->parent->leftChild){
        targetNode->parent->leftChild = tempNode;
    }
    else{
        targetNode->parent->rightChild = tempNode;
    }
    tempNode->leftChild = targetNode;
    targetNode->parent = tempNode;
}

void rightRotation(tree *targetTree, node *targetNode){
    node *tempNode = targetNode->leftChild;
    targetNode->leftChild = tempNode->rightChild;

    if (tempNode->rightChild != targetTree->NIL){
        tempNode->rightChild->parent = targetNode;
    }

    tempNode->parent = targetNode->parent;

    if (targetNode->parent == targetTree->NIL){
        targetTree->root = tempNode;
    }
    else if (targetNode == targetNode->parent->leftChild){
        targetNode->parent->leftChild = tempNode;
    }
    else{
        targetNode->parent->rightChild = tempNode;
    }
    tempNode->rightChild = targetNode;
    targetNode->parent = tempNode;
}

void reconstructRedBlackTree(tree *targetTree, node *targetNode){
    while (targetNode->parent->color == 1){
        if (targetNode->parent == targetNode->parent->parent->leftChild){
            node *tempNode = targetNode->parent->parent->rightChild;
            if (tempNode->color == 1){
                targetNode->parent->color = 0;
                tempNode->color = 0;
                targetNode->parent->parent->color = 1;
                targetNode = targetNode->parent->parent;
            }
            else{
                if (targetNode == targetNode->parent->rightChild){
                    targetNode = targetNode->parent;
                    leftRotation(targetTree, targetNode);
                }
                targetNode->parent->color = 0;
                targetNode->parent->parent->color = 1;
                rightRotation(targetTree, targetNode->parent->parent);
            }
        }
        else{
            node *tempNode = targetNode->parent->parent->leftChild;
            if (tempNode->color == 1){
                targetNode->parent->color = 0;
                tempNode->color = 0;
                targetNode->parent->parent->color = 1;
                targetNode = targetNode->parent->parent;
            }
            else{
                if (targetNode == targetNode->parent->leftChild){
                    targetNode = targetNode->parent;
                    rightRotation(targetTree, targetNode);
                }
                targetNode->parent->color = 0;
                targetNode->parent->parent->color = 1;
                leftRotation(targetTree, targetNode->parent->parent);
            }
        }
    }
    targetTree->root->color = 0;
}

void appendNode(tree *targetTree, node *targetNode){
    node *tempNode1 = targetTree->NIL;
    node *tempNode2 = targetTree->root;
    while (tempNode2 != targetTree->NIL){
        tempNode1 = tempNode2;
        if (targetNode->data < tempNode2->data){
            tempNode2 = tempNode2->leftChild;
        }
        else{
            tempNode2 = tempNode2->rightChild;
        }
    }
    targetNode->parent = tempNode1;
    if (tempNode1 == targetTree->NIL){
        targetTree->root = targetNode;
    }
    else if (targetNode->data < tempNode1->data){
        tempNode1->leftChild = targetNode;
    }
    else{
        tempNode1->rightChild = targetNode;
    }
    targetNode->leftChild = targetTree->NIL;
    targetNode->rightChild = targetTree->NIL;
    targetNode->color = 1;
    reconstructRedBlackTree(targetTree, targetNode);
}

void inOrder(tree *targetTree, node *targetNode){
    if (targetNode != targetTree->NIL){
        inOrder(targetTree, targetNode->leftChild);
        printf("%d ", targetNode->data);
        inOrder(targetTree, targetNode->rightChild);
    }
}

void preOrder(tree *targetTree, node *targetNode){
    if (targetNode != targetTree->NIL){
        printf("%d ", targetNode->data);
        preOrder(targetTree, targetNode->leftChild);
        preOrder(targetTree, targetNode->rightChild);
    }
}

void postOrder(tree *targetTree, node *targetNode){
    if (targetNode != targetTree->NIL){
        postOrder(targetTree, targetNode->leftChild);
        postOrder(targetTree, targetNode->rightChild);
        printf("%d ", targetNode->data);
    }
}



int main(){

    int arr[6] = {41, 38, 31, 12, 19, 8};

    tree *newTree = malloc(sizeof(tree));
    node *nilNode = malloc(sizeof(node));

    nilNode->parent = NULL;
    nilNode->leftChild = NULL;
    nilNode->rightChild = NULL;
    nilNode->data = 0;
    nilNode->color = 0;
    newTree->NIL = nilNode;
    newTree->root = newTree->NIL;

    for(int i=0;i<6;i++){
        node *tempNode = newNode(arr[i]);
        appendNode(newTree, tempNode);
    }

    inOrder(newTree, newTree->root);
    printf("\n");
    preOrder(newTree, newTree->root);
    printf("\n");
    postOrder(newTree, newTree->root);
    printf("\n");


    return 0;
}
