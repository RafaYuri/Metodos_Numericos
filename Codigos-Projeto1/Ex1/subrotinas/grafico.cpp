//==================================================================
// Geracao de grafico
//==================================================================

void graf ( )
{
    // Plotagem
    fstream arq ( "grafico.gnu", ios::in | ios::out | ios::trunc ) ;
    arq << "set size square" << endl ;
    arq << "set grid lw 1.5" << endl ;
    arq << "set xlabel \"Pr\" font \"Arial,12\""<< endl ;
    arq << "set ylabel \"Z\" font \"Arial,12\""<< endl ;
    arq << "set border" << endl ;
    arq << "set term png size 800,800 enhanced font \"Arial,12\"" << endl ;
    arq << "set output \"ZxPr.png\"" << endl ;
    arq << "plot \"ZxPr.dat\" u 1:2 w lp pointtype 7 pointsize 1.5 lt rgb \"black\" lw 2" << endl ;
    arq.close ( ) ;

    system ( "gnuplot grafico.gnu" ) ;

}
