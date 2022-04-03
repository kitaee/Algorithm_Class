#include <stdio.h>
#include <time.h>

void ordinaryMultiplication(int arrA[][10], int arrB[][50], int resultArr[][50]);

int main(void){
  int arrA[30][10];
  int arrB[10][50];
  int resultArr[30][50];
  int num=1;

  for(int i=0;i<30;i++){
    for(int j=0;j<10;j++){
      arrA[i][j]=num;
      num++;
    }
  }
  num=1;
  for(int i=0;i<10;i++){
    for(int j=0;j<50;j++){
      arrB[i][j]=num;
      num++;
    }
  }
  ordinaryMultiplication(arrA,arrB,resultArr);
}

void ordinaryMultiplication(int arrA[][10], int arrB[][50], int resultArr[][50]){
  double start,end;
  start=(double)clock() / CLOCKS_PER_SEC;
  int mul;
  for(int i=0;i<30;i++){
    for(int j=0;j<50;j++){
      mul=0;
      for(int k=0;k<10;k++){
        mul+=arrA[i][k]*arrB[k][j];
      }
      resultArr[i][j]=mul;
    }
  }
  end=(double)clock() / CLOCKS_PER_SEC;
  printf("Time Execution: %lf\n", (end-start));
}
