#ifndef matriz_h
#define matriz_h

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Celula *TipoApontador;
typedef struct Celula{
    int valor;
    int posicaoLinha;
    int posicaoColuna;
    bool visitado; 
}Celula;

void insereMatriz(Celula **matriz, int posicaoLinha, int posicaoColuna, int valor);
void printaMatriz(Celula **matriz, int linhas, int colunas);
Celula **inicializaMatriz(Celula **matriz, int linhas, int colunas);
void LiberaMatriz(Celula **matriz, int l);
//void criaCaminho(int N, int M, int **caminho);
//int fibonacci(int n);
//void printaCaminho(int *caminho);

#endif