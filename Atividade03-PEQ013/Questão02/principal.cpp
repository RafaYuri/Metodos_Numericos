//===========================================================================
// Universidade Federal de Uberlandia
// Faculdade de Engenharia Quimica
// Metodos Numericos Aplicados a Engenharia Quimica

// Determinacao de concentracoes de equilibrio

// Implementado por Rafael Yuri Medeiros Barbosa
//===========================================================================

// Bibliotecas
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <vector>

// Definicao do padrao do C++
using namespace std ;

// Defnicao de tipos
typedef vector <double> v1d ;

// Definicao de constantes
const double tol = 1e-8 ;
const int N_MAX = 400 ;

// Subrotinas
#include "subrotinas/input.cpp"
#include "subrotinas/gradiente.cpp"
#include "subrotinas/norma_vec.cpp"
#include "subrotinas/linesearch.cpp"
#include "subrotinas/gradiente_descendente.cpp"

// Main
int main ( )
{
    // Declaracao de variaveis
    v1d vx ( 7 ) ;
    double kc1, kc2, kc3, ca0, cb0 ;

    // Atribuicao de valores
    kc1 = 1.06 ;
    kc2 = 2.63 ;
    kc3 = 5 ;
    ca0 = cb0 = 1.5 ;

    for ( int i = 0 ; i < vx.size (); i++ )
    {
        vx [ i ] = ( ca0 + cb0 ) / 7 ;
    }

    // Obtencao das raizes pelo metodo do gradiente descendente
    mgd ( vx, kc1, kc2, kc3, ca0, cb0 ) ;

    for ( int i = 0 ; i < vx.size (); i++ )
    {
        cout << "C" << i << " = " << vx [ i ] << endl ;
    }

    // Fim do programa
    return 0 ;
}
