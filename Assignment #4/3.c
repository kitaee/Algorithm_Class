#include <stdio.h>

typedef struct ITEM{
    int weight;
    int value;
    int originalIndex;
}item;

item itemArr[6];

void sortByValueDivWeight();
int greedyKnapsack();

int main(void){

    int maximumValue;

    itemArr[0].weight = 6;
    itemArr[0].value = 60;
    itemArr[0].originalIndex = 1;
    itemArr[1].weight = 10;
    itemArr[1].value = 20;
    itemArr[1].originalIndex = 2;
    itemArr[2].weight = 3;
    itemArr[2].value = 12;
    itemArr[2].originalIndex = 3;
    itemArr[3].weight = 5;
    itemArr[3].value = 80;
    itemArr[3].originalIndex = 4;
    itemArr[4].weight = 1;           
    itemArr[4].value = 30;
    itemArr[4].originalIndex = 5;
    itemArr[5].weight = 3;
    itemArr[5].value = 60;
    itemArr[5].originalIndex = 6;

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
    int currentWeight = 0;
    int maximumValue = 0;
    int stopIndex;
    int lastFraction;
    for(int i=0;i<6;i++){
        maximumValue += itemArr[i].value;
        currentWeight += itemArr[i].weight;
        printf("Item Index : %d, Fraction Number = 1\n",itemArr[i].originalIndex);
        if(currentWeight + itemArr[i+1].weight>16){
            stopIndex = i+1;
            break;
        }
    }
    lastFraction = itemArr[stopIndex].value / itemArr[stopIndex].weight;
    maximumValue += (lastFraction*(capacity-currentWeight));
    printf("Item Index : %d, Fraction Nubmer = %f\n",itemArr[stopIndex].originalIndex,(double)1/3);
    return maximumValue;
}
