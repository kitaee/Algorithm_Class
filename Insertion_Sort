#include <stdio.h>

void InsertionSort(int arr[], int arrLen);

int main(void){
  int arr[5]={8,5,6,2,4};
  printf("정렬 전의 배열 상태 \n");
  for(int i=0;i<5;i++){
    printf("%d ",arr[i]);
  }
  InsertionSort(arr,5);
  printf("\n정렬 후의 배열 상태 \n");
  for(int i=0;i<5;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}

void InsertionSort(int arr[], int arrLen){
  int target;
  for(int i=1;i<arrLen;i++){
    target = arr[i];
    for(int j=i-1;j>=0;j--){
      if(arr[j]<target){
        break;
      }
      else{
        arr[j+1]=arr[j];
        arr[j]=target;
      }
    }
  }
}
