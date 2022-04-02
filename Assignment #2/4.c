#include <stdio.h>

int binarySearch(int arr[], int target);  // arr배열안에 target의 index를 반환하는 함수

int main(void){
  int arr[9]={12, 34, 37, 45, 57, 82, 99, 120, 134};
  int targetIndex = binarySearch(arr,120);
  printf("120은 %d 위치에 있습니다.\n",targetIndex);
}

int binarySearch(int arr[], int target){
  int startIndex = 0;
  int endIndex = 8;

  while(startIndex <= endIndex){
    int middleIndex = (startIndex+endIndex)/2;
    if(arr[middleIndex]==target){
      return middleIndex;
    }
    else if(arr[middleIndex]<target){
      startIndex=middleIndex+1;
    }
    else{
      endIndex=middleIndex-1;
    }
  }
  return -1;  // target이 arr배열 안에 없으면 -1 반환
}
