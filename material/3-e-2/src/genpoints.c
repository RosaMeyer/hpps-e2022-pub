#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <time.h>

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <n> <d> <points>\n", argv[0]);
        exit(1);
    }

    // 'atoi' function converts a string to an integer
    int32_t n = atoi(argv[1]);
    int32_t d = atoi(argv[2]);

    FILE *f_points = fopen(argv[3], "w");
    assert(f_points != NULL);

    // The 'srand' function is used to initialize the random number generator 
    // with a seed value. The 'time' function is a built-in function that returns 
    // the current time, and the 'NULL' macro is a special null pointer constant.
    srand(time(NULL));

    // memory allocating
    double *data = malloc(n * d * sizeof(double));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            // using rand() to generate random number x in interval 0 to 1
            double x = ((double)rand())/RAND_MAX;
            data[i * d +j] = x;
        }
    }

    int error = write_points(f_points, n, d, data);
    assert(error == 0);

    fclose(f_points);
    free(data);

}
