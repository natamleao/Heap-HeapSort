  /******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef CALCULATE_TIME_H
#define CALCULATE_TIME_H

#include "heap.h"

/**
 * @brief Mede o tempo de execução de uma função que atua sobre uma estrutura.
 *
 * @param function Ponteiro para a função a ser executada. Essa função deve receber um parâmetro do tipo `void*` e não retornar valor.
 * @param data Ponteiro para a estrutura sobre a qual a função irá atuar.
 *
 * @return Tempo de execução da função (em segundos) como um valor do tipo `double`.
 *
 * @note Usa a função `clock()` da biblioteca `<time.h>`, logo mede tempo de CPU, não tempo real decorrido.
 */
double executionTimeCalculate(void (*function)(void *), void *data);

/**
 * @brief Imprime o tempo de execução em horas, minutos, segundos e milissegundos.
 *
 * Esta função recebe o tempo total em segundos (tipo double) e converte
 * para horas, minutos, segundos e milissegundos, imprimindo no formato:
 * "H M S ms".
 *
 * @param executionTime Tempo total em segundos (pode conter fração para milissegundos).
 *
 * @note A função apenas imprime o resultado na tela; não retorna nenhum valor.
 */
void executionTimePrint(double executionTime);

#endif

/*********************************************************************************************************************************/