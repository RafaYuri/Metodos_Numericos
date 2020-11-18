//================================================================
// Metodo de Newton
//================================================================

double mn ( double T, double P, double V )
{
    int k, max_int ;
    double V_old, erro, tol ;

    k = 0 ;
    max_int = 200 ;
    erro = 1 ;
    tol = 1e-8 ;

    while ( erro > tol )
    {
        V_old = V ;
        V -= eqvdw ( T, P, V ) / deqvdw ( T, P, V ) ;
        erro = pow ( V - V_old, 2 ) ;
        erro = sqrt ( erro ) ;

        k++ ;
        if ( k > max_int )
            break ;
    }
    return V ;
}
