#include <stdio.h>

int cutRod(int n);
int getMaxValue(int a, int b);

int rodPrice[11] = {0,1,4,5,7,9,11,13,13,15,16};
int maxPrice[11];

int main(void){
  printf("Maximum Prices : %d\n", cutRod(10));
  return 0;
}

int cutRod(int n){
  int maxValue = 0;
  int temp;

  if(n==0){
    return 0;
  }

  if(maxPrice[n]!=0){
    return maxPrice[n];
  }

  for(int i=1;i<=n;i++){  
    maxValue = getMaxValue(maxValue, rodPrice[i] + cutRod(n-i));
    
  }

  maxPrice[n] = maxValue;

  for(int i=1;i<=10;i++){
    printf("%d ", maxPrice[i]);
  }

  printf("\n");
  return maxValue;
}

int getMaxValue(int a, int b){
  if(a>=b){
    return a;
  }
  else{
    return b;
  }
}
