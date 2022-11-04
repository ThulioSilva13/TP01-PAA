#include "backtracking.h"

void achaCaminho(Celula **matriz, int numLinhas, int numColunas, int modoAnalise)
{
	TipoPilha pilha;
    fpVazia(&pilha);

	int *caminho = malloc((numLinhas*numColunas)*sizeof(int));
	caminho = criaCaminho(numLinhas, numColunas);
	
	int indiceCaminho = 0;
	int contadorDeFalsos = 0;

	for(int i=0; i<numColunas; i++){
		if (movimentar(matriz, numLinhas, numColunas, 0, i, &pilha, caminho, &indiceCaminho) == false) {
			contadorDeFalsos++;
		}
		else{
			printf("\nROTA OTIMA ENCONTRADA!\n");
			printf("\nCoordenadas da rota:\n");
			invertePilha(&pilha);
			printf("\nPosicoes da rota na matriz:");
			printaMatriz(matriz, numLinhas, numColunas);
			break;
		}
	}

	if (contadorDeFalsos == (numColunas)){
		printf("\nIMPOSSIVEL!");
	}

	if (modoAnalise == 1){
		printf("\n\n======= MODO ANALISE ======= \n");
		printf("\n- Quantidade de chamadas recursivas: %d", qntdRecursao(pilha));
		imprimeQuantidadeRecursaoDirecao(pilha);
	}

	return;
}

bool verificaPosicao(Celula **matriz, int numLinhas, int numColunas,int x, int y, int *caminho, int indiceCaminho)
{
	if ((x >= 0 && x < numLinhas) && (y >= 0 && y < numColunas) &&
	    (matriz[x][y].valor == caminho[indiceCaminho])){		
		return true;
	} 
	
	return false;
}

bool movimentar(Celula **matriz, int numLinhas, int numColunas, int x, int y, TipoPilha* pilha, int *caminho, int *indiceCaminho)
{
	TipoItem item;
	pilha->nivelRecursao[4]++;
	pilha->qntdRecursao++;

	int novoIndice = *indiceCaminho;

	//verifica se a posicao é valida
	if (verificaPosicao(matriz, numLinhas, numColunas, x, y, caminho, novoIndice) == true) {
		
		if ((x == numLinhas - 1) && (matriz[x][y].valor == caminho[novoIndice])) {
			item.celulaMatriz = matriz[x][y];		

			strcpy(matriz[x][y].cor, ANSI_COLOR_GREEN);
			empilha(item , pilha);
			return true;
		}

		if (matriz[x][y].visitado == true){
			return false;
		}

		matriz[x][y].visitado = true;
		strcpy(matriz[x][y].cor, ANSI_COLOR_GREEN);
		
		item.celulaMatriz = matriz[x][y];
		empilha(item,pilha);
		novoIndice ++;
		
		//primeira opção de caminho: 
		//andar para baixo
		pilha->nivelRecursao[0] += 1;
		if (movimentar(matriz, numLinhas, numColunas, x+1, y, pilha, caminho, &novoIndice) == true){
			return true;
		}
			
		//se para baixo não der solução:
		//andar para direita
		pilha->nivelRecursao[1] += 1;
		if (movimentar(matriz, numLinhas, numColunas, x, y+1, pilha, caminho, &novoIndice) == true){
			return true;
		}
			
		//se para direita não der solução:
		//andar para esquerda
		pilha->nivelRecursao[2] += 1;
		if (movimentar(matriz, numLinhas, numColunas, x, y-1, pilha, caminho, &novoIndice) == true){
			return true;
		}

		//se para esquerda não der solução:
		//andar para cima
		pilha->nivelRecursao[3] += 1;
		if (movimentar(matriz, numLinhas, numColunas, x-1, y, pilha, caminho, &novoIndice) == true){
			return true;
		}
		
		//se para cima não der solução => desmarcar posição e decrementar indiceCaminho
		desempilha (pilha, &item);
		matriz[x][y].visitado = false;
		strcpy(matriz[x][y].cor, ANSI_COLOR_DEFAULT);
		indiceCaminho--;
		return false;
	}
	return false;
}

int* criaCaminho(int N, int M)
{
	int *caminho = malloc((N*M)*sizeof(int));
    int max = N*M;
    int indice = 0;
    int qtd = 1;

    while (indice < max) {
        for (int i = 1; i < qtd; i++)
		{
			if (indice == max) {
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
    int i = 1, k, f = 0;
    for (k = 1; k <= n; k++)
    { 
        f += i;  i = f - i;
    }
    return f;
}

void printaCaminho(int *caminho, int numLinha, int numColuna)
{
	int max = numLinha * numColuna;
	printf("\nCaminho = ");
    for (int i = 0; i < max; i++)
	{
		if (i==0)
			printf("%d", caminho[i]);
		else
			printf("-%d", caminho[i]);
    }
}
