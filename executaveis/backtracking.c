#include "backtracking.h"

TipoPilha pilha;

/*
//bool solveMazeUtil(int maze[N][N], int x, int y,int sol[N][N]);

// A utility function to print solution matrix sol[N][N]
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}


// A utility function to check if x, y is valid index for
// N*N maze
bool isSafe(int maze[N][N], int x, int y)
{
	// if (x, y outside maze) return false
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) //passar qual valor tem q comparar: contador
		return true;
	return false;
}

// This function solves the Maze problem using Backtracking.
// It mainly uses solveMazeUtil() to solve the problem. It
// returns false if no path is possible, otherwise return
// true and prints the path in the form of 1s. Please note
// that there may be more than one solutions, this function
// prints one of the feasible solutions.
*/
void achaCaminho(Celula **matriz, int numLinhas, int numColunas){

	TipoItem item;
    FPVazia(&pilha);

	int *caminho = malloc((numLinhas*numColunas)*sizeof(int));
	caminho = criaCaminho(numLinhas, numColunas);

	//printaCaminho(caminho, numLinhas, numColunas);
	
	int indiceCaminho = 0;
	
	if (confereCaminho(matriz, numLinhas, numColunas, numLinhas-1, numColunas-1, &pilha, caminho, &indiceCaminho) == false) {
		printf("\n\nImpossivel!");
		return;
	}

	for(int i = 0; i < Tamanho(pilha); i++){ 
		Desempilha (&pilha, &item);
      	printf ("\n\nDesempilhou: %d \n", item.celulaMatriz.valor);
    }
    
	return;
}
void printaCaminho(int *caminho, int numLinha, int numColuna){
	int max = numLinha*numColuna;
	printf("\nCaminho = ");
    for (int i = 0; i < max; i++){
        printf("%d-", caminho[i]);
    }
}
// A recursive utility function to solve Maze problem
bool confereCaminho(Celula **matriz, int numLinhas, int numColunas, int x, int y, TipoPilha* pilha, int *caminho, int *indiceCaminho)
{
	printaCaminho(caminho, numLinhas, numColunas);
	
	TipoItem item;

	printf("\n\n indice %d", *indiceCaminho);
	printf("\n\n caminho[0]: %d", caminho[0]);
	printf("\n\n caminho[*indiceCaminho]: %d", caminho[*indiceCaminho]);
	printf("\n\n matriz[x][y]: %d", matriz[x][y].valor);

	if (x == numLinhas - 1 && matriz[x][y].valor == caminho[*indiceCaminho]) {
		printf("\n\n matriz[x][y]: %d", matriz[x][y].valor);
		item.celulaMatriz = matriz[x][y];
		Empilha(item , pilha);
		return true;
	}
	/*
	// Check if maze[x][y] is valid
	if (isSafe(maze, x, y) == true) {
		// Check if the current block is already part of
		// solution path.
		if (sol[x][y] == 1)
			return false;
		// mark x, y as part of solution path
		sol[x][y] = 1;
		// Move forward in x direction 
		if (solveMazeUtil(maze, x + 1, y, sol) == true)
			return true;
		// If moving in x direction doesn't give solution
		// then Move down in y direction
		if (solveMazeUtil(maze, x, y + 1, sol) == true)
			return true;
		// If none of the above movements work then
		// BACKTRACK: unmark x, y as part of solution path
		Desempilha (&pilha, &item);
		indice --;
		return false;
	}
	*/
	return false;
}

int* criaCaminho(int N, int M){
	int *caminho = calloc((N*M),sizeof(int));
    int max = N*M;
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
	
	// printf("\n\n Caminho = ");
    // for (int i = 0; i < max; i++){
    //      printf("%d - ", *caminho[i]);
    // }

	return caminho;
}

int fibonacci(int n)
{ 
    int i = 1, k, F = 0;
    for (k = 1; k <= n; k++)
    { 
        F += i;  i = F - i;
    }
    return F;
}

