/* Data initializtion routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
#include "rand.h"

//Initialize population
void initialize_pop(population *pop) {
    int i;
    for (i = 0; i < popsize; i++) {
        initialize_ind(&(pop->ind[i]));

        add_node_min_path(&(pop->ind[i]));

        repair_collision_concurrent(&(pop->ind[i]));
    }
    return;
}

//Initialize chromosome and copy 
void initialize_ind(individual *ind) {
    int j, k, s, bit, td;
    for (j = 0; j < nreal; j += T) {

        s = (int) (j / T);

        int indice_min_path = rnd(1, min_paths_size[s]) - 1;

        for (k = 0; k < T; k++) {

            bit = j + k;

            if (k == source_demanda[s][1]) {
                ind->xreal[bit] = source_demanda[s][0];
            } else if (k > source_demanda[s][1] && ind->xreal[bit - 1] != 0 && ind->xreal[bit - 1] != -1) {
                td = k - source_demanda[s][1];
                ind->xreal[bit] = min_paths[s][indice_min_path][td];

            } else {
                ind->xreal[bit] = -1;
            }
        }
    }

    for (j = 0; j < nreal; j++) {
        ind->xreal_copia[j] = -1;
    }


    return;
}

//Add node in the shortest path
void add_node_min_path(individual *ind) {
    int j, no, ultimo_no, ultimo_no_util, tentativas, demanda, inicio_demanda, a, vizinho;
    double prob;

    for (j = 0; j < nreal; j += T) {
        prob = randomperc();
        if (prob <= PADD_NODE) {

            demanda = (int) j / T;
            inicio_demanda = source_demanda[demanda][1] + j;
            ultimo_no = ((demanda + 1) * T) - 1;
            ultimo_no_util = ultimo_no;

            for (a = inicio_demanda; a <= ultimo_no; a++) {
                if (ind->xreal[a] != -1) {
                    ultimo_no_util = a;
                }
            }

            do {

                no = rnd(inicio_demanda, ultimo_no_util - 1);

                vizinho = find_neighbor(ind->xreal[no], ind->xreal[no + 1], 0);
                if (vizinho != -1) {

                    for (a = ultimo_no; a > no; a--) {
                        if (a == no + 1) {
                            ind->xreal[a] = vizinho;
                        } else {
                            ind->xreal[a] = ind->xreal[a - 1];
                        }
                    }
                }

                tentativas++;

            } while (vizinho == -1 && tentativas < T);

        }
    }

    return;
}
