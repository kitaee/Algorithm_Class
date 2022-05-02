/*
 3. Write a code to check if the following binary tree is a valid binary search tree (BST) or not.
    [8, 3, 9, null, null, 4, 7]
*/

#include <stdio.h>
#include <stdbool.h>
#define __DARWIN_NULL ((void *)0)

int main(void){
    int arr[7] = {8, 3, 9, '\0', '\0', 4, 7};
    bool isValidBst = true;
    for(int i=0;i<3;i++){
        if(arr[2*i+1]!='\0'){   //left node가 null이면 비교x
            if(arr[2*i+1]>arr[i]){  //left node 항상 root node보다 값이 작아야함.
                isValidBst = false;
                break;
            }
        }
        if(arr[2*i+2]!='\0'){   //right node가 null이면 비교x
            if(arr[2*i+2]<arr[i]){  //right node는 항상 root node보다 값이 커야함.
                isValidBst = false;
                break;
            }
        }
    }
    if(isValidBst){
        printf("Valid Binary Search Tree.\n");
    }
    else{
        printf("Unvalid Binary Search Tree.\n");
    }
    
    return 0;
}
