#include <stdio.h>

int memoization[10];

int fibonacci(int num);

int main(void){

    int fibonacci5 = fibonacci(5);
    int fibonacci10 = fibonacci(10);

    printf("when n = 5 : %d\n",fibonacci5);
    printf("when n = 10 : %d\n",fibonacci10);
    return 0;
}

int fibonacci(int num){
    if(num<=1){
        return num;
    }
    else{
        if(memoization[num]>=1){
            return memoization[num];
        }
        else{
            memoization[num] = fibonacci(num-1) + fibonacci(num-2);
            return memoization[num];
        }
    }
}
