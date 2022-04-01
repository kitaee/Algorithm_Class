#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *str);

int main(void){
  char *str;
  printf("문자열을 입력하세요 : ");
  scanf("%s",str);
  if(isPalindrome(str)){
    printf("%s is palindrome\n",str);
  }
  else{
    printf("%s is not palindrome\n",str);
  }
  return 0;
}

bool isPalindrome(char *str){
  int len = strlen(str);
  for(int i=0;i<len/2;i++){
    if(str[i]!=str[len-i-1]){
      return false;
    }
  }
  return true;
}
