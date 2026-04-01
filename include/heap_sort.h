/******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "heap.h"

/**
 * @brief Ordena um vetor utilizando a estrutura de Heap (Heap Sort).
 * 
 * @param heap Ponteiro para a estrutura `Heap` a ser ordenada.
 *
 * @note O algoritmo transforma a Heap em um vetor ordenado em ordem crescente.
 */
void heapSort(Heap *heap);

/**
 * @brief Wrapper para permitir chamar `heapSort` através de ponteiros genéricos.
 *
 * @param h Ponteiro para a estrutura `Heap` (passado como `void*` para compatibilidade).
 *
 * @note Usado principalmente com funções como `executionTimeCalculate` que aceitam `void*`.
 */
void heapSortWrapper(void *h);

#endif

/*********************************************************************************************************************************/