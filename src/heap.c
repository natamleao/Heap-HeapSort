#include "../include/heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

struct _heap{
    float *_data;
    int _size, _virtualSize;
};

/******************************************************* INTERFACE PUBLICA *******************************************************/

Heap* heapCreate(int size){
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    if(!heap) return NULL;

    heap->_data = calloc(size, sizeof(float));
    if(!heap->_data){
        free(heap);
        return NULL;
    }

    heap->_size = size;
    heap->_virtualSize = size;

    return heap;
}

float* heapGetData(Heap *heap){return heap->_data;}
int heapGetSize(Heap *heap){return heap->_size;}
int heapGetVirtualSize(Heap *heap){return heap->_virtualSize;}

void heapSet(Heap *heap, int index, float value){heap->_data[index] = value;}
void heapSetSize(Heap *heap, int value){heap->_size = value;}

void heapDecrementSize(Heap *heap){heap->_size--;}

void heapifyDown(Heap *heap, int index){
    int son = 2 * index + 1;

    if(son >= heapGetVirtualSize(heap)) return;

    if(son <= heapGetVirtualSize(heap) - 1 && son < heapGetVirtualSize(heap) - 1 && heapGetData(heap)[son] < heapGetData(heap)[son + 1])
        son++;

    if(heapGetData(heap)[index] < heapGetData(heap)[son]){
        heapChangeValues(heap, index, son);

        heapifyDown(heap, son);
    }
}

void heapBuild(Heap *heap){
    for(int i = (heapGetSize(heap) / 2) - 1; i >= 0; i--)
        heapifyDown(heap, i);
}

void heapPrint(Heap *heap){
    printf("[");
    for(int i = 0; i < heapGetSize(heap) - 1; i++)
        printf("%.2f  ", heapGetData(heap)[i]);
    
    printf("%.2f]\n", heapGetData(heap)[heapGetSize(heap) - 1]);
}

void heapChangeValues(Heap *heap, int indexP, int indexS){
    float auxiliaryVariable = heapGetData(heap)[indexP];
    heapSet(heap, indexP, heapGetData(heap)[indexS]);
    heapSet(heap, indexS, auxiliaryVariable);
}

void heapDestroy(Heap *heap){
    if(heap){
        free(heap->_data);
        free(heap);
    }
}

/*********************************************************************************************************************************/