#include <stdio.h>

void rotateArray(int arr[][5]);
void printArray(int arr[][5]);

int main(void){
  int arr[5][5]={{11,12,13,14,15},{21,22,23,24,25},{31,32,33,34,35},{41,42,43,44,45},{51,52,53,54,55}};
  printf("Before Roation\n");
  printArray(arr);
  printf("\n");
  printf("First Roation\n");
  rotateArray(arr);
  printArray(arr);
  printf("\n");
  printf("Second Roation\n");
  rotateArray(arr);
  printArray(arr);
  printf("\n");
  printf("Third Roation\n");
  rotateArray(arr);
  printArray(arr);
  printf("\n");
  printf("Fourth Roation\n");
  rotateArray(arr);
  printArray(arr);
  printf("\n");
}

void rotateArray(int arr[][5]){
  int rotated[5][5];
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      rotated[j][4-i] = arr[i][j];
    }
  }
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      arr[i][j]=rotated[i][j];
    }
  }
}

void printArray(int arr[][5]){
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
}
