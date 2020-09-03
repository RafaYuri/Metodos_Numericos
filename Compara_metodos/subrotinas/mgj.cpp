// Metodo de Gauss-Jacobi
void mgj ( vd2 ma, vd1 vb, vd1 &x )
{
    int n, k ;
    double erro, soma ;

    n = vb.size ( ) ;

    vd1 xold ( n ) ;

    // Aplicacao do metodo
    erro = 1 ;
    k = 0 ;
    while ( erro > tol and k < n_max )
    {
        // Igualando x e xold
        xold = x ;
        for ( int i = 0 ; i < n ; i++ )
        {
            soma = 0 ;
            for ( int j = 0 ; j < n ; j++ )
            {
                if ( j != i )
                {
                    soma += ma [ i ] [ j ] * xold [ j ] ;
                }
            }
            x [ i ] = ( vb [ i ] - soma ) / ma [ i ] [ i ] ;
        }
        erro = nl2 ( x, xold ) ;
        k++ ;
        //cout << erro << "\t" << k << endl ;
    }
}
