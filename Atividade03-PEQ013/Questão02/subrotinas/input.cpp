//===========================================================================
// Funcoes de entrada do problema
//===========================================================================

double fobj ( v1d vx, double kc1, double kc2, double kc3, double ca0, double cb0 )
{
    // Definicao de variaveis
    double fo ;
    v1d vf ( vx.size ( ) ) ;

    // Definicao das funcoes
    vf [ 0 ] = vx [ 2 ] * vx [ 3 ] - kc1 * vx [ 0 ] * vx [ 1 ] ;
    vf [ 1 ] = vx [ 4 ] * vx [ 5 ] - kc2 * vx [ 1 ] * vx [ 2 ] ;
    vf [ 2 ] = vx [ 6 ] - kc3 * vx [ 0 ] * vx [ 4 ] ;
    vf [ 3 ] = vx [ 0 ] - ca0 + vx [ 3 ] + vx [ 6 ] ;
    vf [ 4 ] = vx [ 1 ] - cb0 + vx [ 3 ] + vx [ 5 ] ;
    vf [ 5 ] = vx [ 2 ] - vx [ 3 ] + vx [ 5 ] ;
    vf [ 6 ] = vx [ 5 ] - vx [ 4 ] - vx [ 6 ] ;

    // Definicao da funcao objetivo
     fo = 0 ;
     for ( int i = 0 ; i < vf.size () ; i++ )
     {
         fo += pow ( vf [ i ], 2 ) ;
     }

     return fo ;
}
