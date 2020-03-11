/* This file contains the variable and function declarations */

# ifndef _GLOBAL_H_
# define _GLOBAL_H_

# define INF 1.0e14
# define EPS 1.0e-14
# define E  2.71828182845905
# define PI 3.14159265358979


# include <stdbool.h>


typedef struct
{
    int rank;
    double constr_violation;
    int *xreal;
    int *xreal_copia;
    int **gene;
    double *xbin;
    double *obj;
    double *constr;
    double crowd_dist;
}
individual;

typedef struct
{
    individual *ind;
}
population;

typedef struct lists
{
    int index;
    struct lists *parent;
    struct lists *child;
}
list;

extern int nreal;
extern int nobj;
extern int ncon;
extern int popsize;
extern double pcross_real;
extern double pmut_real;
extern int ngen;
extern int nrealmut;
extern int nrealcross;
extern int obj1;
extern int obj2;


extern const float SEED;
extern const unsigned int POPSIZE;
extern const unsigned int NGEN;
extern const float PCROSS;
extern const float PMUT;
extern const float PADD_NODE;
extern const unsigned char NOBJ;
extern const unsigned char ALL_POP_WITH_PATH;
extern const unsigned short T;
extern const unsigned short N;
extern const unsigned short DEMANDA_MAX;
extern const unsigned short energia_inicial;
extern const unsigned short adj_list[][25];
extern const unsigned short adj_list_size[];
extern const unsigned short source_demanda[][2];
extern const unsigned short min_paths[][100][16];
extern const unsigned short min_paths_size[];

void allocate_memory_pop (population *pop, int size);
void allocate_memory_ind (individual *ind);
void deallocate_memory_pop (population *pop, int size);
void deallocate_memory_ind (individual *ind);

double maximum (double a, double b);
double minimum (double a, double b);

void crossover (individual *parent1, individual *parent2, individual *child1, individual *child2);
void pathcross (individual *parent1, individual *parent2, individual *child1, individual *child2);

void assign_crowding_distance_list (population *pop, list *lst, int front_size);
void assign_crowding_distance_indices (population *pop, int c1, int c2);
void assign_crowding_distance (population *pop, int *dist, int **obj_array, int front_size);

int check_dominance (individual *a, individual *b);

void evaluate_pop (population *pop);
void evaluate_ind (individual *ind);

void fill_nondominated_sort (population *mixed_pop, population *new_pop);
void crowding_fill (population *mixed_pop, population *new_pop, int count, int front_size, list *cur);

void initialize_pop (population *pop);
void initialize_ind (individual *ind);
void add_node_min_path (individual *ind);

void insert (list *node, int x);
list* del (list *node);

void merge(population *pop1, population *pop2, population *pop3);
void copy_ind (individual *ind1, individual *ind2);

void mutation_pop (population *pop);
void mutation_ind (individual *ind);

void network_problem (int *xreal, double *obj, double *constr);

void assign_rank_and_crowding_distance (population *new_pop);

void report_pop (population *pop, FILE *fpt);
void report_feasible (population *pop, FILE *fpt);

void quicksort_front_obj(population *pop, int objcount, int obj_array[], int obj_array_size);
void q_sort_front_obj(population *pop, int objcount, int obj_array[], int left, int right);
void quicksort_dist(population *pop, int *dist, int front_size);
void q_sort_dist(population *pop, int *dist, int left, int right);

void selection (population *old_pop, population *new_pop);
individual* tournament (individual *ind1, individual *ind2);

int find_neighbor(int no1, int no2, int no_atual);
int check_neighbor(int no_i, int no_j);
int check_initial_demand(int no_i, int t);
int find_value(short numero, short vetor[], short tamanho_vetor);

void repair_collision_concurrent(individual *ind);
void regenerate_pop (population *pop);
void regenerate_ind(individual *ind);
void avoid_collision_sink(individual *ind);

void evaluate_metrics(population* pop, FILE* fpt);
        
# endif