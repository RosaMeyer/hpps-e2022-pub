#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <time.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <points> <indexes>\n", argv[0]);
        exit(1);
    }

    FILE *f_points = fopen(argv[1], "r");
    assert(f_points != NULL);

    FILE *f_indexes = fopen(argv[2], "r");
    assert(f_indexes != NULL);

    int n_p, d;
    double *points = read_points(f_points, &n_p, &d);
    assert(points != NULL);

    int n_i, k;
    int *indexes = read_indexes(f_indexes, &n_i, &k);
    assert(indexes != NULL);

    for (int i = 0; i < n_i; i++) {
        for (int j = 0; j < k; j++) {
            int x = indexes[i*k+j];
            if (x < 0 || x >= n_p) {
                printf("Invalid index: %d\n", x);
                exit(1);
        }
    }
    }

    free(points);
    free(indexes);

}
