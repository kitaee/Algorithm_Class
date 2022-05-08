/*
 5. Write a code to construct a red-black tree by successively inserting the keys 41, 38, 31, 12, 19, 8 into an
    initially empty red-black tree. You are required to implement functions to build the tree, such as left-rotate and
    right-rotate. Each key should be accompanied by its corresponding color (red or black) in your code. Then,
    show the in-order/pre-order/post-order traversal results in your console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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

void leftRotation(tree *targetTree, node *targetNode);
void rightRotation(tree *targetTree, node *targetNode);
// void changeNodeStatus(bool condition)
void reconstructRedBlackTree(tree *targetTree, node *targetNode);
void appendNode(tree *targetTree, node *targetNode);
void preOrder(tree *targetTree, node *targetNode);
void inOrder(tree *targetTree, node *targetNode);
void postOrder(tree *targetTree, node *targetNode);

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
        node *tempNode = malloc(sizeof(node));
        tempNode->parent = NULL;
        tempNode->leftChild = NULL;
        tempNode->rightChild = NULL;
        tempNode->data = arr[i];
        tempNode->color = 1;
        appendNode(newTree, tempNode);
    }

    printf("------------------- 결과물 출력 -------------------\n");
    printf("노드 데이터 값(색깔) 형식으로 출력 - 0이면 Black, 1이면 Red를 의미함\n");

    printf("PreOrder Traversal Result Print : ");
    preOrder(newTree, newTree->root);
    printf("\n");
    printf("InOrder Traversal Result Print : ");
    inOrder(newTree, newTree->root);
    printf("\n");
    printf("PostOrder Traversal Result Print : ");
    postOrder(newTree, newTree->root);
    printf("\n");


    return 0;
}

void leftRotation(tree *targetTree, node *targetNode){
    node *tempNode = targetNode->rightChild;
    targetNode->rightChild = tempNode->leftChild;

    if (targetNode == targetNode->parent->leftChild){
        targetNode->parent->leftChild = tempNode;
    }

    else if (targetNode->parent == targetTree->NIL){
        targetTree->root = tempNode;
    }
    else{
        targetNode->parent->rightChild = tempNode;
    }

    tempNode->leftChild = targetNode;
    targetNode->parent = tempNode;

    if (tempNode->leftChild != targetTree->NIL){
        tempNode->leftChild->parent = targetNode;
    }

    tempNode->parent = targetNode->parent;
}
void rightRotation(tree *targetTree, node *targetNode){
    node *tempNode = targetNode->leftChild;
    targetNode->leftChild = tempNode->rightChild;

    if (targetNode == targetNode->parent->leftChild){
        targetNode->parent->leftChild = tempNode;
    }
    else if (targetNode->parent == targetTree->NIL){
        targetTree->root = tempNode;
    }
    else{
        targetNode->parent->rightChild = tempNode;
    }
    tempNode->rightChild = targetNode;
    targetNode->parent = tempNode;

    if (tempNode->rightChild != targetTree->NIL){
        tempNode->rightChild->parent = targetNode;
    }

    tempNode->parent = targetNode->parent;
}

void reconstructRedBlackTree(tree *targetTree, node *targetNode){

    // 코드 간편성을 위해 임의 설정 // 
    node *grandParentNode = targetNode->parent->parent;
    int targetColor = targetNode->parent->color;
    bool condition;

    if(targetColor == 1){
        condition = true;
    }
    while (condition){
        if (targetNode->parent != grandParentNode->leftChild){
            node *tempNode = grandParentNode->leftChild;
            if (tempNode->color != 1){
                if (targetNode == targetNode->parent->leftChild){
                    targetNode = targetNode->parent;
                    rightRotation(targetTree, targetNode);
                }
                targetColor = 0;
                condition = false;
                grandParentNode->color = 1;
                leftRotation(targetTree, grandParentNode);
            }
            else{
                targetColor = 0;
                condition = false;
                tempNode->color = 0;
                grandParentNode->color = 1;
                targetNode = grandParentNode;
            }
        }
        else{
            node *tempNode = grandParentNode->rightChild;
            if (tempNode->color != 1){
                if (targetNode == targetNode->parent->rightChild){
                    targetNode = targetNode->parent;
                    leftRotation(targetTree, targetNode);
                }
                targetColor = 0;
                condition = false;
                grandParentNode->color = 1;
                rightRotation(targetTree, grandParentNode);
            }
            else{
                targetColor = 0;
                condition = false;
                tempNode->color = 0;
                grandParentNode->color = 1;
                targetNode = grandParentNode;
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
        if (targetNode->data > tempNode2->data){
            tempNode2 = tempNode2->rightChild;
        }
        else{
            tempNode2 = tempNode2->leftChild;
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

void preOrder(tree *targetTree, node *targetNode){
    if (targetNode != targetTree->NIL){
        printf("%d(%d) ", targetNode->data, targetNode->color);
        preOrder(targetTree, targetNode->leftChild);
        preOrder(targetTree, targetNode->rightChild);
    }
}
void inOrder(tree *targetTree, node *targetNode){
    if (targetNode != targetTree->NIL){
        inOrder(targetTree, targetNode->leftChild);
        printf("%d(%d) ", targetNode->data, targetNode->color);
        inOrder(targetTree, targetNode->rightChild);
    }
}
void postOrder(tree *targetTree, node *targetNode){
    if (targetNode != targetTree->NIL){
        postOrder(targetTree, targetNode->leftChild);
        postOrder(targetTree, targetNode->rightChild);
        printf("%d(%d) ", targetNode->data, targetNode->color);
    }
}
