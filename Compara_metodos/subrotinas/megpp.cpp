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
