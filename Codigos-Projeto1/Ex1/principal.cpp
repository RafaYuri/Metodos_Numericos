//================================================================
// Universidade Federal de Uberlandia
// Faculdade de Engenharia Quimica
// Determinacao do volume molar da amonia a partir da equacao
// de van der Waals

// Autor: Rafael Yuri Medeiros Barbosa
//================================================================

// Bibliotecas
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <fstream>

// Padrao do C++
using namespace std ;

// Subrotinas
#include "subrotinas/parametros.cpp"
#include "subrotinas/funcoes.cpp"
#include "subrotinas/mnewton.cpp"
#include "subrotinas/grafico.cpp"

// int main
int main ( )
{
    // Declaracao de variaveis
    double P, T, V, Z;
    vector <double> Pr { 1, 2, 4, 10, 20} ;

    // Item 1
    P = 56 ;
    T = 450 ;

    // Chute de V
    V = R * T / P ;

    // Metodo de Newton
    V = mn ( T, P, V ) ;

    // Fator de compressibilidade
    Z = fcompressibilidade ( P, V, T ) ;

    // Resultados
    cout << " P = " << P << " : " << endl ;
    cout << "Volume molar: V = " << V << endl ;
    cout << "Fator de compressibilidade: Z = " << Z << endl ;

    // Item 2
    fstream arq ( "ZxPr.dat", ios::in | ios::out | ios::trunc ) ;
    for ( int i = 0 ; i < Pr.size ( ); i++ )
    {
        P = Pr [ i ] * Pc ;

        // Chute de V
        V = R * T / P ;

        // Metodo de Newton
        V = mn ( T, P, V ) ;

        // Fator de compressibilidade
        Z = fcompressibilidade ( P, V, T ) ;

        // Resultados
        cout << endl ;
        cout << "Pr = " << Pr [ i ] << " : " << endl ;
        cout << "Volume molar: V = " << V << endl ;
        cout << "Fator de compressibilidade: Z = " << Z << endl ;
        arq << Pr [ i ] << "\t" << Z << endl ;
    }
    arq.close () ;

    // Geracao de grafico de Z x Pr
    graf ( ) ;

    return 0 ;
}

