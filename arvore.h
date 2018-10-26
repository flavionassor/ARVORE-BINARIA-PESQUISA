#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
	int chave;
	char nome;
	char ra;
	char cpf;
	char dataN;
	char sexo;
}tAluno;

typedef struct no
{
	struct no *esq, *dir;
	tAluno aluno;
}TNo;

void inicializa(TNo **ptr)
{
	*ptr = NULL;
}

void insere(TNo **ptr, tAluno chave)
{
	if(*ptr == NULL)
	{
		(*ptr) = (TNo *) malloc(sizeof(TNo));
		(*ptr) -> esq = NULL;
		(*ptr) -> dir = NULL;
		(*ptr) -> aluno = chave;
	}else
	{
		if(chave.chave < (*ptr) -> aluno.chave)
		{
			insere(&(*ptr) -> esq, chave);
		}else if(chave.chave > (*ptr) -> aluno.chave)
		{
			insere(&(*ptr) -> dir, chave);
		}
	}
}

void antecessor(TNo *q, TNo **r)
{
	if((*r) -> dir != NULL)
	{
		antecessor(q,&(*r) -> dir);
	}else
	{
		q -> aluno = (*r) -> aluno;
		q = (*r);
		(*r) = (*r) -> esq;
		free(q);
	}
}

void retira(TNo **ptr, int chave)
{
	if((*ptr) == NULL)
	{
		printf("\n A chave #%d não está na árvore!", chave);
	}else if(chave < (*ptr) -> aluno.chave)
	{
		retira(&(*ptr) -> esq, chave);
	}else if(chave > (*ptr) -> aluno.chave)
	{
		retira(&(*ptr) -> dir, chave);
	}else
	{
		TNo *aux = (*ptr);
		if((*ptr) -> dir == NULL)
		{
			(*ptr) = (*ptr)->esq;
			free(aux);
		}else if((*ptr) -> esq == NULL)
		{
			(*ptr) = (*ptr) -> dir;
			free(aux);
		}else
		{
			antecessor((*ptr), &(*ptr) -> esq);
		}
	}
}

void pesquisar(TNo *ptr, int chave)
{
	while((ptr != NULL) && (ptr -> aluno.chave != chave))
	{
		if(chave > ptr -> aluno.chave)
		{	
			ptr = ptr -> dir;
		}else
		{
			ptr = ptr -> esq;
		}
	}
	if(ptr == NULL)
	{
		printf("\nA chave #%d nao esta na arvore!",chave);
	}else
	{
		printf("\nA chave #%d esta na arvore!",chave);
	}
}


//buscar o pai------------------------------------------------------------------------------------------//
void pesq(TNo *ptr,int chave)
{
	
	if(ptr->esq != NULL)
	{
		if(ptr -> esq -> aluno.chave == chave)
		{
			printf("\n O pai eh: %d", ptr->aluno.chave);
		}else
		{
			pesq(ptr -> esq,chave);
		}
	}
	if(ptr->dir != NULL)
	{
		if(ptr -> dir -> aluno.chave == chave)
		{
			printf("\n O pai eh: %d", ptr->aluno.chave);
		}else
		{
			pesq(ptr -> dir,chave);
		}
	}
}
void pesquisarPai(TNo *ptr, int chave)
{	
	pesquisar(ptr,chave);
	if(ptr->aluno.chave == chave)
	{
		printf("Nao tem pai pois está na raiz\n");
	}else
	{	
		pesq(ptr,chave);
	}
}

//Fim buscar o Pai --------------------------------------------------------------------//


//buscar o irmao -----------------------------------------------------------------------------------------//
void pesqI(TNo *ptr,int chave)
{
	
	if(ptr->esq != NULL)
	{
		if(ptr -> esq -> aluno.chave == chave)
		{
			if(ptr-> dir != NULL)
			{
				printf("\n O irmao eh: %d", ptr-> dir -> aluno.chave);
			}else
			{
				printf("\nNão possui irmao!");
			}
			
		}else
		{
			pesq(ptr -> esq,chave);
		}
	}
	if(ptr->dir != NULL)
	{
		if(ptr -> dir -> aluno.chave == chave)
		{
			if(ptr-> esq != NULL)
			{
				printf("\n O irmao eh: %d", ptr-> esq -> aluno.chave);
			}else
			{
				printf("\nNão possui irmao!");
			}
		}else
		{
			pesq(ptr -> dir,chave);
		}
	}
}
void pesquisarIrmao(TNo *ptr, int chave)
{	
	pesquisar(ptr,chave);
	if(ptr->aluno.chave == chave)
	{
		printf("Nao tem pai pois está na raiz\n");
	}else
	{	
		pesqI(ptr,chave);
	}
}

//Fim buscar o irmao --------------------------------------------------------------------//
void exibir(tAluno ptr)
{
	printf("\n***************");
	printf("\n* chave: %d   ",ptr.chave);
	printf("\n* cpf: %c     ",ptr.cpf);
	printf("\n* dataN: %c   ",ptr.dataN);
	printf("\n* nome: %c    ",ptr.nome);
	printf("\n* ra: %c      ",ptr.ra);
	printf("\n* sexo: %c    ",ptr.sexo);
	printf("\n***************");	
}

void in_ordem(TNo *ptr)
{
	if(ptr != NULL)
	{
		in_ordem(ptr -> esq);
		exibir(ptr -> aluno);
		in_ordem(ptr -> dir);
	}
}

void pre_ordem(TNo *ptr)
{
	if(ptr != NULL)
	{
		exibir(ptr -> aluno);
		pre_ordem(ptr -> esq);		
		pre_ordem(ptr -> dir);
	}
}

void pos_ordem(TNo *ptr)
{
	if(ptr != NULL)
	{		
		pos_ordem(ptr -> esq);		
		pos_ordem(ptr -> dir);
		exibir(ptr -> aluno);
	}
}




