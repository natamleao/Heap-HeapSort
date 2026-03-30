#include "heap.h"
#include "heapSort.h"
#include "calculateTime.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    float *array6 = calloc(1000000000, sizeof(float));
    if(!array6){
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    srand(time(NULL));
    for(int i = 0; i < 10000000; i++){
        float min = -5000000000000.0f;
        float max =  5000000000000.0f;
        array6[i] = min + ((float)rand() / RAND_MAX) * (max - min);
    }

    StructureHeap *heap = HeapCreateStructureHeap(array6, 10000000, 100000000);

    //printf("Estrutura criada!\n");
    //HeapPrint(heap);

    //HeapBuildFromArray(heap);
//
    //printf("Heap construída!\n");
    //HeapPrint(heap);
//
    //HeapInsertKey(heap, 100);
//
    //printf("Após a inserção!\n");
    //HeapPrint(heap);
//
    //HeapExtractMax(heap);
//
    //printf("Após a remoção!\n");
    //HeapPrint(heap);
//
    //HeapInsertKey(heap, -10);
//
    //printf("Após a inserção!\n");
    //HeapPrint(heap);

    //HeapSort(heap);
    double executionTime = calculateTime(HeapSort, heap);

    //printf("Após a ordenação!\n");
    //HeapPrint(heap);

    calculateTimePrintTime(executionTime);

    HeapDestroy(heap);
    return 0;
}