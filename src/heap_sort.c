#include "../include/heap_sort.h"

/******************************************************* INTERFACE PUBLICA *******************************************************/

void heapSort(Heap *heap){
    heapBuild(heap);
    for(int i = heapGetSize(heap); i > 1; i--){
        heapChangeValues(heap, 0, i - 1);
        heapDecrementSize(heap);

        heapifyDown(heap, 0); 
    }
}

void heapSortWrapper(void *h){
    heapSort((Heap*)h);
} 

/*********************************************************************************************************************************/