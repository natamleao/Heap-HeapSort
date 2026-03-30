#include "heapSort.h"

/******************************************************* INTERFACE PUBLICA *******************************************************/

void HeapSort(StructureHeap *heap){
    HeapBuildFromArray(heap);
    for(int i = HeapGetSize(heap); i > 1; i--){
        HeapChangeValues(heap, 0, i - 1);
        HeapSetVirtuaSize(heap, i - 1);

        HeapifyDown(heap, 0);
    }
}

/*********************************************************************************************************************************/