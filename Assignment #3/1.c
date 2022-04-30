/*
 1. Write a code to reverse a linked list. Write also the following functions: append, insert, traverse, remove, and reverse. 
    Generate a linked list of size 10 whose elements are chosen randomly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//linked List 구조체
typedef struct NODE{
    int data;
    struct NODE* nextNode; // 자기참조 구조체
}node;

void traverse(node* linkedList);
void append(node* linkedList, int newData);
void removeNode(node* linkedList, int targetData);
void insert(node* linkedList, int newData, int index);  //시작노드를 index 0으로 잡고 순차적으로 증가하는 구조
node* reverse(node* linkedList);

int main(void){
    int randomNumber;
    node* linkedList = malloc(sizeof(node));    //linkedList 1개 생성
    srand(time(NULL));
    for(int i=0;i<10;i++){   //linkedList에 랜덤값을 가지는 10개의 노드 생성
        randomNumber = rand()%99+1;
        append(linkedList,randomNumber);
    }
    traverse(linkedList);
    node* reversedLinkedList = reverse(linkedList);
    traverse(reversedLinkedList);
    return 0;
}


void traverse(node* linkedList){
    node* traverseNode = linkedList->nextNode;
    printf("노드 값 출력 : ");
    while(traverseNode!=NULL){  //마지막 노드까지 순회해주면서 값 출력
        printf("%d ", traverseNode->data);
        traverseNode = traverseNode->nextNode;
    }
    printf("\n");
}
void append(node* linkedList, int newData){
    if(linkedList->nextNode==NULL){ //last node이면, 바로 값만 넣어주면 됨
        node* newNode = malloc(sizeof(node));
        newNode->nextNode = NULL;
        newNode->data = newData;
        linkedList->nextNode = newNode;
    }
    else{   //Last node가 아닌경우, 임시 노드를 끝으로 보내놓고 넣으면 됨
        node* tempNode = linkedList;
        while(tempNode->nextNode!=NULL){
            tempNode = tempNode->nextNode;
        }
        node* newNode = malloc(sizeof(node));
        newNode->nextNode = NULL;
        newNode->data = newData;
        tempNode->nextNode = newNode;
    }
}
void removeNode(node* linkedList, int targetData){
    if(linkedList==NULL){   //빈 linkedList일 경우
        return;
    }
    else if(linkedList->data == targetData){    //처음 노드가 targetData일 경우
        linkedList = linkedList->nextNode;
    }
    else{
        node* traverseNode = linkedList;
        while(traverseNode->nextNode!=NULL){
            if(traverseNode->nextNode->data == targetData){
                traverseNode->nextNode = traverseNode->nextNode->nextNode;
            }
            else{
                traverseNode = traverseNode->nextNode;
            }
        }
    }
}
void insert(node* linkedList, int newData, int index){
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;
    newNode->nextNode = NULL;

    if(index == 0){
        newNode->nextNode = linkedList->nextNode;
        linkedList->nextNode = newNode;
    }

    else{
        int count = 0;
        while(count!=index){
            if(count == index-1){
                newNode->nextNode = linkedList->nextNode;
                linkedList->nextNode = newNode;
            }
            linkedList = linkedList->nextNode;
            count++;
        }
    }
}
node* reverse(node* linkedList){
    node* reversedLinkedList = malloc(sizeof(node));
    node* tempNode = linkedList->nextNode;
    int stack[10];
    int index=0;
    while(tempNode->nextNode!=NULL){
        stack[index] = tempNode->data;
        tempNode = tempNode->nextNode;
        index++;
    }
    stack[index] = tempNode->data;
    for(int i=9;i>=0;i--){
        append(reversedLinkedList,stack[i]);
    }
    return reversedLinkedList;
}
