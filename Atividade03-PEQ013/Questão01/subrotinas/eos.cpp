//===========================================================================
// Equacoes de estado e suas derivadas em relacao ao volume
//===========================================================================

// Equacao de Redlich-Kwong
double erk ( double P, double T, double V, substancia s )
{
    double f ;
    f = ( s.ark ( T ) - P * pow ( s.brk ( ), 2 ) - R * T * s.brk ( ) ) * V ;
    f += P * pow ( V, 3 ) - R * T * V * V - s.ark ( T ) * s.brk ( ) ;
    return f ;
}

// Derivada da equacao de RK
double derk ( double P, double T, double V, substancia s )
{
    double eps, df ;
    eps = 1e-5 ;
    df = erk ( P, T, V + eps, s ) - erk ( P, T, V - eps, s ) ;
    df /= 2 * eps ;
    return df ;
}

// Equacao de Peng-Robinson
double epr ( double P, double T, double V, substancia s )
{
    double f ;
    f = ( s.apr ( T ) - 3 * P * pow ( s.bpr ( ), 2 ) - 2 * R * T * s.bpr ( ) ) * V ;
    f += P * pow ( V, 3 ) + P * pow ( s.bpr ( ), 3 ) ;
    f += ( P * s.bpr ( ) - R * T ) * V * V ;
    f += R * T * pow ( s.bpr ( ), 2 ) - s.bpr ( ) * s.apr ( T ) ;
    return f ;
}

// Derivada da equacao de PR
double depr ( double P, double T, double V, substancia s )
{
    double eps, df ;
    eps = 1e-5 ;
    df = epr ( P, T, V + eps, s ) - epr ( P, T, V - eps, s ) ;
    df /= 2 * eps ;
    return df ;
}
