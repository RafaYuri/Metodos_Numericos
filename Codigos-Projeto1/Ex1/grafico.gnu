set size square
set grid lw 1.5
set xlabel "Pr" font "Arial,12"
set ylabel "Z" font "Arial,12"
set border
set term png size 800,800 enhanced font "Arial,12"
set output "ZxPr.png"
plot "ZxPr.dat" u 1:2 w lp pointtype 7 pointsize 1.5 lt rgb "black" lw 2
