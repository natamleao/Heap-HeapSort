#define _POSIX_C_SOURCE 199309L
#include "../include/execution_time.h"
#include <time.h>
#include <stdio.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

double elapsed(struct timespec a, struct timespec b){
    return (b.tv_sec - a.tv_sec) * 1e9 + (b.tv_nsec - a.tv_nsec);
} 

/******************************************************* INTERFACE PUBLICA *******************************************************/

double executionTimeCalculate(void (*function)(void *), void *data){
    struct timespec t1, t2;
    clock_gettime(CLOCK_MONOTONIC, &t1);
    function(data);
    clock_gettime(CLOCK_MONOTONIC, &t2);
    
    return elapsed(t1, t2);
}

void executionTimePrint(double executionTime){
    long long total_ms = (long long)(executionTime / 1e6);  
    int hours = total_ms / 3600000;
    int minutes = (total_ms % 3600000) / 60000;
    int seconds = (total_ms % 60000) / 1000;
    int milliseconds = total_ms % 1000;

    printf("Tempo de execução: %d H : %d M : %d S : %d ms\n", hours, minutes, seconds, milliseconds);
}

/*********************************************************************************************************************************/
