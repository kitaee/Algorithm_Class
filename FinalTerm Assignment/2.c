#include <stdio.h>

int graph[8][8] = {};

typedef struct VERTEX{
  int d;
  int pi;
}vertex;

vertex vertexList[8];

int main(void){
  for(int i=0;i<8;i++){
    vertexList[i].d = 0;
    vertexList[i].pi = "NIL";
  }
}
