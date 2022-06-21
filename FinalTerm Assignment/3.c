#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int distance[5];
int visitedCityList[5] = {1, 0, 0, 0, 0};
int pathInformation[5][5]={
  {0,3,0,5,0},{0,0,6,2,0},{0,0,0,0,2},{0,1,4,0,6},{3,0,7,0,0}
  };
int vertexYPath[2];
int vertexZPath[3];

typedef struct VERTEX{
  int previousVisitedCity;
  int distance;
}city;

city cityList[5];

char returnVertexChar(int vertexNumber);
int searchMin(int* visitedCityList, int* distance);
void findByDijkstraAlgorithm();
void addVertexPathRoute(int tempY, int tempZ);
void printRouteAndCost();

int main(){
  int tempZ = 4;
  int tempY = 3;
  findByDijkstraAlgorithm(cityList);
  addVertexPathRoute(tempY, tempZ);
  printRouteAndCost();
  return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void addVertexPathRoute(int tempY, int tempZ){
   for(int i=1;i>=0;i--){
    vertexYPath[i] = tempY;
    tempY = cityList[tempY].previousVisitedCity;
  }
  
  for(int i = 2; i>=0; i--){
    vertexZPath[i] = tempZ;
    tempZ = cityList[tempZ].previousVisitedCity;
  }
 }

void findByDijkstraAlgorithm(){
  int temp;
  for(int i=0; i<5; i++){
    distance[i]=pathInformation[0][i];
    cityList[i].previousVisitedCity=0;
    cityList[i].distance=distance[i];
  }
  while((temp=searchMin(visitedCityList, distance))!=-1){
    visitedCityList[temp]=1;
    for(int i=1; i<5; i++){
      if(pathInformation[temp][i]!=0&&(distance[temp]+pathInformation[temp][i] < distance[i] || distance[i] ==0 )){
        distance[i]=distance[temp]+pathInformation[temp][i];
        cityList[i].previousVisitedCity=temp;
        cityList[i].distance=distance[i];
      }
    }
  }
}

char returnVertexChar(int vertexNumber){
  if(vertexNumber == 0){
    return 's';
  }
  else if(vertexNumber == 1){
    return 't';
  }
  else if(vertexNumber == 2){
    return 'x';
  }
  else if(vertexNumber == 3){
    return 'y';
  }
  else{
    return 'z';
  }
}

void printRouteAndCost(){
  printf("-------------------------------------\n");

  printf("<Vertex Y>\n");
  for(int i=0;i<1;i++){
    int startVertex = returnVertexChar(vertexYPath[i]);
    int endVertex = returnVertexChar(vertexYPath[i+1]);
    printf("%c -> %c / distance : %d\n", startVertex, endVertex, pathInformation[vertexYPath[i]][vertexYPath[i+1]]);
  }
  printf("Total Costs : %d\n", cityList[3].distance);

  printf("\n");

  printf("<Vertex Z>\n");
  for(int i=0;i<2;i++){
    int startVertex = returnVertexChar(vertexZPath[i]);
    int endVertex = returnVertexChar(vertexZPath[i+1]);
    printf("%c -> %c / distance : %d\n", startVertex, endVertex, pathInformation[vertexZPath[i]][vertexZPath[i+1]]);
  }
  printf("Total Costs : %d\n", cityList[4].distance);

  printf("-------------------------------------\n");
}

int searchMin(int* visitedCityList, int* distance){
  int min=9999;
  int j=-1;
  for(int i=1; i<5; i++){
    if(distance[i]!=0 && distance[i]<min && visitedCityList[i]==0){
      min=distance[i];
      j=i;
    }
  }
  if(j==-1){
    return -1;
  } 
  else{
    return j;
  } 
}
