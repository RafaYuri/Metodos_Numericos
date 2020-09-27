//===========================================================================
// Metodo do gradiente descendente
//===========================================================================

void mgd ( v1d &vx, double kc1, double kc2, double kc3, double ca0, double cb0 )
{
    // Declaracao de variaveis
    double erro, lambda ;
    int cont ;
    v1d vg ( vx.size () ) ;
    v1d vx_old ( vx.size () ) ;
    v1d verro ( vx.size () ) ;

    // Metodo do gradiente descendente
    erro = 1 ;
    cont = 0 ;
    while ( erro > tol and cont < N_MAX)
    {
        // Salvando valor antigo
        vx_old = vx ;

        // Calculo do gradiente
        vgrad ( vx, vg, kc1, kc2, kc3, ca0, cb0 ) ;

        // Verificando se gradiente e nulo
        if ( nl2 ( vg ) == 0 )
        {
            break ;
        }

        // Calculo do passo ideal
        lambda = ls ( vx, vg, kc1, kc2, kc3, ca0, cb0 ) ;

        // Atualizacao do valor de vx
        for ( int i = 0 ; i < vx.size () ; i++ )
        {
            vx [ i ] -= lambda * vg [ i ] ;

            verro [ i ] = vx [ i ] - vx_old [ i ] ;
        }

        // Calculo do erro
        erro = nl2 ( verro ) ;

        // Incremento do contador
        cont++ ;
    }
    cout << cont << endl ;
    cout << "Erro final = " << erro << endl ;

    if ( cont == N_MAX )
    {
        cout << "A tolerancia nao foi atingida!" << endl ;
    }
}
