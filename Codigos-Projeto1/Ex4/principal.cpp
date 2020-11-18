//===============================================================
// Universidade Federal de Uberlandia
// Faculdade de Engenharia Quimica

// Determinacao da velocidade terminal de uma particula de
// carvao

// Autor: Rafael Yuri Medeiros Barbosa
//===============================================================

// Bibliotecas
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>

// Definicao do padrao do C++
using namespace std ;

// Subrotinas
#include "subrotinas/parametros.cpp"
#include "subrotinas/funcoes.cpp"
#include "subrotinas/mnewton.cpp"

// int main
int main ( )
{
    double vt ;

    // Item 1

    // Aproximacao inicial ( Cd = 1 )
    vt = sqrt ( 4 * g * ( rho_p - rho ) * Dp / ( 3 * rho ) ) ;

    // Metodo de Newton
    vt = mnewton ( vt ) ;

    // Resultado
    cout << "a = 1 g" << endl ;
    cout << "Velocidade terminal: v_t = " << vt << endl ;

    // Item 2

    // a = 30 g
    g *= 30 ;

    // Aproximacao inicial ( Cd = 1 )
    vt = sqrt ( 4 * g * ( rho_p - rho ) * Dp / ( 3 * rho ) ) ;

    // Metodo de Newton
    vt = mnewton ( vt ) ;

    // Resultado
    cout << "a = 30 g" << endl ;
    cout << "Velocidade terminal: v_t = " << vt << endl ;


    return 0 ;

}
