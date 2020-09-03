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
