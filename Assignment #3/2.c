/*
 2. Write a code to remove duplicates from an unsorted linked list. 
    Generate a linked list of size 20 whose elements are from 1 to 50. Write a function to check and remove duplicate numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//linked List 구조체
typedef struct NODE{
    int data;
    struct NODE* nextNode; // 자기참조 구조체
}node;

void append(node* linkedList, int newData);
void traverse(node* linkedList);
void checkAndRemoveDuplicate(node* linkedList);

int main(void){
    int randomNumber;
    node* linkedList = malloc(sizeof(node));    //linkedList 1개 생성
    srand(time(NULL));
    for(int i=0;i<20;i++){   //linkedList에 1~50의 랜덤값을 가지는 20개의 노드 생성
        randomNumber = rand()%50+1;
        append(linkedList,randomNumber);
    }
    printf("--------중복 체크 & 제거 전 --------\n");
    traverse(linkedList);
    printf("--------중복 체크 & 제거 후 --------\n");
    checkAndRemoveDuplicate(linkedList);
    traverse(linkedList);
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
void traverse(node* linkedList){
    node* traverseNode = linkedList->nextNode;
    printf("노드 값 출력 : ");
    while(traverseNode!=NULL){  //마지막 노드까지 순회해주면서 값 출력
        printf("%d ", traverseNode->data);
        traverseNode = traverseNode->nextNode;
    }
    printf("\n");
}
void checkAndRemoveDuplicate(node* linkedList){
    int stack[20];  //중복을 확인해줄 stack 배열
    int index=1;
    node* traverseNode = linkedList->nextNode;
    stack[0] = traverseNode->data;
    while(traverseNode->nextNode!=NULL){
        bool isDuplicated = false;
        for(int i=0;i<index;i++){
            if(traverseNode->nextNode->data == stack[i]){ //중복된 값이 있을 경우
                traverseNode->nextNode = traverseNode->nextNode->nextNode; 
                isDuplicated = true;
                break;
            }
        }
        if(isDuplicated){
            continue;
        }
        else{
            stack[index] = traverseNode->data;
            index++;
            traverseNode = traverseNode->nextNode;
        }    
    }
}
