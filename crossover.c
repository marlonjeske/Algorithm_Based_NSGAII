/* Crossover routines */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "global.h"
#include "rand.h"


//Crossover operator
void crossover(individual *parent1, individual *parent2, individual *child1, individual *child2) {
    int j;
    double rand;

    rand = randomperc();
    if (rand <= pcross_real) {

        nrealcross++;

        int demanda_rnd = rnd(1, (DEMANDA_MAX - 1));

        int site = demanda_rnd * T;

        for (j = 0; j < site; j++) {
            child1->xreal[j] = parent1->xreal[j];
            child2->xreal[j] = parent2->xreal[j];

            child1->xreal_copia[j] = parent1->xreal_copia[j];
            child2->xreal_copia[j] = parent2->xreal_copia[j];
        }
        for (j = site; j < nreal; j++) {
            child1->xreal[j] = parent2->xreal[j];
            child2->xreal[j] = parent1->xreal[j];

            child1->xreal_copia[j] = parent2->xreal_copia[j];
            child2->xreal_copia[j] = parent1->xreal_copia[j];
        }

    } else {

        for (j = 0; j < nreal; j++) {
            child1->xreal[j] = parent1->xreal[j];
            child2->xreal[j] = parent2->xreal[j];

            child1->xreal_copia[j] = parent1->xreal_copia[j];
            child2->xreal_copia[j] = parent2->xreal_copia[j];
        }
    }

    return;
}