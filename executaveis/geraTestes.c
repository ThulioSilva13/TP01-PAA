#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"


// void printaMatriz(int **matriz, int N, int M);

// int* criaCaminho(int N, int M);
// int fibonacci(int n);
// void printaCaminho(int *caminho, int N, int M);

void geraTesteMenu(){
    printf("\n---------------------------------------------------------------------");
    printf("\nMENU");
    printf("\n---------------------------------------------------------------------");
    printf("\n[ 1 ] | Arquivo 'talvez' com Solucao");
    printf("\n[ 2 ] | Arquivo com Soulucao");
    printf("\n[ 3 ] | Aleatorio");
    printf("\n[ 4 ] | Encerrar");
    printf("\nEscolha: ");
}

void geraTestesMain(){

    int opcao, N, M;
    
    while(1){ //enquanto verdaade

        menu();
        scanf("%d",&opcao);

        if( opcao == 4){
            printf("\n---------------------------------------------------------------------");
            printf("\nPROGAMA ENCERRADO");
            printf("\n---------------------------------------------------------------------\n");
            break;
        }

        else{
            printf("\nEntre com as dimensões da fazenda: \n- N = ");
            scanf("%d",&N);
            printf("- M = ");
            scanf("%d",&M);

            //maximo 100. se maior que 100 colocar 100;

            int **matriz;

            matriz = (int**) malloc(N*sizeof(int*));
            for(int i=0; i<N; i++)
                matriz [i] = (int*)calloc(M,sizeof(int)); //alocar e já inicializar com 0

            if (opcao == 1){
                printf("\nPreencher matriz com numeros aleatorios da sequencia de fibonacci");
                preencheAleatoriamente(matriz, N, M);
                
                printaMatriz(matriz, N, M);
            }
            else if (opcao == 2){
                printf("\nPreencher caminho na matriz");
                preencheCaminho(matriz, N, M);
                preencheAleatoriamente(matriz, N, M); //preencher posições que nao fazem parte do caminho
                printaMatriz(matriz, N, M);
            }

            else if (opcao == 3){
                printf("\n Gerar aleatoriamente numero entre 0 e 1");
            }
                
            else{
                printf("\nErro: OPCAO INVALIDA!");  
            }    
        }
    }
    //return 0;
}

void preencheAleatoriamente(int **matriz, int N, int M){
    int i, j, n;
    srand(time(NULL));
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            if (matriz[i][j] == 0){ 
                matriz[i][j] = (rand()%33) + 1; //gerar numero aleatorio entre 1 e 9;
            }
        }
    }
}

void preencheCaminho(int **matriz, int N, int M){
    int *caminho = malloc((N*M)*sizeof(int));
    caminho = criaCaminho(N, M);
    printaCaminho(caminho, N,M);

    int *colunas = malloc((M)*sizeof(int)); //vetor com as possiveis posições de começo = indice das colunas
    for (int i=0;i<M; i++){
        colunas[i] = i;
    }
    printf("\n Possibilidades de começo: ");
    for (int i=0;i<M; i++){
        printf("%d - ",colunas[i]);
    }

    int x = 0; //sempre começar da primeira linha

    //escolher aleatoriamente de qual coluna começar:
    srand(time(NULL));
    int y = colunas[(rand()%M)];;
    //int y=0;

    printf("\nColuna Inicial = %d",y);

    int indice = 0;
    int *prox = malloc((2)*sizeof(int));

    //gerar caminho que só desce 
    while(x<N){
        matriz[x][y] = caminho[indice];
        x++;        
        indice++;
    }

    printf("\nCaminho;");
    printaMatriz(matriz, N, M);
}

// void printaMatriz(int **matriz, int N, int M){
//     int i, j;
//     printf("\n%d %d",N,M);
//     for ( i = 0; i < N; i++){
//         printf("\n");
//         for ( j = 0; j < M; j++){
//             printf("%d ", matriz[i][j]);
//         }
//     }
//     printf("\n"); 
// }

// int* criaCaminho(int N, int M){
//     int *caminho = calloc((N*M),sizeof(int));
//     int max = N*M;
//     int indice = 0;
//     int qtd = 1;
//     while (indice < max) {
//         for (int i = 1; i < qtd; i++){
//             if (indice == max){
//                 return caminho;
//             }
//             caminho[indice] = fibonacci(i);
//             indice ++;
//         }
//         qtd++;
//     }

//     return caminho;
// }

// int fibonacci(int n)
// { 
//     int i = 1, k, F = 0;
//     for (k = 1; k <= n; k++)
//     { 
//         F += i;  i = F - i;
//     }
//     return F;
// }

// void printaCaminho(int *caminho, int N, int M){
//     int max = N*M;
//     printf("\nCaminho = ");
//     for (int i = 0; i < max; i++){
//         printf("%d-", caminho[i]);
//     }
// }
