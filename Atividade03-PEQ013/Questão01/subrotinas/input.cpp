//===========================================================================
// Entrada de dados
//===========================================================================

class substancia{

private:
    double Tc, Pc, w ;

public:
    void setTc ( double T_c )
    {
        Tc = T_c ;
    }

    void setPc ( double P_c )
    {
        Pc = P_c ;
    }

    void setOmega ( double omega )
    {
        w = omega ;
    }

    double getTc ( ) const { return Tc ; }

    double getPc ( ) const { return Pc ; }

    double getOmega ( ) const { return w ; }

    // Parametros de Redlich-Kwong
    double ark ( double T ) const
    {
        double a ;
        a = 0.42748 * pow ( R * Tc, 2 ) / Pc * pow ( Tc / T, 0.5 ) ;
        return a ;
    }

    double brk ( ) const
    {
        double b ;
        b = 0.08664 * ( R * Tc / Pc ) ;
        return b ;
    }

    // Parametros de Peng-Robinson
    double apr ( double T ) const
    {
        double m, alfa, a ;
        m = 0.37363 + ( 1.54226 - 0.26992 * w ) * w ;
        alfa = 1 + m * ( 1 - pow ( T / Tc, 0.5 ) ) ;
        alfa = pow ( alfa, 2 ) ;
        a = 0.45724 * alfa * pow ( R * Tc, 2 ) / Pc ;
        return a ;
    }

    double bpr ( ) const
    {
        double b ;
        b = 0.07780 * R * Tc / Pc ;
        return b ;
    }

};
