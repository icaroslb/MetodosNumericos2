all: ExponenciacaoSimples.o main

ExponenciacaoSimples.o: ExponenciacaoSimples.cpp ExponenciacaoSimples.h
	g++ -g -c $< -o $@

main: main.cpp ExponenciacaoSimples.o
	g++ $^ -o $@