#include "../include/heapSort.h"

/******************************************************* INTERFACE PUBLICA *******************************************************/

void heapSort(Heap *heap){
    heapBuildFromArray(heap);
    for(int i = heapGetSize(heap); i > 1; i--){
        heapChangeValues(heap, 0, i - 1);
        heapSetVirtuaSize(heap, i - 1);

        heapifyDown(heap, 0);
    }
}

/*********************************************************************************************************************************/