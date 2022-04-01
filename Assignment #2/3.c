#include <stdio.h>

int main(void){
  int x=3;
  int y=2;
  int z=5;
  printf("%d\n",((x>y)?x:y)>z?((y>x)?x:y):z);
  return 0;
}
