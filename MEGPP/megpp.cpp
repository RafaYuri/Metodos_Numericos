//========================================================================
// Universidade Federal de Uberlandia
// Programa de Pos-Graduacao em Engenharia Quimica
// Metodos Numericos Aplicados a Engenharia Quimica
// Implementado por Rafael Yuri Medeiros Barbosa
// Metodo da Eliminacao de Gauss com Pivoteamento Parcial
// Resolucao Tambor Flash (Metano e Octano)
//========================================================================

// Bibliotecas
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>

// Definicao do padrao C++
using namespace std ;

// Definicao de tipos
typedef vector <double> vd1 ;
typedef vector <vector<double>> vd2 ;

// Metodo da eliminacao de Gauss com pivoteamento parcial
void megpp ( vd1 &vb, vd2 &ma )
{
    // Declaracao de variaveis
    int pos_max, n ;
    double m, pivo, baux ;

    // Alocacao de arrays
    n = vb.size ( ) ;
    vd1 vaux ( n ) ;

    // Pivoteamento e Eliminacao de Gauss
    for ( int k = 0 ; k < n - 1 ; k++ )
    {
        // Pivoteamento parcial de linhas
        pivo = fabs ( ma [ k ] [ k ] ) ;
        pos_max = k ;
        for ( int l = k + 1; l < n ; l++ )
        {
            if ( fabs ( ma [ l ] [ k ] ) > pivo )
            {
                pivo = fabs ( ma [ l ] [ k ] ) ;
                pos_max = l ;
            }
        }

        if ( pos_max != k )
        {
            vaux = ma [ k ] ;
            ma [ k ] = ma [ pos_max ] ;
            ma [ pos_max ] = vaux ;

            baux = vb [ k ] ;
            vb [ k ] = vb [ pos_max ] ;
            vb [ pos_max ] = baux ;
        }

        // Metodo da eliminacao de Gauss
        for ( int i = k + 1 ; i < n ; i++ )
        {
            m = ma [ i ] [ k ] / ma [ k ] [ k ] ;
            for ( int j = k ; j < n ; j++ )
            {
                ma [ i ] [ j ] -= ma [ k ] [ j ] * m ;
            }
            vb [ i ] -= vb [ k ] * m ;
        }
    }
}

// Resolucao do sistema por substituicoes regressivas
void subsreg ( vd2 ma, vd1 vb, vd1 &x )
{
    // Declaracao de variaveis
    int n ;
    double soma ;

    // Alocacao de arrays
    n = vb.size ( ) ;
    x.resize ( n ) ;

    // Metodo das substituicoes regressivas
    x [ n - 1 ] = vb [ n - 1 ] / ma [ n -1 ] [ n - 1 ] ;
    for ( int i = n - 2 ; i >= 0 ; i-- )
    {
        soma = 0 ;
        for ( int j = i + 1 ; j < n ; j++ )
        {
            soma += ma [ i ] [ j ] * x [ j ] ;
        }
        x [ i ] = ( vb [ i ] - soma ) / ma [ i ] [ i ] ;
    }
}

int main ( )
{
    // Declaracao de variaveis
    double zM, zO ;
    zM = 0.1 ;
    zO = 0.9 ;

    // Resolucao do sistema 1:
    vd2 A1 = { {1, 1, 0, 0}, {0, 0, 1, 1 }, {-220, 0, 1, 0}, {0, -0.3, 0, 1} } ;
    vd1 b1 = {1, 1, 0, 0} ;
    vd1 x1 ; // x1 = [x_M, x_O, y_M, y_O]

    // Eliminacao gaussiana com pivoteamento parcial
    megpp ( b1, A1 ) ;

    // Substituicoes regressivas
    subsreg ( A1, b1, x1 ) ;

    // Resolucao do sistema 2:
    vd2 A2 = { {x1 [ 2 ], x1 [ 0 ], -zM}, {x1 [ 3 ], x1 [ 1 ], -zO}, {0, 0, zM} } ;

    vd1 b2 = {0, 0, 10} ;
    vd1 x2 ; // x2 = [V, L, F]

    // Eliminacao gaussiana com pivoteamento parcial
    megpp ( b2, A2 ) ;

    // Substituicoes regressivas
    subsreg ( A2, b2, x2 ) ;

    // Impressao de resultados
    cout << fixed << setprecision ( 5 ) ;
    cout << "Sistema 1:" << endl ;
    for ( int i = 0 ; i < x1.size ( ); i++ )
    {
        cout << x1 [ i ] << endl ;
    }

    cout << endl << "Sistema 2:" << endl ;
    for ( int i = 0 ; i < x2.size ( ); i++ )
    {
        cout << x2 [ i ] << endl ;
    }

    // Fim do programa
    cout << endl << "Terminado!" << endl ;

    return 0 ;
}
