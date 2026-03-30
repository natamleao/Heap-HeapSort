/******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "heap.h"

/**
 * @brief Chama a função `heapSort` incapsulada.
 * 
 * @param h Ponteiro para o heap.
 */
void heapSortWrapper(void *h);

/**
 * @brief Algoritmo de ordenação Heap Sort, ordena um vetor utilizando a estrutura de uma Heap.
 * 
 * @param heap Ponteiro para o heap. 
 */
void heapSort(Heap *heap);

#endif

/*********************************************************************************************************************************/