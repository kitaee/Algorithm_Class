#include <stdio.h>
#define ARRSIZE 8

int data[8];

void merge(int arr[], int m, int middle, int n){
  int i = m;
  int j = middle+1;
  int k = m;
  while(i<=middle && j<=n){
    if(arr[i]<=arr[j]){
      data[k]=arr[i];
      i++;
    }
    else{
      data[k]=arr[j];
      j++;
    }
    k++;
  }
  if(i>middle){  // 왼쪽 배열이 먼저 끝났을 때
    for(int t=j;t<=n;t++){
      data[k]=arr[t];
      k++;
    }  
  }
  else{  // 오른쪽 배열이 먼저 끝났을 때
    for(int t=i;t<=middle;t++){
      data[k]=arr[t];
      k++;
    }
  }
  // 임시 생성된 배열을 원래의 배열로 넣어주기
  for(int t=m;t<=n;t++){
    arr[t]=data[t];
  }
}

void mergeSort(int arr[], int start, int end){
  if(start<end){
    int middle = (start+end)/2;
    mergeSort(arr, start, middle);  // 왼쪽 배열 나누기
    mergeSort(arr, middle+1, end);  // 오른쪽 배열 나누기
    merge(arr,start,middle,end);
  }
}

int main(void){
  int arr[ARRSIZE] = {7,6,5,8,3,5,9,1};
  printf("Merge Sort 적용 전\n");
  for(int i=0; i<ARRSIZE; i++){
    printf("%d ",arr[i]);
  }
  mergeSort(arr,0,ARRSIZE);
  printf("\nMerge Sort 적용 후\n");
  for(int i=0; i<ARRSIZE; i++){
    printf("%d ",arr[i]);
  }
  return 0;
}
