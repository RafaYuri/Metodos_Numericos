//===========================================================================
// Método de Newton
//===========================================================================

// Metodo de Newton para equacao de Redlich-Kwong
double mnewton_rk ( substancia s, double T, double P, double Vrk )
{
    // Declaracao de variaveis
    double Vrk_old, erro ;
    int cont = 0 ;

    // Inicio do loop ( Redlich
    erro = 1 ;
    while ( erro > tol and cont < N_MAX )
    {
        Vrk_old = Vrk ;
        Vrk -= erk ( P, T, Vrk, s ) / derk ( P, T, Vrk, s ) ;

        erro = pow ( Vrk - Vrk_old, 2 ) ;
        erro = sqrt ( erro ) ;
        cont++ ;
    }

    if ( cont + 1 == N_MAX )
    {
        cout << "A raiz nao foi encontrada! Retornando ultimo valor!\n" ;
    }

    // Retorna valor da raiz
    return Vrk ;
}

// Metodo de Newton para equacao de Peng-Robinson
double mnewton_pr ( substancia s, double T, double P, double Vpr )
{
    // Declaracao de variaveis
    double Vpr_old, erro ;
    int cont = 0 ;

    // Inicio do loop ( Redlich
    erro = 1 ;
    while ( erro > tol and cont < N_MAX )
    {
        Vpr_old = Vpr ;
        Vpr -= epr ( P, T, Vpr, s ) / depr ( P, T, Vpr, s ) ;

        erro = pow ( Vpr - Vpr_old, 2 ) ;
        erro = sqrt ( erro ) ;
        cont++ ;
    }

    if ( cont == N_MAX )
    {
        cout << "A raiz nao foi encontrada! Retornando ultimo valor!\n" ;
    }

    // Retorna valor da raiz
    return Vpr ;
}
