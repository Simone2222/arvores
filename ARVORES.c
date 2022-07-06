#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define E 0
#define D 1
#define R -1

typedef struct NO {
	int dado;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
} NO;

typedef struct ARVORE{
	NO *raiz;
}ARVORE;

ARVORE a;

void inicializaArvore(ARVORE arv);
void inicializaNo(NO* n, int val);
void insereNoArvoreOrdenada(int valor);
void preOrdem(NO* raiz);
void emOrdem(NO* raiz);
void posOrdem(NO* raiz);

void inicializaArvore(ARVORE arv)
{
	arv.raiz = NULL;
}

void inicializaNo(NO* n, int val){
	if(!n)
	{
		printf("Falha de alocacao.\n");
		return;
	}
	n->pai = NULL;
	n->esq = NULL;
	n->dir = NULL;
	n->dado = val;
}

void insereNoArvoreOrdenada(int valor)
{
	NO* corrente = a.raiz;
	NO* pai;

	NO* novoNo = (NO*) malloc(sizeof(NO));
	inicializaNo(novoNo, valor);
	printf("Inserindo no %d. \n", novoNo->dado);
	
	if(corrente == NULL)
	{
		a.raiz = novoNo;
		printf("No inserido na raiz. \n");
		return;
	}
	
	while(corrente){
		pai = corrente;
		if(novoNo->dado < corrente->dado){
			corrente = corrente->esq;
			if(!corrente){
				printf("No inserido a esquerda do no %d. \n", pai->dado);
				pai->esq = novoNo;
				return;
			}
		}
		else{
			corrente = corrente->dir;
			if(!corrente){
				printf("No inserido a direita do no %d. \n", pai->dado);
				pai->dir = novoNo;
				return;
			}
		}
	}
}


void preOrdem(NO* raiz){
	if(raiz){
		printf("%d \t", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}


int main()
{
	setlocale(LC_ALL, "Portuguese");
	inicializaArvore(a);
	
	insereNoArvoreOrdenada(2);
	insereNoArvoreOrdenada(1);
	insereNoArvoreOrdenada(0);
	insereNoArvoreOrdenada(1);
	insereNoArvoreOrdenada(9);
	insereNoArvoreOrdenada(9);
	insereNoArvoreOrdenada(0);
	insereNoArvoreOrdenada(4);
	
	printf("\nBusca pre ordem: \n");
	preOrdem(a.raiz);
	
}

