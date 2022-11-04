#include "fazenda.h"

void insere_matriz(Elemento **matriz, int posicaoLinha, int posicaoColuna, int valor)
{
    matriz[posicaoLinha][posicaoColuna].valor = valor;
    matriz[posicaoLinha][posicaoColuna].visitado = false;
    strcpy(matriz[posicaoLinha][posicaoColuna].cor, ANSI_COLOR_DEFAULT);
}

void printa_matriz(Elemento **matriz, int linhas, int colunas)
{
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
    printf("\n");
    printf("%s", ANSI_COLOR_DEFAULT);
}

void libera_matriz(Elemento **matriz, int linha)
{
    int i;
    for(i = 0; i < linha; i++)
        free(matriz[i]);
    free(matriz);
}

void preenche_aleatoriamente(Elemento **matriz, int linhas, int colunas)
{
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

void preenche_caminho(Elemento **matriz, int linhas, int colunas)
{
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

    srand(time(NULL));

    while(1){

        if (x==(linhas-1)){
            matriz[x][y].valor = caminho[indice];
            strcpy(matriz[x][y].cor , ANSI_COLOR_GREEN);
            break; 
        }
        
        int direcao = (rand()%3); //gerar numero aleatorio de 0 a 2;

        if (direcao == 0){ //andar para baixo
            if ((verificaPosicao(matriz, linhas, colunas, x+1, y))==true){
                matriz[x][y].valor = caminho[indice];
                strcpy(matriz[x][y].cor , ANSI_COLOR_GREEN);
                matriz[x][y].visitado = true;
                x++;        
                indice++;
            }
        }

        if (direcao == 1){ //andar para direita
            if ((verificaPosicao(matriz, linhas, colunas, x, y+1))==true){
                matriz[x][y].valor = caminho[indice];
                strcpy(matriz[x][y].cor , ANSI_COLOR_GREEN);
                matriz[x][y].visitado = true;
                y++;        
                indice++;
            }
        }

        if (direcao == 2){ //andar para esquerda
            if ((verificaPosicao(matriz, linhas, colunas, x, y-1))==true){
                matriz[x][y].valor = caminho[indice];
                strcpy(matriz[x][y].cor , ANSI_COLOR_GREEN);
                matriz[x][y].visitado = true;
                y--;        
                indice++;
            }
        }
    }
}

bool verificaPosicao(Elemento **matriz, int numLinhas, int numColunas,int x, int y)
{
	if ((x >= 0 && x < numLinhas) && (y >= 0 && y < numColunas) &&
	    (matriz[x][y].visitado == false)) {	
		return true;
	} 	
	return false;
}

int* cria_caminho(int linhas, int colunas)
{
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

int fibonacci(int n)
{ 
    int i = 1, k, F = 0;
    for (k = 1; k <= n; k++){ 
        F += i;  i = F - i;
    }
    return F;
}

void printa_caminho(int *caminho, int linhas, int colunas)
{
	int max = linhas*colunas;
	printf("\nCaminho = ");
    for (int i = 0; i < max; i++){
        printf("%d-", caminho[i]);
    }
}

void printa_arquivo(Elemento **matriz, int linhas, int colunas)
{
    printf("\n==== SALVAR EM ARQUIVO =====\n");

    FILE *arquivo;

    char nome_pasta[30] = "../arquivosTeste/";
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