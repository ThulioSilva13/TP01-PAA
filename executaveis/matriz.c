#include "matriz.h"


void insereMatriz(Celula **matriz, int posicaoLinha, int posicaoColuna, int valor){
    //(TipoApontador) malloc(sizeof(TipoCelula));
    matriz[posicaoLinha][posicaoColuna].valor = valor;
    matriz[posicaoLinha][posicaoColuna].posicaoLinha = posicaoLinha+1;
    matriz[posicaoLinha][posicaoColuna].posicaoColuna = posicaoColuna+1;
    matriz[posicaoLinha][posicaoColuna].visitado = false;
    strcpy(matriz[posicaoLinha][posicaoColuna].cor, ANSI_COLOR_DEFAULT);
}
//void AndaPraBaixo(Celula **matriz);

void printaMatriz(Celula **matriz, int linhas, int colunas){
    int i, j;
    printf("\nlinhas: %d || colunas: %d\n",linhas,colunas);
    printf("\n");
    for ( i = 0; i < linhas; i++)
    {
        for ( j = 0; j < colunas; j++)
        {
            printf("%s", matriz[i][j].cor);
            if (matriz[i][j].valor >= 0 && matriz[i][j].valor < 10){
                printf(" %d ", matriz[i][j].valor);
            }
            else{
                printf("%d ", matriz[i][j].valor);
            }
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

void liberaMatriz(Celula **matriz, int linha){
    int i;
    for(i = 0; i < linha; i++)
        free(matriz[i]);
    free(matriz);
}