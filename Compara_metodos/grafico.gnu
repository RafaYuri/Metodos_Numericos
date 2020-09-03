set size square
set grid lw 1.5
set xlabel "Size" font "Arial,12"
set ylabel "Time [s]" font "Arial,12"
set key box
set key font "Arial,10"
set key bottom
set logscale y
set border
set term png size 800,800 enhanced font "Arial,12"
set output "tempos.png"
plot "tempos.dat" u 1:2 t "NP" w lp pointtype 7 pointsize 1.5 lt rgb "black" lw 2,"tempos.dat" u 1:3 t "MEGPP" w l lt rgb "magenta" lw 2,"tempos.dat" u 1:4 t "MGJ" w l lt rgb "cyan" lw 2,"tempos.dat" u 1:5 t "MGS" w l lt rgb "brown" lw 2,"tempos.dat" u 1:6 t "SOR w=0.5" w l lt rgb "blue" lw 2,"tempos.dat" u 1:7 t "SOR w=0.9" w l lt rgb "red" lw 2,"tempos.dat" u 1:8 t "SOR w=1.5" w l lt rgb "yellow" lw 2
