/*
 4. Write a code to find the lowest common ancestor in position between two given nodes in the following binary search tree
    [6, 2, 8, 1, 3, 7, 9]
    Write a function to find the lowest common ancestor by taking two inputs from the console. 
    Show the results for three different pairs of inputs. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data; 
    struct NODE* leftChild; 
    struct NODE* rightChild; 
}node;

node* insertNode(node* root, int data);
node* getLowestCommonAncestor(node* root, int num1, int num2);


int main(void){
    int arr[7] = {6,2,8,1,3,7,9};
    int num1, num2;
    node* lowestCommonAncestor=NULL;
    node* root = NULL;
    for(int i=0;i<7;i++){
        root = insertNode(root,arr[i]);
    }
    for(int i=0;i<3;i++){
        printf("두 수를 입력해주세요 : ");
        scanf("%d %d",&num1,&num2);
        printf("%d번째 case : num1 : %d, num2 : %d -> Lowest Common Ancestor : %d\n",i+1,num1,num2,getLowestCommonAncestor(root,num1,num2)->data);
    }
    return 0;
}

node* insertNode(node* root, int data){
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
        root->leftChild = root->rightChild = NULL;
        root->data = data;
    }
    else{
        if(data < root->data){
            root->leftChild = insertNode(root->leftChild,data);
        }
        else{
            root->rightChild = insertNode(root->rightChild,data);
        }
    }
    return root;
}
node* getLowestCommonAncestor(node* root, int num1, int num2){
    if(root == NULL){
        return NULL;
    }
    if(root->data > num1 && root->data > num2){
        return getLowestCommonAncestor(root->leftChild, num1, num2);
    }
    if(root->data < num1 && root->data < num2){
        return getLowestCommonAncestor(root->rightChild, num1, num2);
    }
    return root;
}

