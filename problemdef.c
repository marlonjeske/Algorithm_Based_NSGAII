/* Problem definitions */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>

# include "global.h"
# include "rand.h"

# define Model


#ifdef Model

void network_problem(int *xreal, double *obj, double *constr) {
    unsigned int contador_bits = 0;
    double sum_restricao = 0.0;
    short i, j, t, r, d;
    unsigned char z, y;

    unsigned short **b = (unsigned short **) malloc(sizeof *b * N);
    unsigned short **sum_Ni = (unsigned short **) malloc(sizeof *sum_Ni * N);
    unsigned short **sum_Ni_ = (unsigned short **) malloc(sizeof *sum_Ni_ * N);

    if (b == NULL || sum_Ni == NULL || sum_Ni_ == NULL) {
        printf("memory allocation failed.");
        exit(0);
    }

    /*Decode individuals*/
    for (i = 0; i < N; i++) {
        b[i] = (unsigned short *) malloc(sizeof *b[i] * T);
        sum_Ni[i] = (unsigned short *) malloc(sizeof *sum_Ni[i] * T);
        sum_Ni_[i] = (unsigned short *) malloc(sizeof *sum_Ni_[i] * T);

        if (b[i] == NULL || sum_Ni[i] == NULL || sum_Ni_[i] == NULL) {
            printf("memory allocation failed [i].");
            exit(0);
        }


        for (t = 0; t < T; t++) {
            b[i][t] = 0;
            sum_Ni[i][t] = 0;
            sum_Ni_[i][t] = 0;
        }
    }

    for (d = 0; d < DEMANDA_MAX; d++) {

        contador_bits = d * T;

        for (t = 0; t < T - 1; t++) {

            i = xreal[contador_bits];
            j = xreal[(contador_bits + 1)];
            contador_bits++;

            if (i != 0 && i != -1 && j != -1 && i != j && check_neighbor(i, j)) {
                sum_Ni[i][t] = sum_Ni[i][t] + 1;
                sum_Ni_[j][t] = sum_Ni_[j][t] + 1;
            } else if (i != 0 && i != -1 && j != -1 && i != j && check_neighbor(i, j) == 0) {
                sum_restricao += -1;
            }
        }
    }

    /*Define constraints*/
    for (t = 0; t < T; t++) {
        for (i = 1; i < N; i++) {

            if (t > 0 && sum_Ni_[i][t - 1] == 1) {
                r = 1;
            } else {
                r = 0;
            }

            if (t == 0) {
                b[i][t] = check_initial_demand(i, t) - sum_Ni[i][t];
            } else {
                b[i][t] = b[i][t - 1] + check_initial_demand(i, t) + r - sum_Ni[i][t];
            }

            if (b[i][t] < 0.0) {
                sum_restricao += b[i][t];
            }
        }
    }



    for (t = 0; t < T; t++) {
        for (i = 1; i < N; i++) {

            z = 0;
            short tamanho = adj_list_size[i];
            for (j = 0; j < tamanho; j++) {
                short no_j = adj_list[i][j];
                if (sum_Ni[no_j][t] == 1) {
                    z = 1;
                    break;
                }
            }


            if (t > 0 && sum_Ni_[i][t - 1] == 1) {
                r = 1;
            } else {
                r = 0;
            }

            if (i > 0) {
                if (t == 0) {
                    y = check_initial_demand(i, t);
                } else if (t > 0 && (b[i][t - 1] + check_initial_demand(i, t) + r) > 0 && t < T - 1) {
                    y = 1;
                } else {
                    y = 0;
                }
            }

            if (1 - z - sum_Ni[i][t] < 0.0) {
                sum_restricao += 1 - z - sum_Ni[i][t];
            }

            if (z + sum_Ni[i][t] - y < 0.0) {
                sum_restricao += z + sum_Ni[i][t] - y;
            }

        }
    }

    /*Define objective functions*/
    short obj_fr = 0;
    for (t = 1; t < T; t++) {

        if (t > 0 && sum_Ni_[0][t - 1] == 1) {
            r = 1;
        } else {
            r = 0;
        }

        obj_fr += r;
    }

    int obj_fe = (N - 1) * energia_inicial;
    int eit = 0;
    int sum_t = 0;

    for (i = 1; i < N; i++) {
        sum_t = 0;
        for (t = 0; t < T; t++) {
            sum_t += sum_Ni[i][t];
        }

        eit = energia_inicial - sum_t;

        if (eit < 0.0) {
            sum_restricao += eit;
        }

        obj_fe -= sum_t;
    }

    obj[0] = obj_fr * (-1);

    obj[1] = obj_fe * (-1);

    constr[0] = sum_restricao;

    for (i = 0; i < N; i++) {
        free(b[i]);
        free(sum_Ni[i]);
        free(sum_Ni_[i]);
    }
    free(b);
    free(sum_Ni);
    free(sum_Ni_);

    return;
}

#endif
