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
 * @param array Ponteiro para o array de floats.
 * @param size Número de elementos válidos no array.
 * @param capacity Capacidade máxima do Heap (>= size).
 * @return Ponteiro para o Heap alocado, ou NULL se falhar.
 */
Heap* heapCreate(float *array, int size, int capacity);

/**
 * @brief Retorna o vetor interno de dados do Heap.
 *
 * @param heap Ponteiro para o Heap.
 * @return Ponteiro para o vetor de floats que representa os dados.
 */
float* heapGetHeap(Heap *heap);

/**
 * @brief Retorna a capacidade máxima do Heap.
 *
 * @param heap Ponteiro para o Heap.
 * @return Número máximo de elementos que o Heap pode armazenar.
 */
int heapGetCapacity(Heap *heap);

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
 * @brief Retorna o valor de um elemento do Heap.
 * 
 * @param heap Ponteiro para o Heap.
 * @param index Índice do elemento.
 * @return Valor do elemento no índice especificado.
 */
float heapGetValue(Heap *heap, int index);

/**
 * @brief Define o valor de um elemento no Heap.
 *
 * @param heap Ponteiro para o Heap.
 * @param index Índice do elemento a ser alterado (0 a size-1).
 * @param value Novo valor a ser colocado nesse índice.
 */
void heapSetHeap(Heap *heap, int index, float value);

/**
 * @brief Ajusta a capacidade máxima do Heap.
 *
 * @param heap Ponteiro para o Heap.
 * @param value Nova capacidade ou incremento da capacidade.
 */
void heapSetCapacity(Heap *heap, int value);

/**
 * @brief Ajusta o tamanho atual do Heap.
 *
 * @param heap Ponteiro para o Heap.
 * @param value Novo tamanho ou incremento do tamanho atual.
 */
void heapSetSize(Heap *heap, int value);

/**
 * @brief Ajusta o tamanho virtual atual do Heap.
 *
 * @param heap Ponteiro para o Heap.
 * @param value Novo valor ou incremento do tamanho virtual.
 */
void heapSetVirtualSize(Heap *heap, int value);

/**
 * @brief Define ou adiciona um valor no Heap.
 * 
 * @param heap Ponteiro para o Heap.
 * @param index Índice do elemento.
 * @param value Valor a ser definido.
 */
void heapSetValue(Heap *heap, int index, float value);

/**
 * @brief Incrementa o tamanho atual do Heap em 1.
 *
 * @param heap Ponteiro para a estrutura Heap.
 */
void heapIncrementSize(Heap *heap);

/**
 * @brief Decrementa o tamanho atual do Heap em 1.
 *
 * @param heap Ponteiro para a estrutura Heap.
 */
void heapDecrementSize(Heap *heap);

/**
 * @brief "Sobe" o elemento na posição index até restaurar a propriedade de Heap.
 * 
 * @param heap Ponteiro para o Heap.
 * @param index Índice do elemento a ser ajustado.
 */
void heapifyUp(Heap *heap, int index);

/**
 * @brief "Desce" o elemento na posição index até restaurar a propriedade de Heap.
 * 
 * @param heap Ponteiro para o Heap.
 * @param index Índice do elemento a ser ajustado.
 */
void heapifyDown(Heap *heap, int index);

/**
 * @brief Extrai (remove e retorna) o maior elemento do Heap.
 * 
 * @param heap Ponteiro para o Heap.
 * @return Maior valor do Heap, ou -1 se estiver vazio.
 */
float heapExtractMax(Heap *heap);

/**
 * @brief Insere uma nova chave no Heap.
 * 
 * @param heap Ponteiro para o Heap.
 * @param key Valor a ser inserido.
 */
void heapInsertKey(Heap *heap, float key);

/**
 * @brief Constrói um Heap válido a partir do vetor já preenchido.
 * 
 * @param heap Ponteiro para o Heap.
 */
void heapBuildFromArray(Heap *heap);

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