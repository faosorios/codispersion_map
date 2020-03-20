# Codispersion Map for Rectangular Grids

The codispersion coefficient quantifies the association between two spatial processes for a particular direction (spatial lag) on the two-dimensional space. The R function **hcodisp.map** provides a graphical tool called codispersion map to visualize the spatial correlation between two sequences measured for regular lattices on the plane.

Authors: Diego Mancilla and Felipe Osorio

Maintainer: Felipe Osorio, Email: felipe.osorios@usm.cl

### Instructions: 
To create the Dynamically Loaded (DL) library, unpack the gzip file `hcodisp.map.tar.gz`, next using the console prompt move to the created directory and enter:

`R CMD SHLIB -o hcodisp.so *.c`

Next, copy `SSIM.so` file to the working directory (in our case to `/case_study`), and execute the commands in `case_study.R` file (optionally, you can use `reading_TIF.R` to read data from TIF images. 'tif' R package is required).

To use this funtion, start R and enter:

`source("hcodisp.map.R")
 dyn.load("hcodisp.so")
 z <- hcodisp.map(x, y)`
