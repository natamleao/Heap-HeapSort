#include "../include/heap.h"
#include "../include/heap_sort.h"
#include "../include/execution_time.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define SIZE 10000000

int main(){

    Heap *heap = heapCreate(SIZE);

    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        float min = -1e6f;
        float max =  1e6f;
        heapSet(heap, i, min + ((float)rand() / RAND_MAX) * (max - min));
    }

    //heapPrint(heap);

    double executionTime = executionTimeCalculate(heapSortWrapper, heap);

    executionTimePrint(executionTime);

    heapDestroy(heap);
    return 0;
}
