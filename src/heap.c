#include "../include/heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

struct _heap{
    float *_data;
    int _size;
    int _virtualSize;
    int _capacity;
};

/******************************************************* INTERFACE PUBLICA *******************************************************/

Heap* heapCreate(float *array, int size, int capacity){
    if(capacity < size){
        printf("Erro: capacidade menor que o tamanho do array!\n");
        return NULL;
    }

    Heap *heap = (Heap*)malloc(sizeof(Heap));
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

float* heapGetheap(Heap *heap){return heap->_data;}
int heapGetCapacity(Heap *heap){return heap->_capacity;}
int heapGetSize(Heap *heap){return heap->_size;}
int heapGetVirtuaSize(Heap *heap){return heap->_virtualSize;}

void heapSetheap(Heap *heap, int index, float value){heap->_data[index] = value;}
void heapSetCapacity(Heap *heap, int value){heap->_capacity = value;}
void heapSetSize(Heap *heap, int value){heap->_size = value;}
void heapSetVirtuaSize(Heap *heap, int value){heap->_virtualSize = value;}

void heapChangeCapacity(Heap *heap, int delta){heapSetCapacity(heap, heapGetCapacity(heap) + delta);}
void heapChangeSize(Heap *heap, int delta){heapSetSize(heap, heapGetSize(heap) + delta);}

void heapifyUp(Heap *heap, int index){
    int father = (index - 1) / 2;

    if(index == 0) return;

    if(heapGetheap(heap)[index] > heapGetheap(heap)[father]){
        heapChangeValues(heap, index, father);

        heapifyUp(heap, father);
    }
}

void heapifyDown(Heap *heap, int index){
    int son = 2 * index + 1;

    if(son >= heapGetVirtuaSize(heap)) return;

    if(son <= heapGetVirtuaSize(heap) - 1 && son < heapGetVirtuaSize(heap) - 1 && heapGetheap(heap)[son] < heapGetheap(heap)[son + 1])
        son++;

    if(heapGetheap(heap)[index] < heapGetheap(heap)[son]){
        heapChangeValues(heap, index, son);

        heapifyDown(heap, son);
    }
}

float heapExtractMax(Heap *heap){
    if(heapGetSize(heap) >= 1){
        float maxValue = heapGetheap(heap)[0];
        heapSetheap(heap, 0, heapGetheap(heap)[heapGetSize(heap) - 1]);
        heapSetheap(heap, heapGetSize(heap) - 1, 0.0);
        heapChangeSize(heap, -1);
        
        heapifyDown(heap, 0);

        return maxValue;
    } 

    else{
        printf("Underflow!\n");
        return -1;
    }
}

void heapInsertKey(Heap *heap, float key){
    if(heapGetSize(heap) < heapGetCapacity(heap)){
        heapSetheap(heap, heapGetSize(heap), key);

        heapifyUp(heap, heapGetSize(heap));
        heapChangeSize(heap, 1);
    }

    else
        printf("Overflow!\n");
}

void heapBuildFromArray(Heap *heap){
    for(int i = (heapGetSize(heap) / 2) - 1; i >= 0; i--)
        heapifyDown(heap, i);
}

void heapPrint(Heap *heap){
    printf("[");
    for(int i = 0; i < heapGetSize(heap) - 1; i++)
        printf("%.2f  ", heapGetheap(heap)[i]);
    
    printf("%.2f]\n", heapGetheap(heap)[heapGetSize(heap) - 1]);
}

void heapChangeValues(Heap *heap, int indexP, int indexS){
    float auxiliaryVariable = heapGetheap(heap)[indexP];
    heapSetheap(heap, indexP, heapGetheap(heap)[indexS]);
    heapSetheap(heap, indexS, auxiliaryVariable);
}

void heapDestroy(Heap *heap){
    if(heap){
        free(heap->_data);
        free(heap);
    }
}

/*********************************************************************************************************************************/