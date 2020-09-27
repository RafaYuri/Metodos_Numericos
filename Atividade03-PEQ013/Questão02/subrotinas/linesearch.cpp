//===========================================================================
// Busca em linha utilizando o metodo de Newton
//===========================================================================

double ls ( v1d vx, v1d vg, double kc1, double kc2, double kc3, double ca0, double cb0 )
{
    double lbd, lbd_old, erro, eps ;
    double df1, df2 ;
    int cont ;
    v1d vxaux ( vx.size () ) ;

    // Definindo valores
    eps = 1e-5 ;

    // Estimativa inicial para lbd
    lbd = nl2 ( vg ) ;

    // Metodo de Newton
    erro = 1 ;
    cont = 0 ;
    while ( erro > tol and cont < N_MAX )
    {
        lbd_old = lbd ;

        // Calculo das derivadas primeira e segunda
        lbd += eps ;
        for ( int i = 0 ; i < vx.size() ; i++ )
        {
            vxaux [ i ] = vx [ i ] - vg [ i ] * lbd ;
        }

        df1 = fobj ( vxaux, kc1, kc2, kc3, ca0, cb0 ) ;
        df2 = fobj ( vxaux, kc1, kc2, kc3, ca0, cb0 ) ;

        lbd -= 2 * eps ;
        for ( int i = 0 ; i < vx.size() ; i++ )
        {
            vxaux [ i ] = vx [ i ] - vg [ i ] * lbd ;
        }
        df1 -= fobj ( vxaux, kc1, kc2, kc3, ca0, cb0 ) ;
        df2 += fobj ( vxaux, kc1, kc2, kc3, ca0, cb0 ) ;

        lbd += eps ;
        for ( int i = 0 ; i < vx.size() ; i++ )
        {
            vxaux [ i ] = vx [ i ] - vg [ i ] * lbd ;
        }

        df2 -= 2 * fobj ( vxaux, kc1, kc2, kc3, ca0, cb0 ) ;

        df1 /= 2 * eps ;
        df2 /= eps * eps ;

        // Metodo de Newton
        lbd -= df1 / df2 ;

        // Calculo do erro
        erro = sqrt ( pow ( lbd - lbd_old, 2 ) ) ;

        // Incrmento do contador
        cont++ ;
    }

    return lbd ;
}
