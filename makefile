
all: 
	gcc main.c ./src/backtracking.c ./src/lerArquivo.c ./src/matriz.c ./src/pilha.c -o main.exe -Wall -lm 
	./main.exe
	
clean:
	rm ./bin/* ./obj/*