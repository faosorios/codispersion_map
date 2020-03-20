hcodisp.map <-
function(x, y, plot.it = TRUE)
{
    require ("akima")
    require ("fields")

    x <- as.matrix(x)
    y <- as.matrix(y)

    if (!is.numeric(x)) stop("'x' must be a numeric matrix")
    if (!is.numeric(y)) stop("'y' must be a numeric matrix")
    if (nrow(x) != nrow(y)) stop(" Number of rows must be equal")
    if (ncol(x) != ncol(y)) stop(" Number of columns must be equal")

    now <- proc.time()
    z <- .Call("hcodisp_map_lattice", x, y)
    speed <- proc.time() - now

    if (plot.it) {
        image.plot(seq(1, nrow(z$coef)), seq(1, ncol(z$coef)), z$coef,
                   main = "Codispersion Map", xlab = "x", ylab = "y",
                   col = topo.colors(256))
    }

    invisible(list(map = z, speed = speed))
}
