#include <stdio.h>

int binarySearch(int arr[], int target, int index);

int main(void){
  int arr[16]={1,2,3,5,6,7,8,10,12,13,15,16,18,19,20,22};  // 
  int target;
  int index;
  printf("BINARY SEARCH\n");
  printf("찾고자 하는 타겟넘버를 입력하면 그 타겟넘버의 인덱스를 프린트해준다.\n");
  printf("찾을 타겟넘버를 입력하세요 : ");
  scanf("%d",&target);
  index=binarySearch(arr,target,sizeof(arr)/sizeof(int));
  if(index==-1){
    printf("타겟넘버가 배열 안에 없습니다. \n");
  }
  else{
    printf("타겟넘버의 index는 %d 입니다.\n",index);
  }
  return 0;
}

int binarySearch(int arr[],int target,int size){
  int start=0;
  int end=size-1;

  while(start<=end){
    int mid=(start+end)/2;
    if(arr[mid]==target){
      return mid;
    }
    else if(arr[mid]<target){
      start=mid+1;
    }
    else{
      end=mid-1;
    }
  }
  return -1;
}
