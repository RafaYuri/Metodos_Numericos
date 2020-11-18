//===============================================================
// Funcoes para resolucao do problema
//===============================================================

// Numero de Reynolds
double Re ( double vt )
{
    return Dp * vt * rho / mu ;
}

// Coeficiente de arraste (Cd)
double Cd ( double vt )
{
    double re, cd ;
    re = Re ( vt ) ;

    if ( re < 0.1 )
    {
        cd = 24.0 / re ;
    }

    else if ( re >= 0.1 and re <= 1000 )
    {
        cd = 24 * ( 1 + 0.14 * pow ( re, 0.7 ) ) / re ;
    }

    else if ( re > 1000 and re <= 350000 )
    {
        cd = 0.44 ;
    }

    else
    {
        cd = 0.19 - 8e4 / re ;
    }

    return cd ;
}

// Velocidade terminal ( vt )
double velocidade_t ( double vt )
{
    double f ;
    f = vt - sqrt ( 4 * g * ( rho_p - rho ) * Dp / ( 3 * Cd ( vt ) * rho ) ) ;
    return f ;
}

// Derivada da velocidade terminal
double dvt ( double vt )
{
    double df, eps ;
    eps = 1e-5 ;
    df = velocidade_t ( vt + eps ) - velocidade_t ( vt - eps ) ;
    df /= 2 * eps ;
    return df ;
}
