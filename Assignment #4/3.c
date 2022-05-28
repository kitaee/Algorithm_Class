#include <stdio.h>

typedef struct ITEM{
    int weight;
    int value;
}item;

item itemArr[6];

void sortByValueDivWeight();
int greedyKnapsack();

int main(void){

    int maximumValue;

    itemArr[0].weight = 6;
    itemArr[0].value = 60;
    itemArr[1].weight = 10;
    itemArr[1].value = 20;
    itemArr[2].weight = 3;
    itemArr[2].value = 12;
    itemArr[3].weight = 5;
    itemArr[3].value = 80;
    itemArr[4].weight = 1;           
    itemArr[4].value = 30;
    itemArr[5].weight = 3;
    itemArr[5].value = 60;

    sortByValueDivWeight();
    
    maximumValue = greedyKnapsack();

    printf("Maximum Value = %d\n",maximumValue);

    return 0;
}

void sortByValueDivWeight(){
    item temp;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if((itemArr[i].value/itemArr[i].weight) < (itemArr[j].value/itemArr[j].weight)){
                temp = itemArr[i];
                itemArr[i] = itemArr[j];
                itemArr[j] = temp;
            }
        }
    }
}
int greedyKnapsack(){
    int capacity = 16;
    int maximumValue = 0;
    int stopIndex;
    int lastFraction;
    for(int i=0;i<6;i++){
        maximumValue += itemArr[i].value;
        capacity -= itemArr[i].weight;
        if(capacity-itemArr[i+1].weight<0){
            stopIndex = i+1;
            break;
        }
        printf("Item Indices")
    }
    lastFraction = itemArr[stopIndex].value / itemArr[stopIndex].weight;
    maximumValue += (lastFraction*capacity);
    return maximumValue;
}
