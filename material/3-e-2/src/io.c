#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

double* read_points(FILE *f, int *n_out, int *d_out) {
    int read;
    int n; 
    int d;

    // reads n from nXd matrix from file
    read = fread(&n, sizeof(int), 1, f);
    if (read != 1) {
      return NULL;
    }

    // reads d from nXd matrix from file   
    read = fread(&d, sizeof(int), 1, f);
    assert(read == 1);

    double* matrix = malloc(n * d * sizeof(double));

    read = fread(matrix, d*sizeof(double), n, f);

    *n_out = n;
    *d_out = d;
    return matrix;
    
    free(matrix);
}

/*
int* read_indexes(FILE *f, int *n_out, int *k_out) {

}

int write_points(FILE *f, int32_t n, int32_t d, double *data) {
  assert(0);
}

int write_indexes(FILE *f, int32_t n, int32_t k, int *data) {
  assert(0);
}
*/
