#include "GaussLegendre.h"

double f(double x)
{
  return cos( x );
}

double x_s (double ini, double fim, double s)
{
  return ( ( fim + ini ) / 2.0 ) + ( ( ( fim - ini ) / 2.0 ) * s );
}

double GaussLegendre (double ini, double fim, int qtdPontos)
{
  double resultado;
  double w1, w2, w3;

  switch (qtdPontos)
  {
  case 2:
    w1 = w2 = 1.0;
    resultado = ( ( fim - ini ) / 2.0 ) * ( f( x_s( ini, fim, -(1.0 / sqrt( 3.0 ) ) ) ) * w1
                                          + f( x_s( ini, fim, +(1.0 / sqrt( 3.0 ) ) ) ) * w2 );
    break;
  case 3:
    w1 = w3 = 5.0 / 9.0;
    w2 = 8.0 / 9.0;

    resultado = ( ( fim - ini ) / 2.0 ) * ( f( x_s( ini, fim, -(sqrt( 3.0 / 5.0 ) ) ) ) * w1
                                          + f( x_s( ini, fim,  (0.0               ) ) ) * w2
                                          + f( x_s( ini, fim, +(sqrt( 3.0 / 5.0 ) ) ) ) * w3 );
  }

  return resultado;
}