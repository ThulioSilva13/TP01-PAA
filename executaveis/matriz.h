#include <stdlib.h>
#include <stdio.h>

void insereMatriz(int **matriz, int posicaoLinha, int posicaoColuna, int valor);
void printaMatriz(int **matriz, int linhas, int colunas);
int **inicializaMatriz(int **matriz, int linhas, int colunas);
void LiberaMatriz(int **matriz, int l);