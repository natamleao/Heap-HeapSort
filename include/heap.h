/******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef HEAP_H
#define HEAP_H

// Estrutura de Heap Máximo
typedef struct _heap Heap;

/**
 * @brief Cria a estrutura de um Heap a partir de um array.
 *
 * Copia os elementos do array passado para o Heap, mas sem construir
 * a propriedade de Heap. Ajusta size, virtualSize e capacidade.
 *
 * @param size Número de elementos válidos no array.
 * @return Ponteiro para o Heap alocado, ou NULL se falhar.
 */
Heap* heapCreate(int size);

/**
 * @brief Retorna o vetor interno de dados do Heap.
 *
 * @param heap Ponteiro para o Heap.
 * @return Ponteiro para o vetor de floats que representa os dados.
 */
float* heapGetData(Heap *heap);

/**
 * @brief Retorna o tamanho atual do Heap.
 *
 * @param heap Ponteiro para o Heap.
 * @return Número de elementos válidos atualmente no Heap.
 */
int heapGetSize(Heap *heap);

/**
 * @brief Retorna o tamanho virtual atual do Heap.
 *
 * @param heap Ponteiro para o Heap.
 * @return Número de elementos válidos considerados no Heap.
 */
int heapGetVirtualSize(Heap *heap);

/**
 * @brief Define ou adiciona um valor no Heap.
 * 
 * @param heap Ponteiro para o Heap.
 * @param index Índice do elemento.
 * @param value Valor a ser definido.
 */
void heapSet(Heap *heap, int index, float value);

/**
 * @brief Ajusta o tamanho atual do Heap.
 *
 * @param heap Ponteiro para o Heap.
 * @param value Novo tamanho ou incremento do tamanho atual.
 */
void heapSetSize(Heap *heap, int value);

/**
 * @brief Decrementa o tamanho atual do Heap em 1.
 *
 * @param heap Ponteiro para a estrutura Heap.
 */
void heapDecrementSize(Heap *heap);

/**
 * @brief "Desce" o elemento na posição index até restaurar a propriedade de Heap.
 * 
 * @param heap Ponteiro para o Heap.
 * @param index Índice do elemento a ser ajustado.
 */
void heapifyDown(Heap *heap, int index);

/**
 * @brief Constrói um Heap válido a partir do vetor já preenchido.
 * 
 * @param heap Ponteiro para o Heap.
 */
void heapBuild(Heap *heap);

/**
 * @brief Imprime todos os elementos do Heap no console.
 *
 * @param heap Ponteiro para o Heap.
 *
 * @note Os elementos são impressos na ordem interna do vetor,
 *       não necessariamente em ordem decrescente.
 */
void heapPrint(Heap *heap);

/**
 * @brief Troca os valores de dois elementos no Heap.
 *
 * @param heap Ponteiro para o Heap.
 * @param indexP Índice do primeiro elemento.
 * @param indexS Índice do segundo elemento.
 */
void heapChangeValues(Heap *heap, int indexP, int indexS);

/**
 * @brief Libera toda a memória usada pelo Heap.
 *
 * Desaloca o vetor interno de dados e a própria estrutura do Heap.
 *
 * @param heap Ponteiro para o Heap a ser destruído.
 */
void heapDestroy(Heap *heap);

#endif

/*********************************************************************************************************************************/