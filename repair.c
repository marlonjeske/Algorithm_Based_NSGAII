 /* Repair routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
# include "rand.h"



/*Repair collisions and concurrent trasmissions*/
/*Avoid collisions*/
void repair_collision_concurrent(individual *ind) {

    short no, no2, d, dd, tf, tf2, ti, ti2, t, i, j, k, s, vizinho, tentativas;
    int max_enlace = DEMANDA_MAX * T;
    unsigned short contador_nos_enlace_aguarda, contador_nos_enlace_envia;
    short nos_enlace_aguarda[max_enlace];
    short nos_enlace_envia[max_enlace];

    double prob_escolher_correcao = randomperc();

    if (prob_escolher_correcao < 0.5) {
        avoid_collision_sink(ind);
    }

    for (t = 0; t < T - 1; t++) {

        if (t > 0) {

            tentativas = 0;

            for (d = 0; d < DEMANDA_MAX; d++) {
                no = t + (T * d);
                tf = T * (d + 1) - 1;

                if (ind->xreal[no] != -1 && ind->xreal[no] != 0) {

                    for (dd = (d + 1); dd < DEMANDA_MAX; dd++) {
                        no2 = t + (T * dd);
                        tf2 = T * (dd + 1) - 1;

                        if (ind->xreal[no] == ind->xreal[no2]
                                && ind->xreal[no] != ind->xreal[no - 1]
                                && ind->xreal[no2] != ind->xreal[no2 - 1]
                                && ind->xreal[no - 1] != -1
                                && ind->xreal[no2 - 1] != -1) {

                            if (prob_escolher_correcao >= 0.5) {

                                vizinho = -1;

                                if (tentativas < DEMANDA_MAX) {

                                    tentativas++;

                                    vizinho = find_neighbor(ind->xreal[no - 1], ind->xreal[no + 1], ind->xreal[no]);

                                    if (vizinho == 0) {
                                        vizinho = -1;
                                    }

                                    if (vizinho != -1) {
                                        ind->xreal[no] = vizinho;

                                        d = 0;
                                        dd = 1;
                                        no = t + (T * d);
                                        tf = T * (d + 1) - 1;
                                    }

                                    if (vizinho == -1) {
                                        vizinho = find_neighbor(ind->xreal[no2 - 1], ind->xreal[no2 + 1], ind->xreal[no2]);

                                        if (vizinho == 0) {
                                            vizinho = -1;
                                        }

                                        if (vizinho != -1) {
                                            ind->xreal[no2] = vizinho;

                                            d = 0;
                                            dd = 1;
                                            no = t + (T * d);
                                            tf = T * (d + 1) - 1;
                                        }
                                    }
                                }

                                if (vizinho == -1 || tentativas > DEMANDA_MAX) {
                                    ti = tf - (T - 1);
                                    ti2 = tf2 - (T - 1);

                                    for (i = tf; i > no; i--) {

                                        if (ind->xreal[i] != -1 && ind->xreal[i] != ind->xreal_copia[ti]) {

                                            if (ind->xreal_copia[ti] != -1) {
                                                for (j = tf; j > ti; j--) {
                                                    ind->xreal_copia[j] = ind->xreal_copia[j - 1];
                                                }
                                            }
                                            ind->xreal_copia[ti] = ind->xreal[i];
                                        }

                                        ind->xreal[i] = -1;
                                    }

                                    for (i = tf2; i > no2; i--) {

                                        if (ind->xreal[i] != -1 && ind->xreal[i] != ind->xreal_copia[ti2]) {

                                            if (ind->xreal_copia[ti2] != -1) {
                                                for (j = tf2; j > ti2; j--) {
                                                    ind->xreal_copia[j] = ind->xreal_copia[j - 1];
                                                }
                                            }
                                            ind->xreal_copia[ti2] = ind->xreal[i];
                                        }

                                        ind->xreal[i] = -1;
                                    }

                                }

                            } else {
                                ti = tf - (T - 1);
                                ti2 = tf2 - (T - 1);

                                for (i = tf; i > no; i--) {

                                    if (ind->xreal[i] != -1 && ind->xreal[i] != ind->xreal_copia[ti]) {

                                        if (ind->xreal_copia[ti] != -1) {
                                            for (j = tf; j > ti; j--) {
                                                ind->xreal_copia[j] = ind->xreal_copia[j - 1];
                                            }
                                        }
                                        ind->xreal_copia[ti] = ind->xreal[i];
                                    }

                                    ind->xreal[i] = -1;
                                }

                                for (i = tf2; i > no2; i--) {

                                    if (ind->xreal[i] != -1 && ind->xreal[i] != ind->xreal_copia[ti2]) {

                                        if (ind->xreal_copia[ti2] != -1) {
                                            for (j = tf2; j > ti2; j--) {
                                                ind->xreal_copia[j] = ind->xreal_copia[j - 1];
                                            }
                                        }
                                        ind->xreal_copia[ti2] = ind->xreal[i];
                                    }

                                    ind->xreal[i] = -1;
                                }
                            }
                        }
                    }
                }
            }
        }

        contador_nos_enlace_aguarda = 0;
        contador_nos_enlace_envia = 0;

        for (i = 0; i < max_enlace; i++) {
            nos_enlace_aguarda[i] = 0;
            nos_enlace_envia[i] = 0;
        }

        for (d = DEMANDA_MAX - 1; d > 0; d--) {

            no = t + (T * d);
            tf = T * (d + 1) - 1;

            if (ind->xreal[no] != -1 && ind->xreal[no] != 0
                    && ind->xreal[no] != ind->xreal[no + 1] && ind->xreal[no + 1] != -1
                    && find_value(no, nos_enlace_envia, contador_nos_enlace_envia) == -1) {

                for (dd = (d - 1); dd >= 0; dd--) {
                    no2 = t + (T * dd);
                    tf2 = T * (dd + 1) - 1;

                    if (ind->xreal[no2] != -1 && ind->xreal[no2] != 0
                            && ind->xreal[no2] != ind->xreal[no2 + 1] && ind->xreal[no2 + 1] != -1
                            && (ind->xreal[no] == ind->xreal[no2] || check_neighbor(ind->xreal[no], ind->xreal[no2]) == 1)
                            && find_value(no2, nos_enlace_envia, contador_nos_enlace_envia) == -1) {

                        short s1 = tf;
                        for (s = no; s <= tf; s++) {
                            if (ind->xreal[s] == 0) {
                                s1 = s;
                                break;
                            }
                        }

                        short s2 = tf2;
                        for (s = no2; s <= tf2; s++) {
                            if (ind->xreal[s] == 0) {
                                s2 = s;
                                break;
                            }
                        }

                        if (s1 > s2) {
                            nos_enlace_envia[contador_nos_enlace_envia] = no;
                        } else {
                            nos_enlace_envia[contador_nos_enlace_envia] = no2;
                        }

                        contador_nos_enlace_envia++;
                    }
                }
            }
        }

        for (i = 0; i < contador_nos_enlace_envia; i++) {

            no = nos_enlace_envia[i];

            if (no >= 0) {

                for (d = 0; d < DEMANDA_MAX; d++) {

                    no2 = t + (T * d);

                    if (no != no2 && ind->xreal[no2] != -1 && ind->xreal[no2] != 0
                            && ind->xreal[no2] != ind->xreal[no2 + 1] && ind->xreal[no2 + 1] != -1
                            && (ind->xreal[no] == ind->xreal[no2] || check_neighbor(ind->xreal[no], ind->xreal[no2]) == 1)
                            && find_value(no2, nos_enlace_aguarda, contador_nos_enlace_aguarda) == -1) {

                        int no_aguardando = find_value(no2, nos_enlace_aguarda, contador_nos_enlace_aguarda);

                        if (no_aguardando == -1) {

                            nos_enlace_aguarda[contador_nos_enlace_aguarda] = no2;

                            contador_nos_enlace_aguarda++;

                            for (j = 0; j < contador_nos_enlace_envia; j++) {

                                if (i != j && no2 == nos_enlace_envia[j]) {
                                    nos_enlace_envia[j] = -1;
                                }
                            }
                        }
                    }
                }

                for (j = (i + 1); j < contador_nos_enlace_aguarda; j++) {

                    no2 = nos_enlace_aguarda[j];

                    if (no == no2) {
                        nos_enlace_aguarda[j] = -1;
                    }
                }
            }
        }

        for (j = 0; j < contador_nos_enlace_aguarda; j++) {

            no = nos_enlace_aguarda[j];

            if (no >= 0) {
                tf = ((((int) no / T) + 1) * T) - 1;
                ti = tf - (T - 1);

                for (i = tf; i > no; i--) {

                    if (i == tf && ind->xreal[i] != -1 && ind->xreal[i] != ind->xreal_copia[ti]) {

                        if (ind->xreal_copia[ti] != -1) {
                            for (k = tf; k > ti; k--) {
                                ind->xreal_copia[k] = ind->xreal_copia[k - 1];
                            }
                        }
                        ind->xreal_copia[ti] = ind->xreal[i];
                    }

                    ind->xreal[i] = ind->xreal[i - 1];
                }
            }
        }
    }
}

/*Avoid collision in Sink*/
void avoid_collision_sink(individual *ind) {

    short no, no2, d, dd, t, vizinho;

    for (t = T - 1; t > 0; t--) {

        for (d = 0; d < DEMANDA_MAX; d++) {

            no = t + (T * d);

            if (ind->xreal[no] == 0) {

                for (dd = (d + 1); dd < DEMANDA_MAX; dd++) {

                    no2 = t + (T * dd);

                    if (ind->xreal[no2] == 0) {

                        vizinho = find_neighbor(ind->xreal[no - 1], ind->xreal[no], 0);

                        if (vizinho != -1) {

                            ind->xreal[no] = vizinho;

                            if (t < T - 1) {
                                ind->xreal[no + 1] = 0;
                            }
                        }

                        vizinho = -1;

                        break;
                    }
                }
            }
        }
    }
}