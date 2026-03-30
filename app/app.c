#include "../include/heap.h"
#include "../include/heapSort.h"
#include "../include/executionTime.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define CAPACITY 1100000
#define SIZE 100000

int main(){
    float *array6 = calloc(CAPACITY, sizeof(float));
    if(!array6){
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        float min = -5000000000000.0f;
        float max =  5000000000000.0f;
        array6[i] = min + ((float)rand() / RAND_MAX) * (max - min);
    }

    Heap *heap = heapCreate(array6, SIZE, CAPACITY);

    //printf("Estrutura criada!\n");
    //heapPrint(heap);

    //heapBuildFromArray(heap);
//
    //printf("Heap construída!\n");
    //heapPrint(heap);
//
    //heapInsertKey(heap, 100);
//
    //printf("Após a inserção!\n");
    //heapPrint(heap);
//
    //heapExtractMax(heap);
//
    //printf("Após a remoção!\n");
    //heapPrint(heap);
//
    //heapInsertKey(heap, -10);
//
    //printf("Após a inserção!\n");
    //heapPrint(heap);

    //heapSort(heap);
    double executionTime = executionTimeCalculate(heapSortWrapper, heap);

    //printf("Após a ordenação!\n");
    //HeapPrint(heap);

    executionTimePrint(executionTime);

    heapDestroy(heap);
    return 0;
}