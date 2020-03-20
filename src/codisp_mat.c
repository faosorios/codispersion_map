#include "codisp_map.h"

SEXP
hcodisp_map_lattice(SEXP Rxmat, SEXP Rymat)
{
    int i, N, M, ndirections, maxdim, nc;
    SEXP list, list_names, directions, coefs, dims;
    double *xmat, *ymat;
    
    Rxmat = coerceVector(Rxmat, REALSXP);
    Rymat = coerceVector(Rymat, REALSXP);
    
    char *names[2] = {"directions", "coefficients"};
    PROTECT(list_names = allocVector(STRSXP, 2));
    
    for (i = 0; i < 2; i ++)
        SET_STRING_ELT(list_names, i, mkChar(names[i]));
    
    /* Creating a list with 2 vector elements */
    PROTECT(list = allocVector(VECSXP, 2));
    
    dims = getAttrib(Rxmat, R_DimSymbol);
    N = INTEGER(dims)[0];
    M = INTEGER(dims)[1];
    maxdim = MAX(N, M);
    xmat = REAL(Rxmat);
    ymat = REAL(Rymat);
    
    directions = generateDirections(N, M, 1.0 ,maxdim, &ndirections, &nc);
    
    coefs = calculateCoefficients(xmat, ymat, directions, N, M, ndirections, nc);
    
    /* attaching directions array to list */
    SET_VECTOR_ELT(list, 0, directions);
    
    /* attaching coefs array to list */
    SET_VECTOR_ELT(list, 1, coefs);
    
    /* and attaching the symbol names */
    setAttrib(list, R_NamesSymbol, list_names);
    
    UNPROTECT(4);
    
    return list;
}
