//===========================================================================
// Calculo do vetor gradiente
//===========================================================================

void vgrad ( v1d vx, v1d &vg, double kc1, double kc2, double kc3, double ca0, double cb0 )
{
    // Definicao de variaveis
    double dfi ;
    double eps = 1e-5 ;

    // Calculo do gradiente
    for ( int i = 0 ; i < vx.size (); i++ )
    {
        vx [ i ] += eps ; // Incrementa x_i em eps
        dfi = fobj ( vx, kc1, kc2, kc3, ca0, cb0 ) ;
        vx [ i ] -= 2 * eps ; // Desfaz o incremento e decrescenta x_i em eps
        dfi -= fobj ( vx, kc1, kc2, kc3, ca0, cb0 ) ;
        dfi /= 2 * eps ;
        vx [ i ] += eps ; // Desfaz o decrescimo em x_i

        vg [ i ] = dfi ;
    }
}
