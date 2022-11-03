
all: 
	gcc main.c ./executaveis/backtracking.c ./executaveis/lerArquivo.c ./executaveis/matriz.c ./executaveis/pilha.c -o main -Wall -lm 
run:
	main
clean:
	rm ./bin/* ./obj/*