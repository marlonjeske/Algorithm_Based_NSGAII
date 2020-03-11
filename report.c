/* Routines for storing population data into files */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
#include "rand.h"

/* Function to print the information of a population in a file */
void report_pop(population *pop, FILE *fpt) {
    int i, j;
    for (i = 0; i < popsize; i++) {
        for (j = 0; j < nobj; j++) {
            fprintf(fpt, "%d\t", (int) pop->ind[i].obj[j]*(-1));
        }

        if (ALL_POP_WITH_PATH) {
            for (j = 0; j < nreal; j++) {
                fprintf(fpt, "%d\t", pop->ind[i].xreal[j]);
            }
        }

        fprintf(fpt, "%e\t", pop->ind[i].constr_violation);
        fprintf(fpt, "%d\t", pop->ind[i].rank);
        fprintf(fpt, "%e", pop->ind[i].crowd_dist);
        fprintf(fpt, "\n");
    }

    return;
}

/* Function to print the information of feasible and non-dominated population in a file */
void report_feasible(population *pop, FILE *fpt) {
    int i, j, k;

    for (k = 1; k <= DEMANDA_MAX; k++) {

        for (i = 0; i < popsize; i++) {
            if (pop->ind[i].obj[0] * (-1) == k && pop->ind[i].constr_violation == 0.0 && pop->ind[i].rank == 1) {
                for (j = 0; j < nobj; j++) {
                    fprintf(fpt, "%d\t", (int) pop->ind[i].obj[j]*(-1));
                }
                for (j = 0; j < nreal; j++) {
                    fprintf(fpt, "%d\t", pop->ind[i].xreal[j]);
                }
                
                fprintf(fpt, "%e\t", pop->ind[i].constr_violation);
                fprintf(fpt, "%d\t", pop->ind[i].rank);
                fprintf(fpt, "%e", pop->ind[i].crowd_dist);
                fprintf(fpt, "\n");

                break;
            }
        }

    }
    return;
}

/*Report and evaluate cardinality and spacing of population */
void evaluate_metrics(population *pop, FILE *fpt) {
    int i, j;
    int cardinalidade = 0;
    double spacing = 0;
    int solucoes[DEMANDA_MAX][2];

    for (j = 1; j <= DEMANDA_MAX; j++) {
        for (i = 0; i < popsize; i++) {
            if (pop->ind[i].obj[0] * (-1) == j) {
                if (pop->ind[i].constr_violation == 0.0 && pop->ind[i].rank == 1) {
                    solucoes[cardinalidade][0] = pop->ind[i].obj[0] * (-1);
                    solucoes[cardinalidade][1] = pop->ind[i].obj[1] * (-1);
                    cardinalidade++;
                    break;
                }
            }
        }
    }

    fprintf(fpt, "\n Cardinality: %d", cardinalidade);

    if (cardinalidade <= 2) {
        spacing = 0;
    } else {

        int k, w, cont = 0;
        double min_distancia;

        double resultado[cardinalidade - 1]; //Vetor aux
        double distancia[cardinalidade]; //Vetor de distancias entre soluções
        double distancia_media = 0, soma_distancia = 0, soma_spacing = 0;

        for (i = 0; i < cardinalidade; i++) {

            cont = 0;

            for (k = 0; k < cardinalidade; k++) {
                if (i != k) {
                    resultado[cont++] = (abs((solucoes[i][0] - solucoes[k][0])) + abs((solucoes[i][1] - solucoes[k][1])));
                }
            }

            min_distancia = resultado[0];

            for (w = 1; w < cardinalidade - 1; w++) {
                if (min_distancia > resultado[w]) {
                    min_distancia = resultado[w];
                }
            }

            distancia[i] = min_distancia;
            soma_distancia += min_distancia;
        };

        distancia_media = soma_distancia / cardinalidade;

        for (i = 0; i < cardinalidade; i++) {
            soma_spacing += pow((distancia[i] - distancia_media), 2);
        }

        spacing = sqrt((1.0 / cardinalidade) * soma_spacing);

    }

    fprintf(fpt, "\n Spacing: %f\n", spacing);

    return;
}

