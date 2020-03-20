#include "codisp_map.h"

SEXP
generateDirections(int  nrow, int  ncol, double d, double max_d, int *ndir, int *nc)
{
    int i, j, jlast, count, count2, ncells;
    double distance, radius = floor(max_d/3);
    SEXP out;
    
    ncells = (int) floor(2 * radius/d);
    
    if (ncells % 2 == 0) {
	ncells--;
    }
    
    ncells = (ncells - 1) / 2;
    *nc = ncells;
    
    int *ntiles = calloc(ncells+1, sizeof(int));
    
    count = 0;
    jlast = 0;
    
    for (i = -ncells; i <= 0; i++) {
	count += jlast;
	for (j = jlast; j < nrow; j++) {
            distance = hypot(j, (double) i);
	    if (distance <= ncells) {
		count = count + 1;
	    }
	    else {
		ntiles[i + ncells] = j;
		jlast = j;
		break;
	    }
	}
    }
    
    int aux = 2*count - ntiles[ncells];
    
    PROTECT(out = allocMatrix(INTSXP,aux,2));
    
    *ndir = aux;
    
    count2 = 0;
    for (i = -ncells; i <= ncells; i++) {
	if (i <= 0) {
            for (j = 0; j< ntiles[i+ncells]; j++) {
		INTEGER(out)[count2] = i;
		INTEGER(out)[count2+aux] = j;
		count2 += 1;
            }
	}
	else {
            for (j = 0; j< ntiles[ncells - i]; j++) {
		INTEGER(out)[count2] = i;
		INTEGER(out)[count2+aux] = j;
		count2 += 1;
            }
	}
    }
    
    Free(ntiles);
    return out; 
}
