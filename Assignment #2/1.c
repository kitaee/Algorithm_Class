#include <stdio.h>

int powerOfN(int k);

int main(void){
  int n,result;
  int k=1;
  printf("Please Enter n : ");
  scanf("%d",&n);
  while(1){
    if(powerOfN(k)>n){
      break;
    }
    else{
      k++;
    }
  }
  printf("The Largest Positive Integer k satisfying the equation is %d\n",k-1);
  return 0;
}

int powerOfN(int k){
  if(k==0){
    return 1;
  }
  else if(k==1){
    return 2;
  }
  else{
    return 2*powerOfN(k-1);
  }
}
