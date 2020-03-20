#ifndef BASE_H
#define BASE_H

#include <R.h>
#include <Rmath.h>
#include <Rdefines.h>
#include <Rinternals.h>
#include <float.h>
#include <omp.h>
#include <math.h>
#include <stdbool.h>

/* some definitions */
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#define SQR(x)	 R_pow_di(x, 2)
#define SQRT(x)	 R_pow(x, 0.5);

#endif /* BASE_H */
