/* Routine for evaluating population members  */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
#include "rand.h"

/* Routine to evaluate objective function values and constraints for a population */
void evaluate_pop(population *pop) {
    int i;
    for (i = 0; i < popsize; i++) {
        evaluate_ind(&(pop->ind[i]));
    }
    return;
}

/* Routine to evaluate objective function values and constraints for an individual */
void evaluate_ind(individual *ind) {
    int j;
    network_problem(ind->xreal, ind->obj, ind->constr);

    ind->constr_violation = 0.0;
    for (j = 0; j < ncon; j++) {
        if (ind->constr[j] < 0.0) {
            ind->constr_violation += ind->constr[j];
        }
    }

    return;
}
