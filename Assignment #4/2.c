#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tempMatrix[501][2];
int minimunCalculation[501][501];
int matrix1[5][3];
int matrix2[3][7];
int matrix3[7][10];
int outputTempMatrix[5][7];
int outputMatrix[5][10];

int calculateMatrix(int row1, int row2, int row3, int row4);
int getMin(int x, int y);
void matrixMultiplication();
void printMatrix();

int main(void){
    srand(time(NULL));
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            matrix1[i][j] = rand()%10+1;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<7;j++){
            matrix2[i][j] = rand()%10+1;
        }
    }
    for(int i=0;i<7;i++){
        for(int j=0;j<10;j++){
            matrix3[i][j] = rand()%10+1;
        }
    }
    matrixMultiplication();
    printMatrix();
}

int calculateMatrix(int row1, int row2, int row3, int row4){
    tempMatrix[0][0] = row1;
    tempMatrix[0][1] = row2;
    tempMatrix[1][0] = row2;
    tempMatrix[1][1] = row3;
    tempMatrix[2][0] = row3;
    tempMatrix[2][1] = row4;
    int matrixCount = 3;    //because there are 4 sequences of dimensions
    int n,m;
    for(int i=0;i<3;i++){
        for(int j=0;j<3-i;j++){
            n = j;
            m = j+i;
            if(n == m){
                minimunCalculation[n][m] = 0;
            }
            else{
                minimunCalculation[n][m] = 987654321;
                for(int k = n; k < m; k++){
                    minimunCalculation[n][m] = getMin(minimunCalculation[n][m],minimunCalculation[n][k] + minimunCalculation[k+1][m] + ( tempMatrix[n][0] * tempMatrix[k][1] * tempMatrix[m][1] ));
                }
            }
        }
    }
    return minimunCalculation[0][2];
}
int getMin(int x, int y){
    if(x < y){
        return x;
    }
    else{
        return y;
    }
}
void matrixMultiplication(){
    int temp;
    for(int i=0;i<5;i++){
        for(int j=0;j<7;j++){
            temp = 0;
            for(int k = 0;k<3;k++){
                temp += (matrix1[i][k]*matrix2[k][j]);
            }
            outputTempMatrix[i][j] = temp;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<10;j++){
            temp = 0;
            for(int k = 0;k<7;k++){
                temp += (outputTempMatrix[i][k]*matrix3[k][j]);
            }
            outputMatrix[i][j] = temp;
        }
    }
}
void printMatrix(){
    for(int i=0;i<5;i++){
        for(int j=0;j<10;j++){
            printf("%d ",outputMatrix[i][j]);
        }
        printf("\n");
    }
}
