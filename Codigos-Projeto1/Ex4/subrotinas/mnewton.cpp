//===============================================================
// Metodo de Newton
//===============================================================

double mnewton ( double vt )
{
    double vt_old, erro, tol ;
    int k, max_int ;

    erro = 1 ;
    tol = 1e-8 ;
    k = 0 ;
    max_int = 200 ;

    while ( erro > tol )
    {
        vt_old = vt ;
        vt -= velocidade_t ( vt ) / dvt ( vt ) ;

        erro = pow ( vt - vt_old, 2 ) ;
        erro = sqrt ( erro ) ;

        k++ ;
        if ( k > max_int )
        {
            break ;
        }
    }

    return vt ;
}
