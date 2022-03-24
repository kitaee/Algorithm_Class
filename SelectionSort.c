#include <stdio.h>

void Swap(int *data1, int *data2);
void SelectionSort(int arr[],int length);

int main(void){
  int arr[7]={7,4,5,9,8,2,1};
  int length = sizeof(arr)/sizeof(int);
  printf("-----정렬 전-----\n");
  for(int i=0;i<length;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
  SelectionSort(arr,length);
  printf("-----정렬 후-----\n");
  for(int i=0;i<length;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
  
}
void SelectionSort(int arr[],int length){
  for(int i=0;i<length-1;i++){
    int minIndex=i;
    for(int j=i;j<length;j++){
      if(arr[minIndex]>arr[j]){
        minIndex=j;
      }
    }
    if(arr[i]!=arr[minIndex]){
      Swap(&arr[i],&arr[minIndex]);
    }
  }
}

void Swap(int *data1, int *data2){
  int temp = *data1;
  *data1 = *data2;
  *data2 = temp;
}
