#include <limits>
#include <cmath>

double f (double x);
double x_s (double ini, double fim, double s);
double s_barra (double ini, double fim, double s);
double f_barra(double ini, double fim, double s);

double GaussHermitExpSimples (double ini, double fim, int grau);
double GaussLegendreExpSimples (double ini, double fim, double iniC, double fimC, int qtdPontos);
double GaussLegendreParticoesExpSImples (double ini, double fim, double iniC, double fimC, int qtdPontos, double eps);