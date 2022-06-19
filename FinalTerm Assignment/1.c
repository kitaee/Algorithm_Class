#include <stdio.h>
#include <stdlib.h>

int divideRod(int n);
int getMaxValue(int a, int b);

int rodPrice[11] = { 0,1,4,5,7,9,11,13,13,15,16 };
int memorizationInformation[11];
int cutInformation[11]={0};

int divideRod(int length) {
    int maxValue = 0;

    if (memorizationInformation[length] != 0) {
        return memorizationInformation[length];
    }

    for (int i = 1; i <= length; i++) {
      if(maxValue<rodPrice[i]+divideRod(length-i)){
        maxValue=rodPrice[i]+divideRod(length-i);
        if(i!=1){
          cutInformation[i]++;
        }
        else{
          continue;
        }
      }
    }
    memorizationInformation[length] = maxValue;
    return maxValue;
}

int getMaxValue(int a, int b) {
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

int main(void) {
  printf("Maximum Prices : %d\n", divideRod(10));
  for(int i=1;i<=10;i++){
    printf("%d의 길이로 %d번 막대기를 잘랐습니다.\n", i, cutInformation[i]);
  }
  return 0;
}
