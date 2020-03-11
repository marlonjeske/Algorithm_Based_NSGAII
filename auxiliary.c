/* Some utility functions (not part of the algorithm) */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
#include "rand.h"

/* Function to return the maximum of two variables */
double maximum(double a, double b) {
    if (a > b) {
        return (a);
    }
    return (b);
}

/* Function to return the minimum of two variables */
double minimum(double a, double b) {
    if (a < b) {
        return (a);
    }
    return (b);
}

/* Randomly finds a neighbor in common between two nodes, which is different from the current node
 * If not found, returns -1 */
int find_neighbor(int no_i, int no_j, int no_atual) {
    short i, j;
    short count = 0;
    short vizinhos[N] = {0};

    for (i = 0; i < adj_list_size[no_i]; i++) {
        for (j = 0; j < adj_list_size[no_j]; j++) {
            if (adj_list[no_i][i] == adj_list[no_j][j] && adj_list[no_i][i] != no_atual) {
                vizinhos[count++] = adj_list[no_i][i];
            }
        }
    }

    if (count > 0) {
        short rand_no = rnd(0, count - 1);
        return vizinhos[rand_no];
    }

    return -1;
}

/* Check if nodes are neighbors */
int check_neighbor(int no_i, int no_j) {
    short tamanho = adj_list_size[no_i];
    for (short i = 0; i < tamanho; i++) {
        if (adj_list[no_i][i] == no_j) {
            return 1;
        }
    }
    return 0;
}

/* Check if there is any demand in node and period*/
int check_initial_demand(int no_i, int t) {
    for (short i = 0; i < DEMANDA_MAX; i++) {
        if (source_demanda[i][0] == no_i && source_demanda[i][1] == t) {
            return 1;
        }
    }
    return 0;
}

/* Find a number in an array */
int find_value(short numero, short vetor[], short tamanho_vetor) {
    short i;
    for (i = 0; i < tamanho_vetor; i++) {
        if (vetor[i] == numero) {
            return i;
        }
    }
    return -1;
}