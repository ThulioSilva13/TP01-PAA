#include "fazenda.h"

void insere_matriz(Elemento **matriz, int posicaoLinha, int posicaoColuna, int valor){
    matriz[posicaoLinha][posicaoColuna].valor = valor;
    matriz[posicaoLinha][posicaoColuna].visitado = false;
    strcpy(matriz[posicaoLinha][posicaoColuna].cor, ANSI_COLOR_DEFAULT);
}

void printa_matriz(Elemento **matriz, int linhas, int colunas){
    int i, j;
    for ( i = 0; i < linhas; i++){
        printf("\n");
        for ( j = 0; j < colunas; j++){
            printf("%s", matriz[i][j].cor);
            if (matriz[i][j].valor >= 0 && matriz[i][j].valor < 10){
                printf(" %d ", matriz[i][j].valor);
            }
            else{
                printf("%d ", matriz[i][j].valor);
            }
        }
    }
    printf("%s", ANSI_COLOR_DEFAULT);
}

void libera_matriz(Elemento **matriz, int linha){
    int i;
    for(i = 0; i < linha; i++)
        free(matriz[i]);
    free(matriz);
}

void preenche_aleatoriamente(Elemento **matriz, int linhas, int colunas){
    int i, j, n;
    srand(time(NULL));
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            if (matriz[i][j].valor == 0){ 
                insere_matriz(matriz, i, j, (rand()%33) + 1); //gerar numero aleatorio entre 1 e 9;
            }
        }
    }
}

void preenche_caminho(Elemento **matriz, int linhas, int colunas){
    int *caminho = malloc((linhas*colunas)*sizeof(int));
    caminho = cria_caminho(linhas, colunas);

    srand(time(NULL));
    int *possiveisColunas = malloc((colunas)*sizeof(int)); //vetor com as possiveis posições de começo = indice das colunas
    for (int i=0;i<colunas; i++){
        possiveisColunas[i] = i;
    }

    int x = 0; //sempre começar da primeira linha
    int y = possiveisColunas[(rand()%colunas)]; //escolher aleatoriamente de qual coluna começar:

    int indice = 0;
    int *prox = malloc((2)*sizeof(int));

    while(x<linhas){
        matriz[x][y].valor = caminho[indice];
        strcpy(matriz[x][y].cor , ANSI_COLOR_GREEN);
        x++;        
        indice++;
    }
}

int* cria_caminho(int linhas, int colunas){
	int *caminho = calloc((linhas*colunas),sizeof(int));
    int max = linhas*colunas;
    int indice = 0;
    int qtd = 1;
    while (indice < max) {
        for (int i = 1; i < qtd; i++){
			if (indice == max){
				return caminho;
			}
            caminho[indice] = fibonacci(i);
            indice ++;
        }
        qtd++;
    }

	return caminho;
}

int fibonacci(int n){ 
    int i = 1, k, F = 0;
    for (k = 1; k <= n; k++){ 
        F += i;  i = F - i;
    }
    return F;
}

void printa_caminho(int *caminho, int linhas, int colunas){
	int max = linhas*colunas;
	printf("\nCaminho = ");
    for (int i = 0; i < max; i++){
        printf("%d-", caminho[i]);
    }
}

int* proxima_posicao(int x, int y){

    printf("\n recebeu: x = %d | y = %d", x,y);

    int *posicao = malloc((2)*sizeof(int));

    posicao[0] = x+1;
    posicao[1] = y;

    
    int direcao[] = {1, -1};
    char eixos[] = {'x', 'y'};
    printf("\nDirecao = %d, %d", direcao[0], direcao[1]);
    printf("\nEixo = %c, %c", eixos[0], eixos[1]);

    srand(time(NULL));
    int eixo = (rand()%2); 
    int dir = (rand()%2);

    printf("\n%d = eixo", eixo);
    printf("\n%d = direcao", dir);
    printf("\neixos[%d] = %c | direcao[%d] = %d", eixo, eixos[eixo], dir, direcao[dir]);
    
    if (eixos[eixo] == 'x') { 
        posicao[0]=x+1;
        posicao[1]=y;
    }
    else{
        posicao[0]=x;
        posicao[1]=y+1;
    }
    
    
    printf("\nposicao[0] = x = %d", posicao[0]);
    printf("\nposicao[1] = y = %d", posicao[1]);
    
    return posicao;
}

void printa_arquivo(Elemento **matriz, int linhas, int colunas){

    printf("\n\n---------------------------------------------------------------------");
    printf("\nSALVAR EM ARQUIVO DE TEXTO");
    printf("\n---------------------------------------------------------------------\n");

    FILE *arquivo;

    char nome_pasta[30] = "./arquivos/";
    char nome_arquivo[30];

    printf("Entre um nome para o arquivo:");
    scanf("%s", nome_arquivo);
    strcat(nome_arquivo, ".txt");

    strcat(nome_pasta, nome_arquivo);

    arquivo = fopen(nome_pasta, "w");

    if (arquivo == NULL){
        printf("\nErro: NAO FOI POSSIVEL CRIAR O ARQUIVO");
        return;
    }

    fprintf(arquivo,"%d ", linhas);
    fprintf(arquivo,"%d", colunas);

    for ( int i = 0; i < linhas; i++){
        fprintf(arquivo,"\n");
        for ( int j = 0; j < colunas; j++){
            fprintf(arquivo,"%d ",matriz[i][j].valor);
        }
    }

    fclose(arquivo);
    return;
}