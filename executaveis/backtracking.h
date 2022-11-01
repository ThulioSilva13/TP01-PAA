#include <stdio.h>
#include <stdbool.h>
#include "pilha.h"

void achaCaminho(Celula **matriz, int numLinhas, int numColunas);
bool confereCaminho(Celula **matriz, int numLinhas, int numColunas, int x, int y, TipoPilha* pilha, int *caminho, int *indiceCaminho);
void printaCaminho(int *caminho, int numLinhas, int numColunas);
int* criaCaminho(int N, int M);
bool verificaPosicao(Celula **matriz, int numLinhas, int numColunas, int x, int y, int *caminho, int indiceCaminho);
int fibonacci(int n);