#include <stdio.h>

#define SIZE 5

typedef struct {
	int upcity;
	int distance;
}c;

int pathInformation[][SIZE] = {
    {0,3,5,0,0}, {0,0,2,6,0}, {0,1,0,4,0}, {0,0,0,0,2}, {3,0,0,7,0}
  };

int vertexYPath[2];
int vertexZPath[4];



void dijkstraAlgorithm(c* city, int pathInformation[][SIZE], int* distance);
int min_find(int* footstep, int* distance);
char returnVertexChar(int vertexNumber);

int main(void){
	   
	/* 도시 정보 */
	c city[SIZE];
	
	/* 0->다른 도시 간 거리 정보 */
	int distance[SIZE] = { 0 };		
	
	/* 최단거리 찾기 */
	dijkstraAlgorithm(city, pathInformation, distance);	

  int tempZ = 4;
  int tempY = 2;

  for(int i=1;i>=0;i--){
    vertexYPath[i] = tempY;
    tempY = city[tempY].upcity;
  }
  
  for(int i = 3; i>=0; i--){
    vertexZPath[i] = tempZ;
    tempZ = city[tempZ].upcity;
  }

  printf("-------------------------------------\n");

  printf("<Vertex Y>\n");
  for(int i=0;i<1;i++){
    int startVertex = returnVertexChar(vertexYPath[i]);
    int endVertex = returnVertexChar(vertexYPath[i+1]);
    printf("%c -> %c / distance : %d\n", startVertex, endVertex, pathInformation[vertexYPath[i]][vertexYPath[i+1]]);
  }
  printf("Total Costs : %d\n", city[2].distance);

  printf("\n");

  printf("<Vertex Z>\n");
  for(int i=0;i<3;i++){
    int startVertex = returnVertexChar(vertexZPath[i]);
    int endVertex = returnVertexChar(vertexZPath[i+1]);
    printf("%c -> %c / distance : %d\n", startVertex, endVertex, pathInformation[vertexZPath[i]][vertexZPath[i+1]]);
  }
  printf("Total Costs : %d\n", city[4].distance);

  printf("-------------------------------------\n");
}

void dijkstraAlgorithm(c* city, int pathInformation[][SIZE], int* distance)
{
	int footstep[SIZE] = { 1, 0 };  // 방문완료한 도시 (0번 도시는 방문처리)
	for (int i = 0; i < SIZE; i++)  // 첫 배열 복사 (0에서 연결된 도시 정보)
	{
		distance[i] = pathInformation[0][i];
		city[i].upcity = 0;
		city[i].distance = distance[i];
	}

		
	/* 도시를 다 방문할 때까지 반복문 수행 */
	int i;
	while ((i = min_find(footstep, distance)) != -1)
	{
		footstep[i] = 1;  // 방문처리
		for (int j = 1; j < SIZE; j++)
		{
			/* 새로운 길이 현재 저장된 값보다 더 작거나 0인 경우 갱신 */
			if (pathInformation[i][j] != 0 && (distance[i] + pathInformation[i][j] < distance[j] || distance[j] == 0))
			{
				distance[j] = distance[i] + pathInformation[i][j];
				city[j].upcity = i;
				city[j].distance = distance[j];
			}
		}
	}
}

int min_find(int* footstep, int* distance)
{
	int min = 999999;
	int j = -1;
	for (int i = 1; i < SIZE; i++)
		if (distance[i] != 0 && distance[i] < min && footstep[i] == 0)
		{
			min = distance[i];
			j = i;
		}
	if (j == -1)  // 모두 방문했을 경우
		return -1;
	else  // 방문할 도시가 남은 경우
		return j;
}

char returnVertexChar(int vertexNumber){
  if(vertexNumber == 0){
    return 's';
  }
  else if(vertexNumber == 1){
    return 't';
  }
  else if(vertexNumber == 2){
    return 'y';
  }
  else if(vertexNumber == 3){
    return 'x';
  }
  else{
    return 'z';
  }
}
