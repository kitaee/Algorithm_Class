#include <stdio.h>

void BubbleSort(int arr[],int length);
void Swap(int *data1, int *data2);

int main(void){
  int array[5]={3,2,4,1,5};
  int length = sizeof(array)/sizeof(int);
  printf("-----정렬 전-----\n");
  for(int i=0;i<length;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
  BubbleSort(array,length);
  printf("-----정렬 후-----\n");
  for(int i=0;i<length;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
  return 0;
}

void BubbleSort(int arr[],int length){
  for(int i=0;i<length-1;i++){
    for(int j=0;j<length-i;j++){
      if(arr[j]>arr[j+1]){
        Swap(&arr[j],&arr[j+1]);
      }
    }
  }
}

void Swap(int *data1, int *data2){
  int temp = *data1;
  *data1 = *data2;
  *data2 = temp;
}
