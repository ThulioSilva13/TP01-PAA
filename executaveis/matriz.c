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


// --------- nao utilizada ------------- //

void inicializaMatriz(int **matriz, int linhas, int colunas){
    int i;
    matriz = malloc (linhas * sizeof (int*)) ; // aloca um vetor de linhas ponteiros para linhas
    // aloca cada uma das linhas (vetores de COL inteiros)
    for (i=0; i < linhas; i++){
        matriz[i] = malloc (colunas * sizeof (int)) ; // aloca cada uma das linhas (vetores de colunas inteiros)
    }
    
}
/* --------- explicação:
    Quando uso a função inicializaMatriz, da segmentation fault quando insiro algum valor na matriz;
    Entretanto, quando utilizo o codigo (do inicializa matriz) DIRETO dentro do lerArquivoPrincipal, dá certinho; */
    
// --------- nao utilizada ------------- //