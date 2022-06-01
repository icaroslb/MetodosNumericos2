import numpy as np
import math

## decomposição.py possui as funções de decomposição
## main() apenas para testes

def LU (M):
  L = np.identity(np.shape(M)[0])
  U = np.identity(np.shape(M)[0])

  for j in range(np.shape(M)[0]):
    for i in range(j + 1):
      value = 0
      for k in range(i):
        value = value + (L[i, k] * U[k, j])
      U[i, j] = M[i, j] - value

    for i in range(j + 1, np.shape(M)[0]):
      value = 0
      for k in range(j):
        value = value + (L[i, k] * U[k, j])
      if (U[j, j] == 0):
        raise ValueError("Matriz não se decompõe em LU!")
      L[i, j] = (M[i, j] - value) / U[j, j]
  
  return (L, U)

def resolutionLU (L, U, b):
  y = np.zeros(np.shape(b))
  x = np.zeros(np.shape(b))
  size = np.shape(b)[0]

  for i in range(size):
    y[i, 0] = b[i, 0]
    for j in range(i):
      y[i, 0] = y[i, 0] - (L[i, j] * y[j, 0])

  for i in range(size - 1, -1, -1):
    x[i, 0] = y[i, 0]
    for j in range(size - 1, i, -1):
      x[i, 0] = x[i, 0] - (U[i, j] * x[j, 0])
      
    x[i, 0] = x[i, 0] / U[i, i]
  
  return x

def main ():
  M = np.array([[1, 2, 3], [4, 5, 6], [7, 7, 8]])
  b = np.array([[1], [5], [7]])
  (L, U) = LU(M)
  x = resolutionLU(L, U, b)
  print("\n\nL:\n{}\n\nU:\n{}\n\nL * U:\n{}\n\nx:\n{}\n\n LU * x:\n{}".format(L, U, L @ U, x, L @ U @ x))


if __name__ == "__main__":
  main()