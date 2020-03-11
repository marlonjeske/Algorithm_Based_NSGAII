 /* Regenerate routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
#include "rand.h"

void regenerate_pop(population *pop) {
    int i;
    for (i = 0; i < popsize; i++) {
        regenerate_ind(&(pop->ind[i]));
    }
    return;
}

void regenerate_ind(individual *ind) {

    short no, d, ti, tf, i, no_colisao, ti2;

    for (d = 0; d < DEMANDA_MAX; d++) {

        ti = (T * d) + source_demanda[d][1];
        tf = T * (d + 1) - 1;

        for (no = tf; no >= ti + 1; no--) {

            if (ind->xreal[no] != -1 && ind->xreal[no] == ind->xreal[no - 1]) {
                
                for (i = no + 1; i <= tf; i++) {

                    ind->xreal[i - 1] = ind->xreal[i];

                    if (ind->xreal[i] == -1) {
                        break;
                    }

                    if (i == tf && ind->xreal[i] == 0) {
                        ind->xreal[i] = -1;
                    }
                }
            }
        }

        no_colisao = -1;

        for (no = ti + 1; no <= tf; no++) {

            if (ind->xreal[no] == -1 && ind->xreal[no - 1] > 0) {
                no_colisao = no - 1;
                break;
            }

            if (ind->xreal[no] == 0) {
                break;
            }
        }

        if (no_colisao != -1) {

            no = ind->xreal[no_colisao];

            ti2 = tf - (T - 1);

            while (no == ind->xreal_copia[ti2]) {
                ti2++;
            }

            if (ind->xreal_copia[ti2] != -1 && check_neighbor(no, ind->xreal_copia[ti2])) {
                for (int t = no_colisao; t < tf; t++) {

                    if (no > 0) {
                        no = ind->xreal_copia[ti2];
                        ti2++;
                    } else {
                        no = -1;
                    }

                    ind->xreal[t + 1] = no;
                }
            }
        }
    }
}