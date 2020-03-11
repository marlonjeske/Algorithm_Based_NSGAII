/* Mutation routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
#include "rand.h"

void mutation_pop(population *pop) {
    int i;
    for (i = 0; i < popsize; i++) {
        mutation_ind(&(pop->ind[i]));
    }
    return;
}

void mutation_ind(individual *ind) {

    int j;
    double prob;

    for (j = 0; j < nreal; j += T) {
        prob = randomperc();
        if (prob <= pmut_real) {
            nrealmut += 1;

            int bit;
            int demanda = (int) j / T;
            int inicio_demanda = source_demanda[demanda][1];
            int fim_demanda = j + T - 1;
            int no_inicio_demanda = inicio_demanda + j;
            int no_fim_demanda = fim_demanda;

            for (int t = no_inicio_demanda; t < fim_demanda; t++) {
                if (ind->xreal[t] == 0 || ind->xreal[t] == -1) {
                    no_fim_demanda = t;
                    break;
                }
            }

            if (ind->xreal[no_fim_demanda] == -1) {
                no_fim_demanda--;
            }

            int max_tentativas = no_fim_demanda - no_inicio_demanda;
            int vizinho = -1;

            do {
                bit = rnd(no_inicio_demanda + 1, no_fim_demanda - 1);
                vizinho = find_neighbor(ind->xreal[bit - 1], ind->xreal[bit + 1], ind->xreal[bit]);

                if (vizinho == 0) {
                    vizinho = -1;
                }

                if (vizinho != -1) {
                    ind->xreal[bit] = vizinho;
                }

                max_tentativas--;

            } while (vizinho == -1 && max_tentativas > 0);
        }
    }

    repair_collision_concurrent(ind);

    return;
}