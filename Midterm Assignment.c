#include <stdio.h>
#include <time.h>

int arr1[1000];
int arr2[5000];
int arr3[10000];
int data[10000];  // mergeSort를 위한 배열
double executionTime[18];  //bubble, insertion, merge, quick, radix, bucket -> 1000/5000/10000 순서대로 저장

int temp;

void resetArr1(){
  for(int i=1000;i>0;i--){
    arr1[1000-i]=i;
  }
}
void resetArr2(){
  for(int i=5000;i>0;i--){
    arr2[5000-i]=i;
  }
}
void resetArr3(){
  for(int i=10000;i>0;i--){
    arr3[10000-i]=i;
  }
}
void resetArr(){
  resetArr1();
  resetArr2();
  resetArr3();
}
void sortTest1(){
  for(int i=0;i<10;i++){
    printf("%d ",arr1[i]);
  }
}

void bubbleSort(int arr[], int length){
  for(int i=0;i<length-1;i++){
    for(int j=0;j<length-i;j++){
      if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
}
void insertionSort(int arr[], int length){
  int target;
  for(int i=1;i<length;i++){
    target = arr[i];
    for(int j=i-1;j>=0;j--){
      if(arr[j]<target){
        break;
      }
      else{
        arr[j+1]=arr[j];
        arr[j]=target;
      }
    }
  }
}
void merge(int arr[], int m, int middle, int n){
  int i = m;
  int j = middle+1;
  int k = m;
  while(i<=middle && j<=n){
    if(arr[i]<=arr[j]){
      data[k]=arr[i];
      i++;
    }
    else{
      data[k]=arr[j];
      j++;
    }
    k++;
  }
  if(i>middle){  // 왼쪽 배열이 먼저 끝났을 때
    for(int t=j;t<=n;t++){
      data[k]=arr[t];
      k++;
    }  
  }
  else{  // 오른쪽 배열이 먼저 끝났을 때
    for(int t=i;t<=middle;t++){
      data[k]=arr[t];
      k++;
    }
  }
  // 임시 생성된 배열을 원래의 배열로 넣어주기
  for(int t=m;t<=n;t++){
    arr[t]=data[t];
  }
}
void mergeSort(int arr[], int start, int end){
  if(start<end){
    int middle = (start+end)/2;
    mergeSort(arr, start, middle);  // 왼쪽 배열 나누기
    mergeSort(arr, middle+1, end);  // 오른쪽 배열 나누기
    merge(arr,start,middle,end);
  }
}
void printResultTable(){
  printf("\n");
  printf("\t");
  printf("BubbleSort\t");
  printf("insertionSort\t");
  printf("mergeSort\t");
  printf("QuickSort\t");
  printf("Radix Sort\t");
  printf("Bucket Sort\t");
  printf("\n");
  printf("1000\t");
  printf("%lfms\t",executionTime[0]);
  printf("%lfms\t",executionTime[3]);
  printf("%lfms\t",executionTime[6]);
  printf("%lfms\t",executionTime[9]);
  printf("%lfms\t",executionTime[12]);
  printf("%lfms\t",executionTime[15]);
  printf("\n");
  printf("5000\t");
  printf("%lfms\t",executionTime[1]);
  printf("%lfms\t",executionTime[4]);
  printf("%lfms\t",executionTime[7]);
  printf("%lfms\t",executionTime[10]);
  printf("%lfms\t",executionTime[13]);
  printf("%lfms\t",executionTime[16]);
  printf("\n");
  printf("10000\t");
  printf("%lfms\t",executionTime[2]);
  printf("%lfms\t",executionTime[5]);
  printf("%lfms\t",executionTime[8]);
  printf("%lfms\t",executionTime[11]);
  printf("%lfms\t",executionTime[14]);
  printf("%lfms\t",executionTime[17]);
}
void quickSort(int arr[], int startPoint, int endPoint) {
      int leftIndex = startPoint, rightIndex = endPoint;
      int pivot = arr[(startPoint + endPoint) / 2]; 
      do
      {
        while (arr[leftIndex] < pivot)
            leftIndex++;
        while (arr[rightIndex] > pivot)
            rightIndex--;
        if (leftIndex<= rightIndex)  
        {
            temp = arr[leftIndex];
            arr[leftIndex] = arr[rightIndex];
            arr[rightIndex] = temp;
            leftIndex++;
            rightIndex--;
        }
      } while (leftIndex<= rightIndex);
 
    if (startPoint < rightIndex)
        quickSort(arr, startPoint, rightIndex);
 
    if (leftIndex < endPoint)
        quickSort(arr, leftIndex, endPoint); 
}

int main(void){
  
  double start,end;
  
  resetArr();
  printf("<Bubble Sort>\n");
  printf("1. Before : ");
  sortTest1();
  start = (double)clock() / CLOCKS_PER_SEC;
  bubbleSort(arr1,1000);
  end = (double)clock() / CLOCKS_PER_SEC;
  executionTime[0] = end-start;
  printf("<---->  After : ");
  sortTest1();
  start = (double)clock() / CLOCKS_PER_SEC;
  bubbleSort(arr2,5000);
  end = (double)clock() / CLOCKS_PER_SEC;
  executionTime[1] = end-start;
  start = (double)clock() / CLOCKS_PER_SEC;
  bubbleSort(arr3,10000);
  end = (double)clock() / CLOCKS_PER_SEC;
  executionTime[2] = end-start;
  
  printf("\n");
  resetArr();
  printf("<Insertion Sort>\n");
  printf("2. Before : ");
  sortTest1();
  start = (double)clock() / CLOCKS_PER_SEC;
  insertionSort(arr1,1000);
  end = (double)clock() / CLOCKS_PER_SEC;
  executionTime[3] = end-start;
  start = (double)clock() / CLOCKS_PER_SEC;
  insertionSort(arr2,5000);
  end = (double)clock() / CLOCKS_PER_SEC;
  start = (double)clock() / CLOCKS_PER_SEC;
  insertionSort(arr3,10000);
  end = (double)clock() / CLOCKS_PER_SEC;
  executionTime[5] = end-start;
  printf("<---->  After : ");
  sortTest1();
  printf("\n");

  resetArr();
  printf("<Merge Sort>\n");
  printf("3. Before : ");
  sortTest1();
  start = (double)clock() / CLOCKS_PER_SEC;
  mergeSort(arr1,0,1000);
  end = (double)clock() / CLOCKS_PER_SEC;
  executionTime[6] = end-start;
  start = (double)clock() / CLOCKS_PER_SEC;
  mergeSort(arr2,0,5000);
  end = (double)clock() / CLOCKS_PER_SEC;
  executionTime[7] = end-start;
  start = (double)clock() / CLOCKS_PER_SEC;
  mergeSort(arr3,0,10000);
  end = (double)clock() / CLOCKS_PER_SEC;
  executionTime[8] = end-start;
  printf("<---->  After : ");
  sortTest1();
  printf("\n");

  resetArr();
  printf("<Quick Sort>\n");
  printf("4. Before : ");
  sortTest1();
  start = (double)clock() / CLOCKS_PER_SEC;
  quickSort(arr1,0,1000-1);
  end = (double)clock() / CLOCKS_PER_SEC;
  executionTime[9] = end-start;
  start = (double)clock() / CLOCKS_PER_SEC;
  quickSort(arr2,0,5000-1);
  end = (double)clock() / CLOCKS_PER_SEC;
  executionTime[10] = end-start;
  start = (double)clock() / CLOCKS_PER_SEC;
  quickSort(arr3,0,10000-1);
  end = (double)clock() / CLOCKS_PER_SEC;
  executionTime[11] = end-start;
  printf("<---->  After : ");
  sortTest1();
  printf("\n");

  resetArr();
  printf("<Radix Sort>\n");
  printf("5. Before : ");
  sortTest1();

  printResultTable();
  
  return 0;
}
