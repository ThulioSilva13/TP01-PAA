#include "matriz.h"

void insereMatriz(Celula **matriz, int posicaoLinha, int posicaoColuna, int valor){
    //(TipoApontador) malloc(sizeof(TipoCelula));
    matriz[posicaoLinha][posicaoColuna].valor = valor;
    matriz[posicaoLinha][posicaoColuna].posicaoLinha = posicaoLinha;
    matriz[posicaoLinha][posicaoColuna].posicaoColuna = posicaoColuna;
    matriz[posicaoLinha][posicaoColuna].visitado = false;
    matriz[posicaoLinha][posicaoColuna].cima = (TipoApontador)malloc(sizeof(Celula));
    matriz[posicaoLinha][posicaoColuna].baixo = (TipoApontador)malloc(sizeof(Celula));
    matriz[posicaoLinha][posicaoColuna].esquerda = (TipoApontador)malloc(sizeof(Celula));
    matriz[posicaoLinha][posicaoColuna].direita = (TipoApontador)malloc(sizeof(Celula));
}

void printaMatriz(Celula **matriz, int linhas, int colunas){
    int i, j;
    printf("\nlinhas: %d || colunas: %d\n",linhas,colunas);
    printf("\n");
    for ( i = 0; i < linhas; i++)
    {
        for ( j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j].valor);
        }
        printf("\n");
    }
}

Celula **inicializaMatriz(Celula **matriz, int linhas, int colunas){
    int i;
    //matriz = malloc (linhas * sizeof (int*));
    matriz = (Celula **)malloc(sizeof(Celula *)*linhas);

    if( matriz == NULL){
        printf("Memoria insuficiente.\n");
        return NULL;
    }
    for (i=0; i < linhas; i++){
        matriz[i] = (Celula *)malloc(sizeof(Celula)*colunas);
        if( matriz[i] == NULL){
            printf("Memoria insuficiente.\n");
            return NULL;
        }
    }
    return matriz;
}

// void LiberaMatriz(Celula *matriz, int l){
//     int i;
//     for(i = 0; i < l; i++)
//         free(matriz[i]);
//     free(matriz);
// }