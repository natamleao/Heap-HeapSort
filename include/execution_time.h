/******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef CALCULATE_TIME_H
#define CALCULATE_TIME_H

/**
 * @brief Mede o tempo de execução de uma função que atua sobre uma estrutura genérica.
 *
 * @param function Ponteiro para a função a ser executada. Deve receber um parâmetro `void*` e não retornar valor.
 * @param data Ponteiro para a estrutura sobre a qual a função atuará.
 *
 * @return Tempo de execução da função em segundos (tipo `double`).
 *
 * @note Usa clock_gettime com CLOCK_MONOTONIC (tempo real de alta precisão).
 */
double executionTimeCalculate(void (*function)(void *), void *data);

/**
 * @brief Imprime o tempo de execução em horas, minutos, segundos e milissegundos.
 *
 * @param executionTime Tempo total em segundos (tipo `double`).
 *
 * @note Apenas imprime o resultado no console; não retorna nenhum valor.
 */
void executionTimePrint(double executionTime);

#endif

/*********************************************************************************************************************************/
