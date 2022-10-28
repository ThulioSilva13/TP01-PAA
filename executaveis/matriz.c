#include "matriz.h"

void insereMatriz(int **matriz, int posicaoLinha, int posicaoColuna, int valor){
    matriz[posicaoLinha][posicaoColuna] = valor;
}

void printaMatriz(int **matriz, int linhas, int colunas){
    int i, j;
    printf("\nlinhas: %d || colunas: %d\n",linhas,colunas);
    printf("\n");
    for ( i = 0; i < linhas; i++)
    {
        for ( j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int **inicializaMatriz(int **matriz, int linhas, int colunas){
    int i;
    //matriz = malloc (linhas * sizeof (int*));
    matriz = (int **)malloc(sizeof(int *)*linhas);

    if( matriz == NULL){
        printf("Memoria insuficiente.\n");
        return NULL;
    }
    for (i=0; i < linhas; i++){
        matriz[i] = (int *)malloc(sizeof(int)*colunas);
        if( matriz[i] == NULL){
            printf("Memoria insuficiente.\n");
            return NULL;
        }
    }
    return matriz;
}

void LiberaMatriz(int **matriz, int l){
    int i;
    for(i = 0; i < l; i++)
        free(matriz[i]);
    free(matriz);
}