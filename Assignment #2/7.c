#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int A[30][10], B[10][50], C1[30][50], C2[30][50]; 
int subMatrixA11[15][5], subMatrixA12[15][5], subMatrixA21[15][5], subMatrixA22[15][5]; 
int subMatrixB11[5][25], subMatrixB12[5][25], subMatrixB21[5][25], subMatrixB22[5][25]; 
int temp1[15][5], temp2[5][25];
int M1[15][25], M2[15][25], M3[15][25], M4[15][25], M5[15][25], M6[15][25], M7[15][25];
int subMatrixC11[15][25], subMatrixC12[15][25], subMatrixC21[15][25], subMatrixC22[15][25]; 


void makeMatrixA(){
  int num=1;
  for(int i=0;i<30;i++){
    for(int j=0;j<10;j++){
      A[i][j] = num;
      num++;
    }
  }
}
void makeMatrixB(){
  int num=1;
  for(int i=0;i<10;i++){
    for(int j=0;j<50;j++){
      B[i][j] = num;
      num++;
    }
  }
}
void ordinaryMultiplicationWithMatrixC1() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 10; k++)
                C1[i][j] += A[i][k] * B[k][j];
        }
    }
}
void divideMatrixA() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
          subMatrixA11[i][j] = A[i][j];
          subMatrixA12[i][j] = A[i][j+5];
          subMatrixA21[i][j] = A[i+15][j];
          subMatrixA22[i][j] = A[i+15][j+5];
        }
    }
}
void divideMatrixB(){
  for(int i=0;i<5;i++){
    for(int j=0;j<25;j++){
      subMatrixB11[i][j] = B[i][j];
      subMatrixB11[i][j] = B[i][j+25];
      subMatrixB11[i][j] = B[i+5][j];
      subMatrixB11[i][j] = B[i+5][j+25];
    }
  }
}
void makeM1() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++)
            temp1[i][j] = subMatrixA11[i][j] + subMatrixA22[i][j];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 25; j++)
            temp2[i][j] = subMatrixB11[i][j] + subMatrixB22[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M1[i][j] += temp1[i][k] * temp2[k][j];
        }
    }
}
void makeM2() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++)
            temp1[i][j] = subMatrixA21[i][j] + subMatrixA22[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M2[i][j] += temp1[i][k] * subMatrixB11[k][j];
        }
    }
}
void makeM3() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 25; j++)
            temp2[i][j] = subMatrixB12[i][j] - subMatrixB22[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M3[i][j] += subMatrixA11[i][k] * temp2[k][j];
        }
    }
}
void makeM4() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 25; j++)
            temp2[i][j] = subMatrixB21[i][j] - subMatrixB11[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M4[i][j] += subMatrixA22[i][k] * temp2[k][j];
        }
    }
}
void makeM5() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++)
            temp1[i][j] = subMatrixA11[i][j] + subMatrixA12[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M5[i][j] += temp1[i][k] * subMatrixB22[k][j];
        }
    }
}
void makeM6() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++)
            temp1[i][j] = subMatrixA21[i][j] - subMatrixA11[i][j];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 25; j++)
            temp2[i][j] = subMatrixB11[i][j] + subMatrixB12[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M6[i][j] += temp1[i][k] * temp2[k][j];
        }
    }
}
void makeM7() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++)
            temp1[i][j] = subMatrixA12[i][j] - subMatrixA22[i][j];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 25; j++)
            temp2[i][j] = subMatrixB21[i][j] + subMatrixB22[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M7[i][j] += temp1[i][k] * temp2[k][j];
        }
    }
}
void makePartictionOfMatrixC2() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            subMatrixC11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            subMatrixC12[i][j] = M3[i][j] + M5[i][j];
            subMatrixC21[i][j] = M2[i][j] + M4[i][j];
            subMatrixC22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }
}
void mergeMatrixC2() {
    for(int i=0;i<15;i++){
      for(int j=0;j<25;j++){
        C2[i][j]=subMatrixC11[i][j];
        C2[i][j+25]=subMatrixC12[i][j];
        C2[i+15][j]=subMatrixC21[i][j];
        C2[i+15][j+25]=subMatrixC22[i][j];
      }
    }
}
void printMatrixC1(){
  for(int i=0;i<30;i++){
    for(int j=0;j<50;j++){
      printf("%d ",C1[i][j]);
    }
    printf("\n");
  }
}
void printMatrixC2(){
  for(int i=0;i<30;i++){
    for(int j=0;j<50;j++){
      printf("%d ",C2[i][j]);
    }
    printf("\n");
  }
}
int main(void) {
  int ordinaryMultiplicationStart,ordinaryMultiplicationEnd;
  int strassenMultiplicationStart,strassenMultiplicationEnd;
  float time1, time2;
  makeMatrixA();
  makeMatrixB();
  // ordinaryMultiplicationStart = clock();
  // ordinaryMultiplicationWithMatrixC1();
  // // printMatrixC1();
  
  // printf("\n");
  // printf("Time for ordinary multiplication: \n");
  // ordinaryMultiplicationEnd = clock();
  // time1 = (float)(ordinaryMultiplicationEnd - ordinaryMultiplicationStart) / CLOCKS_PER_SEC;
  strassenMultiplicationStart = clock();
  divideMatrixA();
  divideMatrixB();
  makeM1();
  makeM2();
  makeM3();
  makeM4();
  makeM5();
  makeM6();
  makeM7();
  makePartictionOfMatrixC2();
  mergeMatrixC2();
  printMatrixC2();
  // strassenMultiplicationEnd = clock();
  // time2 = (float)(strassenMultiplicationEnd - strassenMultiplicationStart) / CLOCKS_PER_SEC;
  // printf("ordinary multiplication: %.7f \n", time1);
  // printf("Strassen multiplication: %.7f \n", time2);
  return 0;
}
