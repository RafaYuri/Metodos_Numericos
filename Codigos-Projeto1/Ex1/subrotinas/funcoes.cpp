//================================================================
// Funcoes que compoem o problema
//================================================================

double pressao ( double Pr )
{
    double p = Pr * Pc ;
    return p ;
}

double fcompressibilidade ( double P, double V, double T )
{
    return P * V / ( R * T ) ;
}


// Equacao de van der Waals
double eqvdw ( double T, double P, double V )
{
    double a, b, f ;
    a = ( 27.0 / 64 ) * ( R * R * Tc * Tc / Pc ) ;
    b = ( R * Tc ) / ( 8 * Pc ) ;
    f = ( P + a / pow ( V, 2 ) ) * ( V - b ) - R * T ;
    return f ;
}

// Derivada equacao de van der Waals
double deqvdw ( double T, double P, double V )
{
    double eps, df ;
    eps = 1e-5 ;
    df = eqvdw ( T, P, V + eps ) - eqvdw ( T, P, V - eps ) ;
    df /= 2 * eps ;
    return df ;
}

