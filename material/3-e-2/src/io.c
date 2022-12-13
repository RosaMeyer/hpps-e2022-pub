#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

double* read_points(FILE *f, int *n_out, int *d_out) {
  int read;
  int n, d;

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


int* read_indexes(FILE *f, int *n_out, int *k_out) {
  int read;
  int n, k;

  read = fread(&n, sizeof(int), 1, f);
  assert(read == 1);

  double* index = malloc(n * k * sizeof(double));

  read = fread(index, k*sizeof(double), n, f);

  *n_out = n;
  *k_out = k;

  return index;

  free(index);
}



int write_points(FILE *f, int32_t n, int32_t d, double *data) {
  // Writes number of points
  if (fwrite(&n, sizeof(int32_t), 1, f) != 1) {
    return 1;
  }

  // Writes no. of values for each point (dimensionality).
  if (fwrite(&d, sizeof(int32_t), 1, f) != 1) {
    return 1; 
  }

  // Write the raw point data
  if ((int)fwrite(data, d * sizeof(double), n, f) != n) {
    return 1;
  }

  return 0;
}

int write_indexes(FILE *f, int32_t n, int32_t k, int *data) {
  // Writes no. of indexes
  if (fwrite(&n, sizeof(int32_t), 1, f) != 1) {
    return 1;
  }

  // Writes no. of values for each index (dimensionality)
  if (fwrite(&k, sizeof(int32_t), 1, f) != 1) {
    return 1;
  }

  // Write the raw index data
  if ((int)fwrite(data, k * sizeof(double), n ,f) != n) {
    return 1;
  }

  return 0;
}
