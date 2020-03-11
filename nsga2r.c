/* NSGA-II routine (implementation of the 'main' function) */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <time.h>

# include "global.h"
# include "rand.h"


  # include "input_small_scale.h"
//# include "input_small_scale_d1t20.h"
//# include "input_small_scale_d2t20.h"
//# include "input_small_scale_d3t20.h"
//# include "input_small_scale_d4t20.h"
  # include "input_small_scale_d5t20.h"
//# include "input_small_scale_d1t50.h"
//# include "input_small_scale_d2t50.h"
//# include "input_small_scale_d3t50.h"
//# include "input_small_scale_d4t50.h"
//# include "input_small_scale_d5t50.h"

//# include "input_large_scale.h"
//# include "input_large_scale_d84.h"
//# include "input_large_scale_d103.h"
//# include "input_large_scale_d133.h"
//# include "input_large_scale_d148.h"


int nreal;
int nobj;
int ncon;
int popsize;
double pcross_real;
double pmut_real;
int ngen;
int nrealmut;
int nrealcross;
int obj1;
int obj2;

int main(int argc, char **argv) {
    
    clock_t tempo;
    clock_t tempo_fim;
    clock_t tempo_parcial;
    clock_t tempo_geracao;
    clock_t tempo_geracao_fim;
    tempo = clock();

    int i;
    FILE *fpt1;
    FILE *fpt2;
    FILE *fpt3;
    FILE *fpt4;
    FILE *fpt5;
    population *parent_pop;
    population *child_pop;
    population *mixed_pop;

    seed = SEED;

    if (seed <= 0.0 || seed >= 1.0) {
        printf("\n Entered seed value is wrong, seed value must be in (0,1) \n");
        exit(1);
    }
    fpt1 = fopen("initial_pop.out", "w");
    fpt2 = fopen("final_pop.out", "w");
    fpt3 = fopen("best_pop.out", "w");
    fpt4 = fopen("all_pop.out", "w");
    fpt5 = fopen("params.out", "w");
    fprintf(fpt1, "# This file contains the data of initial population\n");
    fprintf(fpt2, "# This file contains the data of final population\n");
    fprintf(fpt3, "# This file contains the data of final feasible population (if found)\n");
    fprintf(fpt4, "# This file contains the data of all generations\n");
    fprintf(fpt5, "# This file contains information about inputs as read by the program\n");
    printf("\n Enter the problem relevant and algorithm relevant parameters ... ");

    popsize = POPSIZE;
    if (popsize < 4 || (popsize % 4) != 0) {
        printf("\n population size read is : %d", popsize);
        printf("\n Wrong population size entered, hence exiting \n");
        exit(1);
    }
    ngen = NGEN;
    if (ngen < 1) {
        printf("\n number of generations read is : %d", ngen);
        printf("\n Wrong nuber of generations entered, hence exiting \n");
        exit(1);
    }
    nobj = NOBJ;
    if (nobj < 1) {
        printf("\n number of objectives entered is : %d", nobj);
        printf("\n Wrong number of objectives entered, hence exiting \n");
        exit(1);
    }
    ncon = 1;
    if (ncon < 0) {
        printf("\n number of constraints entered is : %d", ncon);
        printf("\n Wrong number of constraints enetered, hence exiting \n");
        exit(1);
    }
    nreal = DEMANDA_MAX * T;
    if (nreal <= 0) {
        printf("\n number of variables entered is : %d", nreal);
        printf("\n Wrong number of variables entered, hence exiting \n");
        exit(1);
    }

    pcross_real = PCROSS;
    if (pcross_real < 0.0 || pcross_real > 1.0) {
        printf("\n Probability of crossover entered is : %e", pcross_real);
        printf("\n Entered value of probability of crossover of variables is out of bounds, hence exiting \n");
        exit(1);
    }
    pmut_real = PMUT;
    if (pmut_real < 0.0 || pmut_real > 1.0) {
        printf("\n Probability of mutation entered is : %e", pmut_real);
        printf("\n Entered value of probability of mutation of variables is out of bounds, hence exiting \n");
        exit(1);
    }

    printf("\n Input data successfully entered, now performing initialization \n");
    fprintf(fpt5, "\n Population size = %d", popsize);
    fprintf(fpt5, "\n Number of generations = %d", ngen);
    fprintf(fpt5, "\n Number of objective functions = %d", nobj);
    fprintf(fpt5, "\n Number of variables = %d", nreal);
    fprintf(fpt5, "\n Probability of crossover of variable = %e", pcross_real);
    fprintf(fpt5, "\n Probability of mutation of variable = %e", pmut_real);
    fprintf(fpt5, "\n Seed for random number generator = %e", seed);
    fprintf(fpt1, "# of objectives = %d, # of var = %d, constr_violation, rank, crowding_distance\n", nobj, nreal);
    fprintf(fpt2, "# of objectives = %d, # of var = %d, constr_violation, rank, crowding_distance\n", nobj, nreal);
    fprintf(fpt3, "# of objectives = %d, # of var = %d, constr_violation, rank, crowding_distance\n", nobj, nreal);
    fprintf(fpt4, "# of objectives = %d, # of var = %d, constr_violation, rank, crowding_distance\n", nobj, nreal);
    nrealmut = 0;
    nrealcross = 0;
    parent_pop = (population *) malloc(sizeof (population));
    child_pop = (population *) malloc(sizeof (population));
    mixed_pop = (population *) malloc(sizeof (population));
    allocate_memory_pop(parent_pop, popsize);
    allocate_memory_pop(child_pop, popsize);
    allocate_memory_pop(mixed_pop, 2 * popsize);
    randomize();
    tempo_geracao = clock();
    initialize_pop(parent_pop);
    printf("\n Initialization done, now performing first generation");
    evaluate_pop(parent_pop);
    assign_rank_and_crowding_distance(parent_pop);
    tempo_geracao_fim = clock();
    report_pop(parent_pop, fpt1); //initial_pop
    fprintf(fpt4, "\n gen = 1 - time = %f \n", ((tempo_geracao_fim - tempo_geracao) / (double) CLOCKS_PER_SEC));
    report_pop(parent_pop, fpt4); //all_pop
    evaluate_metrics(parent_pop, fpt4);

    printf("\n gen = 1 - time = %f", ((tempo_geracao_fim - tempo_geracao) / (double) CLOCKS_PER_SEC));
    fflush(stdout);
    fflush(fpt1);
    fflush(fpt2);
    fflush(fpt3);
    fflush(fpt4);
    fflush(fpt5);
    sleep(1);

    for (i = 2; i <= ngen; i++) {
        tempo_geracao = clock();
        selection(parent_pop, child_pop);
        regenerate_pop(child_pop);
        mutation_pop(child_pop);
        evaluate_pop(child_pop);
        merge(parent_pop, child_pop, mixed_pop);
        fill_nondominated_sort(mixed_pop, parent_pop);
        tempo_geracao_fim = clock();

        if (i % REPORT_EVERY_GEN == 0) {
            fprintf(fpt4, "\n gen = %d - time = %f \n", i, ((tempo_geracao_fim - tempo_geracao) / (double) CLOCKS_PER_SEC));
            report_feasible(parent_pop, fpt4);

            tempo_parcial = clock();
            fprintf(fpt4, "\n Computational time = %f", ((tempo_parcial - tempo) / (double) CLOCKS_PER_SEC));
            evaluate_metrics(parent_pop, fpt4);

            fflush(fpt4);
        }
        printf("\n gen = %d - time = %f", i, ((tempo_geracao_fim - tempo_geracao) / (double) CLOCKS_PER_SEC));

    }

    tempo_fim = clock();

    printf("\n Generations finished, now reporting solutions");
    report_pop(parent_pop, fpt2);
    report_feasible(parent_pop, fpt3);

    fprintf(fpt5, "\n Number of crossover of variable = %d", nrealcross);
    fprintf(fpt5, "\n Number of mutation of variable = %d", nrealmut);

    fprintf(fpt3, "\n Population size = %d", popsize);
    fprintf(fpt3, "\n Number of generations = %d", ngen);
    fprintf(fpt3, "\n Number of objective functions = %d", nobj);
    fprintf(fpt3, "\n Number of variables = %d", nreal);
    fprintf(fpt3, "\n Probability of crossover of variable = %e", pcross_real);
    fprintf(fpt3, "\n Probability of mutation of variable = %e", pmut_real);
    fprintf(fpt3, "\n Seed for random number generator = %e", seed);
    fprintf(fpt3, "\n Number of crossover of variable = %d", nrealcross);
    fprintf(fpt3, "\n Number of mutation of variable = %d", nrealmut);
    fprintf(fpt3, "\n Computational time: %f", (tempo_fim - tempo) / (double) CLOCKS_PER_SEC);

    evaluate_metrics(parent_pop, fpt3);

    fprintf(fpt4, "\n\n Population size = %d", popsize);
    fprintf(fpt4, "\n Number of generations = %d", ngen);
    fprintf(fpt4, "\n Number of objective functions = %d", nobj);
    fprintf(fpt4, "\n Number of variables (chromosome size)= %d", nreal);
    fprintf(fpt4, "\n Probability of crossover = %e", pcross_real);
    fprintf(fpt4, "\n Probability of mutation = %e", pmut_real);
    fprintf(fpt4, "\n Seed for random number generator = %e", seed);
    fprintf(fpt4, "\n Number of crossover = %d", nrealcross);
    fprintf(fpt4, "\n Number of mutation = %d", nrealmut);
    fprintf(fpt4, "\n Computational time: %f", (tempo_fim - tempo) / (double) CLOCKS_PER_SEC);

    fflush(stdout);
    fflush(fpt1);
    fflush(fpt2);
    fflush(fpt3);
    fflush(fpt4);
    fflush(fpt5);
    fclose(fpt1);
    fclose(fpt2);
    fclose(fpt3);
    fclose(fpt4);
    fclose(fpt5);

    deallocate_memory_pop(parent_pop, popsize);
    deallocate_memory_pop(child_pop, popsize);
    deallocate_memory_pop(mixed_pop, 2 * popsize);
    free(parent_pop);
    free(child_pop);
    free(mixed_pop);
    printf("\n Routine successfully exited \n");

    printf("Time: %f", (tempo_fim - tempo) / (double) CLOCKS_PER_SEC);

    return (0);
}