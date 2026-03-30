/******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef HEAP_H
#define HEAP_H

// Estrutura de Heap Máximo
typedef struct _heap Heap;

/**
 * @brief Cria a estrutura de um Heap a partir de um array qualquer.
 *
 * Copia os elementos do array passado para o array da estrutura,
 * mas sem transformá-la em um Heap, ajusta size, vituralSize e capacidade.
 *
 * @param array Ponteiro para o array de floats.
 * @param size Quantidade de elementos válidos no array.
 * @param capacity Capacidade máxima que o Heap deve ter (>= array_size).
 * @return Ponteiro para o Heap alocado, ou NULL se falhar.
 */
Heap* heapCreate(float *array, int size, int capacity);

/**
 * @brief Retorna o vetor interno de dados do Heap.
 *
 * Permite acesso direto ao array que armazena os elementos do Heap.
 *
 * @param Heap Ponteiro para a estrutura do Heap.
 * @return Ponteiro para o vetor de floats que representa os dados.
 */
float* heapGetHeap(Heap *Heap);

/**
 * @brief Retorna a capacidade máxima do Heap.
 *
 * Informa quantos elementos o Heap pode armazenar antes de ocorrer overflow.
 *
 * @param Heap Ponteiro para a estrutura do Heap.
 * @return Capacidade máxima do Heap.
 */
int heapGetCapacity(Heap *Heap);

/**
 * @brief Retorna o tamanho atual do Heap.
 *
 * Indica quantos elementos válidos estão armazenados no Heap no momento.
 *
 * @param Heap Ponteiro para a estrutura do Heap.
 * @return Número de elementos atualmente no Heap.
 */
int heapGetSize(Heap *Heap);

/**
 * @brief Retorna o tamanho atual virtual do Heap.
 *
 * Indica quantos elementos válidos estão armazenados no Heap no momento.
 *
 * @param Heap Ponteiro para a estrutura do Heap.
 * @return Número de elementos atualmente no Heap.
 */
int heapGetVirtuaSize(Heap *Heap);

/**
 * @brief Define o valor de um elemento no Heap.
 *
 * Altera diretamente o valor armazenado no índice especificado.
 *
 * @param Heap Ponteiro para a estrutura do Heap.
 * @param index Índice do elemento a ser alterado (0 a size-1).
 * @param value Novo valor a ser colocado nessa posição.
 */
void heapSetHeap(Heap *Heap, int index, float value);

/**
 * @brief Ajusta a capacidade do Heap.
 *
 * Altera a capacidade máxima em relação ao valor atual.
 *
 * @param Heap Ponteiro para a estrutura do Heap.
 * @param value Valor a ser adicionado à capacidade.
 */
void heapSetCapacity(Heap *Heap, int value);

/**
 * @brief Ajusta o tamanho atual do Heap.
 *
 * Altera o campo `size` em relação ao valor atual.
 *
 * @param Heap Ponteiro para a estrutura do Heap.
 * @param value Valor a ser adicionado ao tamanho.
 */
void heapSetSize(Heap *Heap, int value);

/**
 * @brief Ajusta o tamanho atual virtual do Heap.
 *
 * Altera o campo `virtualSize` em relação ao valor atual.
 *
 * @param Heap Ponteiro para a estrutura do Heap.
 * @param value Valor a ser adicionado ao tamanho.
 */
void heapSetVirtuaSize(Heap *Heap, int value);

/**
 * @brief Altera a capacidade do Heap em uma quantidade específica.
 *
 * Incrementa ou decrementa o campo `capacity` da estrutura do Heap
 * de acordo com o valor de `delta`. Pode ser positivo (aumenta) ou
 * negativo (diminui).
 *
 * @param Heap Ponteiro para a estrutura do Heap.
 * @param delta Valor a ser adicionado ao campo capacity.
 */
void heapChangeCapacity(Heap *Heap, int delta);

/**
 * @brief Altera o tamanho atual do Heap em uma quantidade específica.
 *
 * Incrementa ou decrementa o campo `size` de acordo com o valor de `delta`.
 *
 * @param Heap Ponteiro para a estrutura do Heap.
 * @param delta Valor a ser adicionado ao campo size.
 */
void heapChangeSize(Heap *Heap, int delta);

/**
 * @brief "Sobe" o elemento na posição index até restaurar a propriedade de Heap.
 * 
 * @param Heap Ponteiro para o Heap.
 * @param index Índice do elemento a ser ajustado.
 */
void heapifyUp(Heap *Heap, int index);

/**
 * @brief "Desce" o elemento na posição index até restaurar a propriedade de Heap.
 * 
 * @param Heap Ponteiro para o Heap.
 * @param index Índice do elemento a ser ajustado.
 */
void heapifyDown(Heap *Heap, int index);

/**
 * @brief Extrai (remove e retorna) o maior elemento do Heap.
 * 
 * @param Heap Ponteiro para o Heap.
 * @return Maior valor do Heap, ou -1 se estiver vazio.
 */
float heapExtractMax(Heap *Heap);

/**
 * @brief Insere uma nova chave no Heap.
 * 
 * @param Heap Ponteiro para o Heap.
 * @param key Valor a ser inserido.
 */
void heapInsertKey(Heap *Heap, float key);

/**
 * @brief Constrói um Heap válido a partir do vetor já preenchido.
 * 
 * @param Heap Ponteiro para o Heap.
 */
void heapBuildFromArray(Heap *Heap);

/**
 * @brief Imprime todos os elementos do Heap no console.
 *
 * A função percorre o vetor interno do Heap do índice 0 até Heap->size - 1
 * e imprime os valores. 
 *
 * @param Heap Ponteiro para o Heap a ser impresso.
 *
 * @note Os elementos são impressos na ordem interna do vetor, não necessariamente
 *       em ordem decrescente de valor.
 */
void heapPrint(Heap *Heap);

/**
 * @brief Troca os valores de dois elementos no Heap.
 *
 * Realiza a troca dos valores entre os índices `indexP` e `indexS` do Heap.
 *
 * @param Heap Ponteiro para a estrutura do Heap.
 * @param indexP Índice do primeiro elemento a ser trocado.
 * @param indexS Índice do segundo elemento a ser trocado.
 */
void heapChangeValues(Heap *Heap, int indexP, int indexS);

/**
 * @brief Libera toda a memória usada pelo Heap.
 *
 * Desaloca o vetor interno de dados (`data`) e a própria estrutura
 * do Heap. 
 *
 * @param Heap Ponteiro para a estrutura do Heap a ser destruída.
 */
void heapDestroy(Heap *Heap);

#endif

/*********************************************************************************************************************************/