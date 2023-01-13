#include <sys/time.h>
#include <stdlib.h>

// Copied from exercise 6-1-e to time heat2d.py/heat-equation.c ... maybe
double seconds() {
  struct timeval tv;
  gettimeofday(&tv, NULL); // The null is for timezone information.
  return tv.tv_sec + tv.tv_usec/1000000.0;
}
