import numpy as np
import decomposicaoLU as decomp

def metodoPotenciaInversa(M, x, eps):
  (L, U) = decomp.LU(M)
  
  error = float('inf')
  antAutoValor = 0
  x = x / np.linalg.norm(x)
  y = decomp.resolutionLU(L, U, x)

  autoValor = ( x.transpose() @ y )
  autoVetor = x

  while (error > eps):
    antAutoValor = autoValor
    x = y / np.linalg.norm(y)
    y = decomp.resolutionLU(L, U, x)
    autoValor = ( x.transpose() @ y )

    error = abs( ( antAutoValor - autoValor ) / autoValor )


  autoValor = 1.0 / autoValor
  autoVetor = y / np.linalg.norm(y)
  
  return (autoValor, autoVetor)

#*********************************************************#
#*********************************************************#

def main():
  tamanhoMatriz = int(input("Insira o tamanho da matriz: "))
  eps = float(input("Insira o erro: "))
  M = np.zeros([tamanhoMatriz, tamanhoMatriz])
  x = np.zeros([tamanhoMatriz, 1])

  for i in range(tamanhoMatriz):
    M[i, :] = [float(j) for j in input("Insira a linha {} da matriz: ".format(i)).split(" ")]

  for i in range(tamanhoMatriz):
    x[i, 0] = float(input("Insira a posição {} do vetor: ".format(i)))

  (autoValor, autoVetor) = metodoPotenciaInversa(M, x, eps)

  print("Auto valor: {}\n\nAuto Vetor:\n{}".format(autoValor, autoVetor / autoVetor[2, 0]))

# 4 2 1
# 2 5 3
# 1 3 3


#*********************************************************#
#*********************************************************#


if __name__ == "__main__":
  main()