#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *arquivoDeEntrada;
void lerArquivoPrincipal(char **nomeArquivo, int **matriz);
void inicializaMatriz(int **matriz, int linhas, int colunas);
void insereMatriz(int **matriz, int posicaoLinha, int posicaoColuna,int valor);
void printaMatriz(int **matriz, int linhas, int colunas);