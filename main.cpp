#include <iostream>

#include <string>
#include <limits>
#include "GaussLegendre.h"

int main()
{
  double a;
  double b;
  double eps;
  int qtdPontos;

  std::cout << "Integração de Gauss Legendre" << std::endl;

  std::cout << "Início do intervalo: ";
  std::cin >> a;

  std::cout << "Fim do intervalo: ";
  std::cin >> b;

  std::cout << "Número de pontos de Legendre: ";
  std::cin >> qtdPontos;

  std::cout << "Tolerância: ";
  std::cin >> eps;

  double integralNova = std::numeric_limits<double>::infinity();
  double integralVelha;
  int N = 1;

  do
  {
    integralVelha = integralNova;

    double deltaX = ( b - a ) / N;

    integralNova = 0.0;

    for ( int i = 0; i < N; i++ )
    {
      double xIn = a + ( i * deltaX );
      double xFin = xIn + deltaX;
      integralNova += GaussLegendre( xIn, xFin, qtdPontos );
    }

    N *= 2;
  } while (fabs( ( integralNova - integralVelha / integralNova ) ) > eps );
  
  std::cout << integralNova << " - " << N << std::endl;

  return 0;
}

//1.5707963268