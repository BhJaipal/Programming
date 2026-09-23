#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/// NOTE: compile with sort_algo.c

int count_derange(int *arr, int n)
{
    int degranged = 0;
    for (int i = 0; i < n; i++) {
        if (i != n - 1 && arr[i] > arr[i + 1]) {
            degranged++;
        } else {
            degranged--;
        }
    }
    return degranged;
}
void print_derange(int *arr, int n)
{
    printf("\e[93m[");
    int degranged = 0;
    for (int i = 0; i < n; i++) {
        if (i != n - 1 && arr[i] > arr[i + 1]) {
            printf("\e[91m");
            degranged++;
        } else {
            printf("\e[92m");
            degranged--;
        }
        printf("█");
    }
    printf("\e[93m]\e[0m degranged: %d\n", degranged);
}

int radix_sort(int arr[], int n, void *, void *);
int selection_sort(int arr[], int n, void *, void *);
int bubble_sort(int arr[], int n, void *, void *);
int insertion_sort(int arr[], int n, void *, void *);
int quick_sort(int arr[], int start, int end, int n, void *, void *);
int merge_sort(int arr[], int left, int right, int n, void *, void *);

typedef enum { QUICK, BUBBLE, SELECTION, INSERTION, RADIX, MERGE } algo_type_t;

typedef enum { BEST, MID, WORST } algo_rank_t;

void escape_rank(algo_rank_t rank)
{
    switch (rank) {
    case BEST:
        printf("\e[92m");
        break;
    case MID:
        printf("\e[38;5;226m");
        break;
    case WORST:
        printf("\e[38;5;202m");
        break;
    }
}

typedef struct {
    algo_type_t type;
    algo_rank_t rank;
    time_t duration;
    int swaps;
} algo_t;

void init(algo_t *algorithms, int algo_n, ...);
void race(algo_t *algorithms, int algo_n, int n, int mod);

/// NOTE: compile with sort_algo.c
int main()
{
    srand(time(NULL));
    int algo_n = 5;
    algo_t algorithms[algo_n] = {};

    init(algorithms, algo_n, SELECTION, QUICK, MERGE, INSERTION,
         RADIX /*, BUBBLE*/);
    for (int i = 0; i < 5; i++) {
        race(algorithms, algo_n, 25, 100);
    }
    for (int i = 0; i < 5; i++) {
        race(algorithms, algo_n, 50, 100);
    }
    for (int i = 0; i < 5; i++) {
        race(algorithms, algo_n, 75, 200);
    }
    for (int i = 0; i < 10; i++) {
        race(algorithms, algo_n, 100, 400);
    }
    for (int i = 0; i < 10; i++) {
        race(algorithms, algo_n, 2048, 4096);
    }
    for (int i = 0; i < 10; i++) {
        race(algorithms, algo_n, 4096, 0x4000);
    }
}

int get_algorithm(algo_type_t type, int *arr, int n)
{
    switch (type) {
    case QUICK:
        return quick_sort(arr, 0, n, n, NULL, NULL);
        break;
    case SELECTION:
        return selection_sort(arr, n, NULL, NULL);
        break;
    case INSERTION:
        return insertion_sort(arr, n, NULL, NULL);
        break;
    case BUBBLE:
        return bubble_sort(arr, n, NULL, NULL);
        break;
    case RADIX:
        return radix_sort(arr, n, NULL, NULL);
        break;
    case MERGE:
        return merge_sort(arr, 0, n - 1, n, NULL, NULL);
        break;
    }
}

void print_centered(int max_w, long val)
{
    char data[11] = "";
    int n_len = sprintf(data, "%ld", val);
    printf("%*s%ld%*s", max_w / 2 - n_len / 2 - (n_len % 2), "", val,
           max_w / 2 - n_len / 2, "");
}
void init(algo_t *algorithms, int algo_n, ...)
{
    va_list args;
    va_start(args, algo_n);
    printf("  Algorithms  ");
    for (int i = 0; i < algo_n; i++) {
        algorithms[i].type = va_arg(args, int);
        algorithms[i].rank = MID;
        printf("│       ");
        switch (algorithms[i].type) {
        case QUICK:
            printf("  Quick  ");
            break;
        case SELECTION:
            printf("Selection");
            break;
        case INSERTION:
            printf("Insertion");
            break;
        case BUBBLE:
            printf(" Bubble  ");
            break;
        case RADIX:
            printf("  Radix  ");
            break;
        case MERGE:
            printf("  Merge  ");
            break;
        }
        printf("        ");
    }
    va_end(args);
    printf("\n");
    printf("  Data size   ");
    for (int i = 0; i < algo_n; i++) {
        printf("│    Time      Swaps     ");
    }
    printf("\n──────────────");
    for (int i = 0; i < algo_n; i++) {
        printf("┼────────────────────────");
    }
    printf("\n");
}

/**
 * @out @algorithms algorithms info
 * @in @n array size
	*/
void run_algo(algo_t *algorithms, int n, int *data, int *reset)
{
    time_t start = clock();
    algorithms[0].swaps = get_algorithm(algorithms[0].type, data, n);
    time_t end = clock();
    algorithms[0].duration = end - start;
    for (int i = 0; i < n; i++) {
        data[i] = reset[i];
    }
}
void start_race(algo_t *algorithms, int algo_n, int n, int *sort, int *reset)
{
    printf("  ");
    char data[11] = "";
    print_centered(10, n);
    printf("  ");
    for (int i = 0; i < algo_n; i++) {
        run_algo(algorithms + i, n, sort, reset);
        algorithms[i].rank = MID;
    }
    int best_r = 0, worst_r = 0;
    for (int i = 0; i < algo_n; i++) {
        if (algorithms[i].duration > algorithms[worst_r].duration) {
            worst_r = i;
        }
        if (algorithms[i].duration < algorithms[best_r].duration) {
            best_r = i;
        }
    }
    algorithms[worst_r].rank = WORST;
    algorithms[best_r].rank = BEST;
    for (int i = 0; i < algo_n; i++) {
        printf("│  ");
        escape_rank(algorithms[i].rank);
        print_centered(10, algorithms[i].duration * 1000000 / CLOCKS_PER_SEC);
        print_centered(10, algorithms[i].swaps);
        printf("\e[0m  ");
    }
    printf("\n");
}
void race(algo_t *algorithms, int algo_n, int n, int mod)
{
    if (n <= 4096) {
        int arr[n];
        int arr2[n];
        for (int i = 0; i < n; i++) {
            int val = rand() % mod;
            arr[i] = val;
            arr2[i] = val;
        }
        start_race(algorithms, algo_n, n, arr, arr2);
    }
}
