codisp.map <-
function(x, y, coords, nclass = 13, ncell = 40, plot.it = TRUE)
{
    require("akima")
    require("fields")
    require("geoR")
    rho <- function(x, y, uvec, max.dist, angle)
    {
	z <- as.geodata(cbind(x$coords, x$data + y$data))
	nz <- variog(z, uvec = uvec, max.dist = max.dist, direction = angle, messages = FALSE)
	dx <- variog(x, uvec = uvec, max.dist = max.dist, direction = angle, messages = FALSE)
	dy <- variog(y, uvec = uvec, max.dist = max.dist, direction = angle, messages = FALSE)
	rho <- .5 * (nz$v - dx$v - dy$v) / sqrt(dx$v * dy$v)
    }

    x <- as.geodata(cbind(coords, x))
    y <- as.geodata(cbind(coords, y))
    dmax <- .5 * max(dist(coords))
    angles <- seq(from = 0, to = pi, by = 0.01)
    nangles <- length(angles)
    uvec <- seq(from = 0, to = dmax, length = nclass + 1)[-1]

    xcirc <- 0
    ycirc <- 0

    for (i in seq_len(nclass)) {
	xcirc[(nangles*(i-1)+1):(nangles*i)] <- seq(-uvec[i], uvec[i], length = nangles)
	ycirc[(nangles*(i-1)+1):(nangles*i)] <- sqrt(uvec[i]^2 - xcirc[(nangles*(i-1)+1):(nangles*i)]^2)
    }
    z <- matrix(0, nrow = nangles, ncol = nclass)
    for (i in seq_len(nangles))
	z[i,] <- rho(x, y, uvec = uvec, max.dist = dmax, angle = angles[i])
    z <- as.vector(z)
    xl <- seq(min(xcirc), max(ycirc), length=ncell)
    yl <- seq(min(ycirc), max(ycirc), length=ncell)

    if (plot.it) {
	par(pty = "s")
	image.plot(interp(xcirc, ycirc, as.vector(z), xo = xl,yo = yl), col = topo.colors(256),
		   xlab = "x", ylab = "y")
	title(main = "Codispersion Map")
    }

    invisible(list(xcirc = xcirc, ycirc = ycirc, z = z))
}
