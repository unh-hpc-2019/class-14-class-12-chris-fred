
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "linear_algebra.h"

static double
f(double x)
{
  return sqrt(1. - x*x);
}

int
main(int argc, char **argv)
{
  const int N = 10000;
  double dx = 1. / N;
    
   double tbeg = Wtime();
    double sum = 0.;
    

    
    
#pragma omp parallel for

  for (int i = 0; i < N; i++) {
    double x0 = i * dx;
    double x1 = (i+1) * dx;

    double val = .5 * (f(x0) + f(x1)) * dx;
 #pragma omp critical
      sum += val;
  }
    
        
  printf("four times the sum = %g\n", 4*sum);
    
    
double tend = Wtime();
    
    
    printf("It took %g seconds\n", tend-tbeg);
  return 0;
}
