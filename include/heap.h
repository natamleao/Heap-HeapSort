/******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef HEAP_H
#define HEAP_H

// Estrutura de Heap Máximo
typedef struct _structureHeap StructureHeap;

/**
 * @brief Cria a estrutura de um heap a partir de um array qualquer.
 *
 * Copia os elementos do array passado para o array da estrutura,
 * mas sem transformá-la em um heap, ajusta size, vituralSize e capacidade.
 *
 * @param array Ponteiro para o array de floats.
 * @param size Quantidade de elementos válidos no array.
 * @param capacity Capacidade máxima que o heap deve ter (>= array_size).
 * @return Ponteiro para o heap alocado, ou NULL se falhar.
 */
StructureHeap* HeapCreateStructureHeap(float *array, int size, int capacity);

/**
 * @brief Retorna o vetor interno de dados do heap.
 *
 * Permite acesso direto ao array que armazena os elementos do heap.
 *
 * @param heap Ponteiro para a estrutura do heap.
 * @return Ponteiro para o vetor de floats que representa os dados.
 */
float* HeapGetHeap(StructureHeap *heap);

/**
 * @brief Retorna a capacidade máxima do heap.
 *
 * Informa quantos elementos o heap pode armazenar antes de ocorrer overflow.
 *
 * @param heap Ponteiro para a estrutura do heap.
 * @return Capacidade máxima do heap.
 */
int HeapGetCapacity(StructureHeap *heap);

/**
 * @brief Retorna o tamanho atual do heap.
 *
 * Indica quantos elementos válidos estão armazenados no heap no momento.
 *
 * @param heap Ponteiro para a estrutura do heap.
 * @return Número de elementos atualmente no heap.
 */
int HeapGetSize(StructureHeap *heap);

/**
 * @brief Retorna o tamanho atual virtual do heap.
 *
 * Indica quantos elementos válidos estão armazenados no heap no momento.
 *
 * @param heap Ponteiro para a estrutura do heap.
 * @return Número de elementos atualmente no heap.
 */
int HeapGetVirtuaSize(StructureHeap *heap);

/**
 * @brief Define o valor de um elemento no heap.
 *
 * Altera diretamente o valor armazenado no índice especificado.
 *
 * @param heap Ponteiro para a estrutura do heap.
 * @param index Índice do elemento a ser alterado (0 a size-1).
 * @param value Novo valor a ser colocado nessa posição.
 */
void HeapSetHeap(StructureHeap *heap, int index, float value);

/**
 * @brief Ajusta a capacidade do heap.
 *
 * Altera a capacidade máxima em relação ao valor atual.
 *
 * @param heap Ponteiro para a estrutura do heap.
 * @param value Valor a ser adicionado à capacidade.
 */
void HeapSetCapacity(StructureHeap *heap, int value);

/**
 * @brief Ajusta o tamanho atual do heap.
 *
 * Altera o campo `size` em relação ao valor atual.
 *
 * @param heap Ponteiro para a estrutura do heap.
 * @param value Valor a ser adicionado ao tamanho.
 */
void HeapSetSize(StructureHeap *heap, int value);

/**
 * @brief Ajusta o tamanho atual virtual do heap.
 *
 * Altera o campo `virtualSize` em relação ao valor atual.
 *
 * @param heap Ponteiro para a estrutura do heap.
 * @param value Valor a ser adicionado ao tamanho.
 */
void HeapSetVirtuaSize(StructureHeap *heap, int value);

/**
 * @brief Altera a capacidade do heap em uma quantidade específica.
 *
 * Incrementa ou decrementa o campo `capacity` da estrutura do heap
 * de acordo com o valor de `delta`. Pode ser positivo (aumenta) ou
 * negativo (diminui).
 *
 * @param heap Ponteiro para a estrutura do heap.
 * @param delta Valor a ser adicionado ao campo capacity.
 */
void HeapChangeCapacity(StructureHeap *heap, int delta);

/**
 * @brief Altera o tamanho atual do heap em uma quantidade específica.
 *
 * Incrementa ou decrementa o campo `size` de acordo com o valor de `delta`.
 *
 * @param heap Ponteiro para a estrutura do heap.
 * @param delta Valor a ser adicionado ao campo size.
 */
void HeapChangeSize(StructureHeap *heap, int delta);

/**
 * @brief "Sobe" o elemento na posição index até restaurar a propriedade de heap.
 * 
 * @param heap Ponteiro para o heap.
 * @param index Índice do elemento a ser ajustado.
 */
void HeapifyUp(StructureHeap *heap, int index);

/**
 * @brief "Desce" o elemento na posição index até restaurar a propriedade de heap.
 * 
 * @param heap Ponteiro para o heap.
 * @param index Índice do elemento a ser ajustado.
 */
void HeapifyDown(StructureHeap *heap, int index);

/**
 * @brief Extrai (remove e retorna) o maior elemento do heap.
 * 
 * @param heap Ponteiro para o heap.
 * @return Maior valor do heap, ou -1 se estiver vazio.
 */
float HeapExtractMax(StructureHeap *heap);

/**
 * @brief Insere uma nova chave no heap.
 * 
 * @param heap Ponteiro para o heap.
 * @param key Valor a ser inserido.
 */
void HeapInsertKey(StructureHeap *heap, float key);

/**
 * @brief Constrói um heap válido a partir do vetor já preenchido.
 * 
 * @param heap Ponteiro para o heap.
 */
void HeapBuildFromArray(StructureHeap *heap);

/**
 * @brief Imprime todos os elementos do heap no console.
 *
 * A função percorre o vetor interno do heap do índice 0 até heap->size - 1
 * e imprime os valores. 
 *
 * @param heap Ponteiro para o heap a ser impresso.
 *
 * @note Os elementos são impressos na ordem interna do vetor, não necessariamente
 *       em ordem decrescente de valor.
 */
void HeapPrint(StructureHeap *heap);

/**
 * @brief Troca os valores de dois elementos no heap.
 *
 * Realiza a troca dos valores entre os índices `indexP` e `indexS` do heap.
 *
 * @param heap Ponteiro para a estrutura do heap.
 * @param indexP Índice do primeiro elemento a ser trocado.
 * @param indexS Índice do segundo elemento a ser trocado.
 */
void HeapChangeValues(StructureHeap *heap, int indexP, int indexS);

/**
 * @brief Libera toda a memória usada pelo heap.
 *
 * Desaloca o vetor interno de dados (`data`) e a própria estrutura
 * do heap. 
 *
 * @param heap Ponteiro para a estrutura do heap a ser destruída.
 */
void HeapDestroy(StructureHeap *heap);

#endif

/*********************************************************************************************************************************/