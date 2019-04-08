#include <stdio.h>
#include "omp.h"

int
main(int argc, char **argv)
{
  // single-threaded
  printf("Hi, just starting.\n");
  // start running multiple threads

  int thread_id = omp_get_thread_num();
  int n_threads = omp_get_num_threads();
#pragma omp parallel
 {
    printf("Hello %d/%d\n", thread_id, n_threads);
  }
  // back to single-threaded
  printf("just about done...\n");
}
