// Calculo da norma L2 entre duas iteracoes consecutivas
double nl2 ( vd1 x1, vd1 x2 )
{
    int n ;
    double l2 ;

    n = x1.size ( ) ;

    // Calculo da norma
    l2 = 0 ;
    for ( int i = 0 ; i < n ; i++ )
    {
        l2 += pow ( x1 [ i ] - x2 [ i ], 2 ) ;
    }
    l2 = sqrt ( l2 ) ;
    return l2 ;
}
