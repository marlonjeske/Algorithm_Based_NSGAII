# About the proposed algorithm

We introduce an efficient evolutionary algorithm based on the Non-dominated Sorting Genetic Algorithm II (NSGA-II) to solve a multi-objective integer problem to the routing problem in wireless sensors network to optimize both energy consumption and delivery reliability. This algorithm was developed based on source code of the Multi-objective NSGA-II code in C, revision 1.1.6 (08 July 2011), available at the following link: http://www.iitk.ac.in/kangal/codes.shtml

Authors: Marlon Jeske, Valério Rosset and Mariá C.V. Nascimento

## Input parameters

The input parameters of the algorithm are located in header files.

To run the instances, you must use the file input_small_scale.h and input_large_scale.h, which refer to small-scale and large-scale networks, respectively.

In these files, you will find the necessary parameters to use the proposed algorithm and the report options for the solutions.

- SEED: used to generate random numbers
- POPSIZE: population size (a multiple of 4)
- NGEN: number of generations
- NOBJ: number of objectives
- PCROSS: probability of crossover
- PMUT: probability of mutation
- PADD_NODE: probability of adding a node to the shortest path in the initial population
- ALL_POP_WITH_PATH: Reports all pop with path or not
- REPORT_EVERY_GEN: Report all pop every generation

After these settings, you will find all definitions of the instances.

### For small-scale

For small-scale instances use the file inpute_small_scale.h and uncomment the network namely SMALL_SCALE_NETWORK and after one of the 10 instances you prefer.

Below these options you will find information about the small-scale network such as the number of nodes, the initial energy value of the nodes, adjacency lists and the size of each list for each node.

The small-scale instances that have 5 instances with 20 and 50 periods of activity, respectively, besides there are the following files input_small_scale_d1t20 until input_small_scale_d5t50. In each file you will find information about the number of periods of network activity, the number of demands, the sensor node and the period in which the data was sensed, the shortest paths and the number of shortest paths of these nodes.

### For large-scale

For large-scale instances use the file input_large_scale.h and uncomment the network namely LARGE_SCALE_NETWORK and then one of the 4 demands and one of the 4 periods you prefer, thus combining demand and period you will have a large-scale instance.

Just as in the small-scale network, below these options you will find the number of nodes, the initial energy value of the nodes, adjacency lists, the size of each list and also information about the periods of network activity.

Large-scale instances have 4 initial demands declared in the following files input_large_scale_d84.h until input_large_scale_d148. In each file you will find the number of demands, sensor node and period in which data was sensed, the shortest paths and the number of the shortest paths of these nodes.

After defining the parameters and selecting the instance, you should access the file nsga2r.c, from line 13 to 23 for the small-scale network and on lines 25 to 29 for the large-scale network, and uncomment the names of the include files network and demand previously selected. You are ready to run it once this is done.


# Output files

The algorithm creates 5 output files with information about the solutions.

- initial_pop.out: This file contains all the information about the initial population.
- final_pop.out: This file contains the data of the final population.
- all_pop.out: This file contains the data of populations at every generation defined by you in - REPORT_EVERY_GEN.
- best_pop.out: This file contains the best solutions (Pareto front) obtained at the end of the simulation run.
- params.out: This file contains information about input parameters.




# About files

- global.h: Header file containing declaration of global variables and functions
- input_.h: Header file containing all instances information about problem
- rand.h: Header file containing declaration of variables and functions for random number generator
- allocate.c: Memory allocation and deallocation routines
- auxiliary.c: Auxiliary routines (not part of the algorithm)
- crossover.c: Crossover routines
- crowddist.c: Crowding distance assignment routines
- dominance.c: Routine to perform non-domination checking
- eval.c: Routine to evaluate constraint violation
- fillnds.c: Non-dominated sorting based selection
- initialize.c: Routine to perform random initialization to population members
- list.c: A custom doubly linked list implementation
- merge.c: Routine to merge two population into one larger population
- mutation.c: Mutation routines
- nsga2r.c: Implementation of main function and the proposed algorithm based on NSGA-II framework
- problemdef.c: Problem definitions
- rand.c: Random number generator related routines
- rank.c: Rank assignment routines
- regenerate.c: Routine to regenerate population
- repair.c: Routine to repair population
- report.c: Routine to write the population information in a file
- sort.c: Randomized quick sort implementation
- tourselect.c: Tournament selection routine