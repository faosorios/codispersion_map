#ifndef CODISP_MAP_H
#define CODISP_MAP_H

#include "base.h"

/* routines for computation of directional codispersion map */

extern SEXP hcodisp_map_lattice(SEXP, SEXP);
SEXP calculateCoefficients(double *, double *, SEXP, int, int, int, int);
double hcod_coef(double *, double *, int, int, int, int);
SEXP generateDirections(int, int, double, double, int *, int*);

#endif /* CODISP_MAP_H */
