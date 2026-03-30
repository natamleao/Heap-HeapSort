#define _POSIX_C_SOURCE 199309L
#include "calculateTime.h"
#include <time.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

double elapsed(struct timespec a, struct timespec b){
    return (b.tv_sec - a.tv_sec) + (b.tv_nsec - a.tv_nsec) / 1e9;
}

/******************************************************* INTERFACE PUBLICA *******************************************************/

double calculateTime(void (*func)(StructureHeap *heap), StructureHeap *heap){
    struct timespec t1, t2;
    clock_gettime(CLOCK_MONOTONIC, &t1);
    func(heap);
    clock_gettime(CLOCK_MONOTONIC, &t2);
    
    return elapsed(t1, t2);
}

void calculateTimePrintTime(double executionTime){
    int hours, minutes, seconds, milliseconds;

    hours = (int)(executionTime / 3600);
    minutes = (int)((executionTime - hours*3600) / 60);
    seconds = (int)(executionTime - hours*3600 - minutes*60);
    milliseconds = (int)((executionTime - hours*3600 - minutes*60 - seconds) * 1000);

    printf("Tempo de execução: %d H : %d M : %d S : %d ms\n", hours, minutes, seconds, milliseconds);
}

/*********************************************************************************************************************************/