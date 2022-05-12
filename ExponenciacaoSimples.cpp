#include "ExponenciacaoSimples.h"

double f (double x)
{
  return 1.0 / sqrt(x);
}

double x_s (double ini, double fim, double s)
{
  return ( ( ini + fim ) / 2.0 ) + ( ( ( fim - ini ) / 2.0 ) * tanh(s) );
}

double s_barra (double ini, double fim, double s)
{
  return ( ( fim + ini ) / 2.0 ) + ( ( ( fim - ini ) / 2.0 ) * s );
}

double f_barra(double ini, double fim, double s)
{
  return f(x_s(ini, fim, s))
       * ( ( fim - ini ) / 2.0 )
       * ( 1.0 / pow( cosh(s), 2 ) );
}

double GaussHermitExpSimples (double ini, double fim, int grau)
{
  double w1, w2, w3;
  double s1, s2, s3;
  double resultado;

  switch (grau)
  {
  case 2:
    s1 = - ( 1.0 / sqrt(2) );
    s2 = + ( 1.0 / sqrt(2) );
    w1 = w2 = sqrt(M_PI) / 2.0;

    resultado = ( exp(s1 * s1) * f_barra( ini, fim, s1 ) * w1 )
              + ( exp(s2 * s2) * f_barra( ini, fim, s2 ) * w2 );
    break;
  case 3:
    s1 = - sqrt( 3.0 / 2.0 );
    s2 = 0.0;
    s3 = + sqrt( 3.0 / 2.0 );
    w1 = w3 = sqrt(M_PI) / 6.0;
    w2 = ( 2.0 * sqrt(M_PI) ) / 3.0;

    resultado = ( exp(s1 * s1) * f_barra( ini, fim, s1 ) * w1 )
              + ( exp(s2 * s2) * f_barra( ini, fim, s2 ) * w2 )
              + ( exp(s3 * s3) * f_barra( ini, fim, s3 ) * w3 );
  break;
  }

  return resultado;
}

double GaussLegendreExpSimples (double ini, double fim, double iniC, double fimC, int qtdPontos)
{
  double resultado;
  double w1, w2, w3;
  double s1, s2, s3;

  switch (qtdPontos)
  {
  case 2:
    w1 = w2 = 1.0;
    s1 = - 1.0 / sqrt( 3.0 );
    s2 = + 1.0 / sqrt( 3.0 );

    resultado = ( ( fimC - iniC ) / 2.0 ) * ( ( f_barra( ini, fim, s_barra( iniC, fimC, s1 ) ) * w1 )
                                            + ( f_barra( ini, fim, s_barra( iniC, fimC, s2 ) ) * w2 ) );
    break;
  case 3:
    w1 = w3 = 5.0 / 9.0;
    w2 = 8.0 / 9.0;

    s1 = - sqrt( 3.0 / 5.0 );
    s2 = 0.0;
    s3 = + sqrt( 3.0 / 5.0 );

    resultado = ( ( fimC - iniC ) / 2.0 ) * ( ( f_barra( ini, fim, s_barra( iniC, fimC, s1 ) ) * w1 )
                                            + ( f_barra( ini, fim, s_barra( iniC, fimC, s2 ) ) * w2 )
                                            + ( f_barra( ini, fim, s_barra( iniC, fimC, s3 ) ) * w3 ) );
  }

  return resultado;
}

double GaussLegendreParticoesExpSImples (double ini, double fim, double iniC, double fimC, int qtdPontos, double eps)
{
  double integralNova = std::numeric_limits<double>::infinity();
  double integralVelha;
  int N = 1;

  do
  {
    integralVelha = integralNova;

    double deltaX = ( fimC - iniC ) / N;

    integralNova = 0.0;

    for ( int i = 0; i < N; i++ )
    {
      double xIn = iniC + ( i * deltaX );
      double xFin = xIn + deltaX;
      integralNova += GaussLegendreExpSimples( ini, fim, xIn, xFin, qtdPontos );
    }

    N *= 2;
  } while (fabs( ( integralNova - integralVelha ) / integralNova ) > eps );

  return integralNova;
}