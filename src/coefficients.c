#include "codisp_map.h"

SEXP 
calculateCoefficients(double *xM, double *yM, SEXP h, int nrows, int ncols,
		      int ndir, int ncells)
{
    int k, n, R, l;
    SEXP out;
    h = coerceVector(h, INTSXP);
    
    PROTECT(out = allocMatrix(REALSXP, 2*ncells+1,ncells+1));
    
    n = 2 * ncells + 1;
    R = SQR(ncells);
    
    #pragma omp parallel for
    for (k = 0; k < ndir; k++) {
        int hx = INTEGER(h)[k];
	int hy = INTEGER(h)[k+ndir];
	int i = hx + ncells;
	int j = hy;
	int r = SQR(hx) + SQR(hy+1);
	if (r > R) {
            for (l = j + 1; l <= ncells; l++)
		REAL(out)[i + l*n] = NA_REAL;
	}
	REAL(out)[i + j*n] = hcod_coef(xM, yM, nrows, ncols, hx, hy);
    }

    REAL(out)[ncells] = 0.0;

    return out;
}

double
hcod_coef(double *xM, double *yM, int nrow, int ncol, int hx, int hy )
{
    double sx = 0.0, sy = 0.0, cross = 0.0;
    int i, j;
    double x, y, xh, yh;
    
    for (i = 0; i < nrow - hy; i++ ) {
	if (hx >= 0) {
            for (j = 0; j < ncol - hx; j++) {
		x = xM[i + nrow*j];
		y = yM[i + nrow*j];
		xh = xM[i + hy + (j + hx)*nrow];
		yh = yM[i + hy + (j + hx)*nrow];
		/* adds quantity only if both cells are non empty*/
		if (x != NA_REAL && xh != NA_REAL) {
		    cross += (x-xh)*(y-yh);
		    sx += (x-xh)*(x-xh);
		    sy += (y-yh)*(y-yh);
		}
            }
	}
	else {
            for (j = -hx; j < ncol; j++) {
		x = xM[i + nrow*j];
		y = yM[i + nrow*j];
		xh = xM[i + hy + (j + hx)*nrow];
		yh = yM[i + hy + (j + hx)*nrow];
		if (x != NA_REAL && xh != NA_REAL) {
		    cross += (x-xh)*(y-yh);
		    sx += (x-xh)*(x-xh);
		    sy += (y-yh)*(y-yh);
		}
            }
	}
    }
    
    if (sx != 0.0 && sy != 0.0) {
	return cross/SQRT(sx*sy);
    }
    else {
	return NA_REAL;
    }
}
