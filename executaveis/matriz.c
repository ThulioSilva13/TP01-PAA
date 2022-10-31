#include "matriz.h"


void insereMatriz(Celula **matriz, int posicaoLinha, int posicaoColuna, int valor){
    //(TipoApontador) malloc(sizeof(TipoCelula));
    matriz[posicaoLinha][posicaoColuna].valor = valor;
    matriz[posicaoLinha][posicaoColuna].posicaoLinha = posicaoLinha;
    matriz[posicaoLinha][posicaoColuna].posicaoColuna = posicaoColuna;
    matriz[posicaoLinha][posicaoColuna].visitado = false;
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
            printf("%d ", matriz[i][j].valor);
        }
        printf("\n");
    }
}

void criaCaminho(int N, int M){
    int caminho[N*M+1];
    int max = N*M;
    int indice = 0;
    int qtd = 1;
    caminho[0]=1;
    while (indice<max) {
        for (int i = 1; i < qtd; i++){
            caminho[indice] = fibonacci(i);
            indice ++;
        }
        qtd++;
    }

    for (int i =0; i<max; i++ ){
        printf("%d\n", caminho[i]);
    }
}
int fibonacci(int n)
{ 
    int i = 1, k, F=0;
    for (k = 1; k <= n; k++)
    { 
        F += i;  i = F - i;
    }
    return F;
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