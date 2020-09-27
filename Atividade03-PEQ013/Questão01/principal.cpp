//===========================================================================
// Universidade Federal de Uberlandia
// Faculdade de Engenharia Quimica
// Metodos Numericos Aplicados a Engenharia Quimica

// Determinacao do volume especifico de uma substancia utilizando
// as equacoes de estado de Redlich-Kwong e Peng-Robinson

// Implementado por Rafael Yuri Medeiros Barbosa
//===========================================================================


// Bibliotecas
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

// Definicao do padrao do C++
using namespace std ;

// Definicao de constantes
const double R = 0.08206 ;
const double tol = 1e-8 ;
const int N_MAX = 200 ;


// Subrotinas
#include "subrotinas/input.cpp"
#include "subrotinas/eos.cpp"
#include "subrotinas/newton.cpp"

// Main
int main ( )
{
    // Declaracao de variaveis
    double T, P, Vrk, Vpr ;
    double Tc, Pc, w ;
    substancia nbutano ;

    // Entrada de dados
    Tc = 425.2 ;
    Pc = 37.5 ;
    w = 0.193 ;

    T = 500 ;
    P = 18 ;

    // Atribuicao de valores
    nbutano.setTc ( Tc ) ;
    nbutano.setPc ( Pc ) ;
    nbutano.setOmega ( w ) ;

    // Estimativa inicial para V
    Vrk = Vpr = R * T / P ;

    // Obtencao do volume
    Vrk = mnewton_rk ( nbutano, T, P, Vrk ) ;
    Vpr = mnewton_pr ( nbutano, T, P, Vpr ) ;

    cout << "Volume por Redlich-Kwong: V = " << Vrk << endl ;
    cout << "Volume por Peng-Robinson: V = " << Vpr << endl ;

    // Fim do programa
    return 0 ;
}
