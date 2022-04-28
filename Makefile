all: GaussLegendre.o main

GaussLegendre.o: GaussLegendre.cpp GaussLegendre.h
	g++ -g -c $< -o $@

main: main.cpp GaussLegendre.o
	g++ $^ -o $@ -lmuparser