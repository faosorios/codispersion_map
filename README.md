# Codispersion Map for Rectangular Grids

The codispersion coefficient quantifies the association between two spatial processes for a particular direction (spatial lag) on the two-dimensional space. The R function **hcodisp.map** provides a graphical tool called codispersion map to visualize the spatial correlation between two sequences measured for regular lattices on the plane.

Authors: Diego Mancilla and Felipe Osorio

Maintainer: Felipe Osorio, Email: felipe.osorios@usm.cl

### Instructions: 
To create the Dynamically Loaded (DL) library, unpack the gzip file `hcodisp.map.tar.gz`, next using the console prompt move to the created directory and enter:

```shell
R CMD SHLIB -o hcodisp.so *.c
```

To use this funtion, start R and enter:

```shell
source("hcodisp.map.R")
dyn.load("hcodisp.so")
z <- hcodisp.map(x, y)
```

### Details:
License: GPL (>= 3)
Suggests: [SpatialPack](https://cran.r-project.org/package=SpatialPack)
Languages:	R, C

