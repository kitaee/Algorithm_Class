#include <stdio.h>

void pairSum(int arr[], int target);

int main(void){
  int arr[10]={2,4,3,5,6,-2,4,7,8,9};
  int targetNumber=7;
  pairSum(arr,targetNumber);
  return 0;
}

void pairSum(int arr[], int target){
  printf("[");
  for(int i=0;i<9;i++){
    for(int j=i+1;j<10;j++){
      if(arr[i]+arr[j]==target){
        printf("'%d+%d' ",arr[i],arr[j]);
      }
    }
  }
  printf("]\n");
}
