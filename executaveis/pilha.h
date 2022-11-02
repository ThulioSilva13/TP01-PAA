#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matriz.h"

//typedef int TipoChave;
typedef struct TipoItem {
  Celula celulaMatriz;
} TipoItem;

typedef struct TipoCelula *TipoApontadorPilha;
typedef struct TipoCelula {
  TipoItem Item;
  TipoApontadorPilha Prox;
} TipoCelula;

typedef struct {
  TipoApontadorPilha Fundo, Topo;
  int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha *Pilha);

int Vazia(TipoPilha Pilha);

void Empilha(TipoItem x, TipoPilha *Pilha);

void Desempilha(TipoPilha *Pilha, TipoItem *Item);

int Tamanho(TipoPilha Pilha);

void imprimePilhaInvertida(TipoPilha *pilhaAuxiliar);

void invertePilha(TipoPilha *pilha);


