#include "lerArquivos.h"
#include "matriz.h"

void lerArquivoPrincipal(char **nomeArquivo, int **matriz)
{
    int i,linhas, colunas;
    char *cadaNumero;
    char nomepasta[100] = "./arquivos/";
    char *cadaLinha;
    cadaLinha = malloc(sizeof(char) * 150);

    strcat(nomepasta, *nomeArquivo);
    strcat(nomepasta, ".txt");
    printf("%s\n",nomepasta);
    
    if ((arquivoDeEntrada = fopen(nomepasta, "r")) == NULL)
    {
        *nomeArquivo = NULL;
        printf("\nArquivo nao encontrado!");
        return;
    }
    fscanf(arquivoDeEntrada, "%d %d", &linhas, &colunas);

    matriz = malloc (linhas * sizeof (int*)) ; // aloca um vetor de linhas ponteiros para linhas
    // aloca cada uma das linhas (vetores de COL inteiros)
    for (i=0; i < linhas; i++){
        matriz[i] = malloc (colunas * sizeof (int)) ; // aloca cada uma das linhas (vetores de colunas inteiros)
    }

    int posicaoLinha = 0;

    while (!feof(arquivoDeEntrada))
    {
        int posicaoColuna  = 0;
        fscanf(arquivoDeEntrada," %[^\n]s",cadaLinha);         
        if (cadaLinha)  // Se foi possível ler
        {
            cadaNumero = strtok(cadaLinha, " ");
            while (cadaNumero != NULL)
            {
                //printf("%d %d %d\n",posicaoLinha,posicaoColuna, atoi(cadaNumero));
                insereMatriz(matriz,posicaoLinha,posicaoColuna,atoi(cadaNumero));
                posicaoColuna++;
                cadaNumero = strtok(NULL, " ");
            }                
        }
        posicaoLinha++;
    }
    fclose(arquivoDeEntrada);
    *nomeArquivo = NULL;
    printaMatriz(matriz, linhas, colunas);
  
}
