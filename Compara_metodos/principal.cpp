//==================================================================================
// Universidade Federal de Uberlandia
// Faculdade de Engenharia Química
// Metodos Numericos Aplicados a Engenharia Quimica
// Rafael Yuri Medeiros Barbosa
// Comparacao de metodos de resolucao de sistemas lineares com numpy.solve
//==================================================================================

// Bibliotecas
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <ctime>

// Definicao do padrao do C++
using namespace std ;

// Definicao de tipos
typedef vector <double> vd1 ;
typedef vector <vector<double>> vd2 ;

// Definicao de constantes
const double tol = 1e-8 ;
const int n_max = 1000000 ;

// Subrotinas
#include "subrotinas/megpp.cpp"
#include "subrotinas/subsreg.cpp"
#include "subrotinas/nl2.cpp"
#include "subrotinas/mgj.cpp"
#include "subrotinas/mgs.cpp"
#include "subrotinas/sor.cpp"

// Main
int main ( )
{
    // Variavel tempo
    clock_t tp ;

    // Vetor de tamanhos
    vector <int> tamanho = {10, 50, 100, 1000} ;

    // Vetores de tempo
    vd1 tmegpp ;
    vd1 tmgj ;
    vd1 tmgs ;
    vd1 tsor050 ;
    vd1 tsor090 ;
    vd1 tsor150 ;

    // Definicao da semente para geracao de numeros aleatorios
    srand ( 10 ) ;

    // Iniciando geracao e resolucao dos sistemas
    for ( int k = 0 ; k < tamanho.size ( ) ; k++ )
    {
        // Inicializacao de vetores
        vd2 ma ( tamanho [ k ], vd1 ( tamanho [ k ] ) ) ;
        vd1 vb ( tamanho [ k ] ) ;
        vd1 x ( tamanho [ k ] , 0 ) ;

        // Preenchimento com numeros aleatorios
        for ( int i = 0 ; i < tamanho [ k ] ; i++ )
        {
            for ( int j = 0 ; j < tamanho [ k ] ; j++ )
            {
                ma [ i ] [ j ] = (double) rand ( ) ;
            }
        }

        for ( int i = 0 ; i < tamanho [ k ] ; i++ )
        {
            vb [ i ] = (double) rand ( ) ;
        }

        // Metodo da Eliminacao de Gauss com Pivoteamento Parcial
        tp = clock ( ) ;
        megpp ( vb, ma ) ;
        subsreg ( ma, vb, x ) ;
        tp = clock ( ) - tp ;
        tmegpp.push_back ( tp / (double) CLOCKS_PER_SEC ) ;

        // Metodo de Gauss-Jacobi
        x.resize ( tamanho [ k ], 0 ) ;
        tp = clock ( ) ;
        mgj ( ma, vb, x ) ;
        tp = clock ( ) - tp ;
        tmgj.push_back ( tp / (double) CLOCKS_PER_SEC ) ;

        // Metodo de Gauss-Seidel
        x.resize ( tamanho [ k ], 0 ) ;
        tp = clock ( ) ;
        mgs ( ma, vb, x ) ;
        tp = clock ( ) - tp ;
        tmgs.push_back ( tp / (double) CLOCKS_PER_SEC ) ;

        // SOR para w = 0.5
        x.resize ( tamanho [ k ], 0 ) ;
        tp = clock ( ) ;
        sor ( ma, vb, x, 0.5 ) ;
        tp = clock ( ) - tp ;
        tsor050.push_back ( tp / (double) CLOCKS_PER_SEC ) ;

        // SOR para w = 0.9
        x.resize ( tamanho [ k ], 0 ) ;
        tp = clock ( ) ;
        sor ( ma, vb, x, 0.9 ) ;
        tp = clock ( ) - tp ;
        tsor090.push_back ( tp / (double) CLOCKS_PER_SEC ) ;

        // SOR para w = 1.5
        x.resize ( tamanho [ k ], 0 ) ;
        tp = clock ( ) ;
        sor ( ma, vb, x, 1.5 ) ;
        tp = clock ( ) - tp ;
        tsor150.push_back ( tp / (double) CLOCKS_PER_SEC ) ;
    }

    // Leitura dos tempos do numpy.solve
    fstream arq ( "numpy_solve.dat", ios::in ) ;
    vd1 nps ( tamanho.size ( ) ) ;
    for ( int i = 0 ; i < tamanho.size ( ) ; i++ )
    {
        arq >> nps [ i ] ;
    }
    arq.close ( ) ;

    // Escrita dos tempos em arquivo
    arq.open ( "tempos.dat", ios::in | ios::out | ios::trunc ) ;
    arq << fixed ;
    for ( int i = 0 ; i < tamanho.size ( ) ; i++ )
    {
        arq << tamanho [ i ] << "\t" ;
        arq << nps [ i ] << "\t" ;
        arq << tmegpp [ i ] << "\t" ;
        arq << tmgj [ i ] << "\t" ;
        arq << tmgs [ i ] << "\t" ;
        arq << tsor050 [ i ] << "\t" ;
        arq << tsor090 [ i ] << "\t" ;
        arq << tsor150 [ i ] << endl ;
    }
    arq.close ( ) ;

    // Plotagem
    arq.open ( "grafico.gnu", ios::in | ios::out | ios::trunc ) ;
    arq << "set size square" << endl ;
    arq << "set grid lw 1.5" << endl ;
    arq << "set xlabel \"Size\" font \"Arial,12\""<< endl ;
    arq << "set ylabel \"Time [s]\" font \"Arial,12\""<< endl ;
    arq << "set key box" << endl ;
    arq << "set key font \"Arial,10\"" << endl ;
    arq << "set key bottom" << endl ;
    arq << "set logscale y" << endl ;
    arq << "set border" << endl ;
    arq << "set term png size 800,800 enhanced font \"Arial,12\"" << endl ;
    arq << "set output \"tempos.png\"" << endl ;
    arq << "plot \"tempos.dat\" u 1:2 t \"NP\" w lp pointtype 7 pointsize 1.5 lt rgb \"black\" lw 2,";
    arq << "\"tempos.dat\" u 1:3 t \"MEGPP\" w l lt rgb \"magenta\" lw 2,";
    arq << "\"tempos.dat\" u 1:4 t \"MGJ\" w l lt rgb \"cyan\" lw 2,";
    arq << "\"tempos.dat\" u 1:5 t \"MGS\" w l lt rgb \"brown\" lw 2,";
    arq << "\"tempos.dat\" u 1:6 t \"SOR w=0.5\" w l lt rgb \"blue\" lw 2,";
    arq << "\"tempos.dat\" u 1:7 t \"SOR w=0.9\" w l lt rgb \"red\" lw 2,";
    arq << "\"tempos.dat\" u 1:8 t \"SOR w=1.5\" w l lt rgb \"yellow\" lw 2" << endl ;

    arq.close ( ) ;

    system ( "gnuplot grafico.gnu" ) ;


    // Fim do programa
    return 0 ;
}



