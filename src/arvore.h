#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
	int chave;
	char nome[50];
	char ra[50];
	char cpf[50];
	char dataN[50];
	char sexo[50];
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

void antecessor(TNo *q, TNo **r)//encontra valor imediatamento inferior ao valor passado, necessario passar valor a esquerda para que procure o valor imediatamente menor!
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


void sucessor(TNo *q, TNo **r)//é basicamente o inverso da sucessora, pegando o valor imediato a direita para encontrar o menor em seguida!
{
	if((*r) -> esq != NULL)
	{
		antecessor(q,&(*r) -> esq);
	}else
	{
		q -> aluno = (*r) -> aluno;
		q = (*r);
		(*r) = (*r) -> dir;
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

int pesquisar(TNo *ptr, int chave)
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
		return 0;
	}else
	{
		printf("\nA chave #%d esta na arvore!",chave);
		return 1;
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
	int aux;
	aux = pesquisar(ptr,chave);
	if(aux == 0)
	{	
		printf("\nChave não esta na arvore!");
		getchar();
		getchar();					
	}
		
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
			pesqI(ptr -> esq,chave);
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
			pesqI(ptr -> dir,chave);
		}
	}
}
void pesquisarIrmao(TNo *ptr, int chave)
{	
	int aux;
	aux = pesquisar(ptr,chave);
	if(aux == 0)
	{	
		printf("\nChave não esta na arvore!");
		getchar();
		getchar();					
	}
	if(ptr->aluno.chave == chave)
	{
		printf("Nao tem irmao pois está na raiz\n");
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
	printf("\n* cpf: %s     ",ptr.cpf);
	printf("\n* dataN: %s   ",ptr.dataN);
	printf("\n* nome: %s    ",ptr.nome);
	printf("\n* ra: %s      ",ptr.ra);
	printf("\n* sexo: %s    ",ptr.sexo);
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




