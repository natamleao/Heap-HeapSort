#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

struct _structureHeap{
    float *_data;
    int _size;
    int _virtualSize;
    int _capacity;
};

/******************************************************* INTERFACE PUBLICA *******************************************************/

StructureHeap* HeapCreateStructureHeap(float *array, int size, int capacity){
    if(capacity < size){
        printf("Erro: capacidade menor que o tamanho do array!\n");
        return NULL;
    }

    StructureHeap *heap = (StructureHeap*)malloc(sizeof(StructureHeap));
    if(!heap) return NULL;

    heap->_data = calloc(capacity, sizeof(float));
    if(!heap->_data){
        free(heap);
        return NULL;
    }

    memcpy(heap->_data, array, size * sizeof(float));
    heap->_size = size;
    heap->_virtualSize = size;
    heap->_capacity = capacity;

    return heap;
}

float* HeapGetHeap(StructureHeap *heap){return heap->_data;}
int HeapGetCapacity(StructureHeap *heap){return heap->_capacity;}
int HeapGetSize(StructureHeap *heap){return heap->_size;}
int HeapGetVirtuaSize(StructureHeap *heap){return heap->_virtualSize;}

void HeapSetHeap(StructureHeap *heap, int index, float value){heap->_data[index] = value;}
void HeapSetCapacity(StructureHeap *heap, int value){heap->_capacity = value;}
void HeapSetSize(StructureHeap *heap, int value){heap->_size = value;}
void HeapSetVirtuaSize(StructureHeap *heap, int value){heap->_virtualSize = value;}

void HeapChangeCapacity(StructureHeap *heap, int delta){HeapSetCapacity(heap, HeapGetCapacity(heap) + delta);}
void HeapChangeSize(StructureHeap *heap, int delta){HeapSetSize(heap, HeapGetSize(heap) + delta);}

void HeapifyUp(StructureHeap *heap, int index){
    int father = (index - 1) / 2;

    if(index == 0) return;

    if(HeapGetHeap(heap)[index] > HeapGetHeap(heap)[father]){
        HeapChangeValues(heap, index, father);

        HeapifyUp(heap, father);
    }
}

void HeapifyDown(StructureHeap *heap, int index){
    int son = 2 * index + 1;

    if(son >= HeapGetVirtuaSize(heap)) return;

    if(son <= HeapGetVirtuaSize(heap) - 1 && son < HeapGetVirtuaSize(heap) - 1 && HeapGetHeap(heap)[son] < HeapGetHeap(heap)[son + 1])
        son++;

    if(HeapGetHeap(heap)[index] < HeapGetHeap(heap)[son]){
        HeapChangeValues(heap, index, son);

        HeapifyDown(heap, son);
    }
}

float HeapExtractMax(StructureHeap *heap){
    if(HeapGetSize(heap) >= 1){
        float maxValue = HeapGetHeap(heap)[0];
        HeapSetHeap(heap, 0, HeapGetHeap(heap)[HeapGetSize(heap) - 1]);
        HeapSetHeap(heap, HeapGetSize(heap) - 1, 0.0);
        HeapChangeSize(heap, -1);
        
        HeapifyDown(heap, 0);

        return maxValue;
    } 

    else{
        printf("Underflow!\n");
        return -1;
    }
}

void HeapInsertKey(StructureHeap *heap, float key){
    if(HeapGetSize(heap) < HeapGetCapacity(heap)){
        HeapSetHeap(heap, HeapGetSize(heap), key);

        HeapifyUp(heap, HeapGetSize(heap));
        HeapChangeSize(heap, 1);
    }

    else
        printf("Overflow!\n");
}

void HeapBuildFromArray(StructureHeap *heap){
    for(int i = (HeapGetSize(heap) / 2) - 1; i >= 0; i--)
        HeapifyDown(heap, i);
}

void HeapPrint(StructureHeap *heap){
    printf("[");
    for(int i = 0; i < HeapGetSize(heap) - 1; i++)
        printf("%.2f  ", HeapGetHeap(heap)[i]);
    
    printf("%.2f]\n", HeapGetHeap(heap)[HeapGetSize(heap) - 1]);
}

void HeapChangeValues(StructureHeap *heap, int indexP, int indexS){
    float auxiliaryVariable = HeapGetHeap(heap)[indexP];
    HeapSetHeap(heap, indexP, HeapGetHeap(heap)[indexS]);
    HeapSetHeap(heap, indexS, auxiliaryVariable);
}

void HeapDestroy(StructureHeap *heap){
    if(heap){
        free(heap->_data);
        free(heap);
    }
}

/*********************************************************************************************************************************/