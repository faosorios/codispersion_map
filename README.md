# Codispersion Map for Rectangular Grids

The codispersion coefficient quantifies the association between two spatial processes for a particular direction (spatial lag) on the two-dimensional space. The R function **hcodisp.map** provides a graphical tool called codispersion map to visualize the spatial correlation between two sequences measured for regular lattices on the plane.

Supplementary material to **The codispersion map: A graphical tool to visualize the association between two spatial variables.** by Ronny Vallejos, Felipe Osorio and Diego Mancilla (Statistica Neerlandica 69 (3), 298-314. DOI: [10.1111/stan.12060](https://doi.org/10.1111/stan.12060))

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
* License: GPL (>= 3)
* Suggests: [SpatialPack](https://cran.r-project.org/package=SpatialPack)
* Languages:	R, C

### Related information:
* [SpatialPack homepage](http://spatialpack.mat.utfsm.cl/)
* [Task View: Analysis of Spatial Data](http://cran.r-project.org/web/views/Spatial.html)

Partially supported by grants CONICYT 791100007 and UTFSM 12.12.05

