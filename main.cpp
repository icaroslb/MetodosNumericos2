#include <iostream>

#include <string>
#include <limits>
//#include "GaussLegendre.h"
#include "ExponenciacaoSimples.h"

int main()
{
  double a;
  double b;
  double cInicial;
  double c;
  double eps;
  double passo;
  int qtdPontos;
  int grau;

  std::cout << "Integração de Gauss Legendre" << std::endl;

  std::cout << "Início do intervalo: ";
  std::cin >> a;

  std::cout << "Fim do intervalo: ";
  std::cin >> b;

  //std::cout << "Número de grau de Hermit: ";
  //std::cin >> grau;

  std::cout << "Quantidade de pontos de Legendre: ";
  std::cin >> qtdPontos;

  std::cout << "Insira o valor do corte: ";
  std::cin >> cInicial;

  std::cout << "Tolerância: ";
  std::cin >> eps;

  double resultadoAnt;
  double resultadoNovo = std::numeric_limits<double>::infinity();

  //double resultado = GaussHermitExpSimples(a, b, grau);

  c = cInicial;
  passo = 0.1;

  do
  {
    resultadoAnt = resultadoNovo;

    resultadoNovo = GaussLegendreParticoesExpSImples(a, b, -c, c, qtdPontos, eps);

    c += passo;

    if (isnan( resultadoNovo ) || isinf( resultadoNovo ))
    {
      c = cInicial;
      passo /= 10;
      resultadoNovo = std::numeric_limits<double>::infinity();
      continue;
    }

  } while (fabs( ( resultadoNovo - resultadoAnt ) / resultadoNovo ) > eps);

  std::cout << resultadoNovo << " - " << c - passo << std::endl;

  return 0;
}

//1.5707963268