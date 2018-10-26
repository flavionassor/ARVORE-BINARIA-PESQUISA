#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

main()
{
		int menu=-1,remover=0,percurso=0,chavep=0;
		TNo *ptr;
		inicializa(&ptr);
		tAluno temp;
		temp.chave = 1;
		temp.cpf = '1';
		temp.dataN = '1';
		temp.nome = '1';
		temp.ra = '1';
		temp.sexo = '1';
		insere(&ptr,temp);
		temp.chave = 2;
		temp.cpf = '2';
		temp.dataN = '1';
		temp.nome = '1';
		temp.ra = '1';
		temp.sexo = '1';
		insere(&ptr,temp);
		while(menu != 0)
		{	
			system("cls");
			printf("\n***********************************");
			printf("\n*       Menu de ocoes             *");
			printf("\n*     1- Inserir aluno            *");
			printf("\n*     2- Retirar aluno            *");
			printf("\n*     3- Pesquisar aluno          *");
			printf("\n*     4- Visualizar dados         *");
			printf("\n*     0- Sair                     *");
			printf("\n***********************************\n");
			scanf("%d",&menu);
			switch(menu) 
			{
				case 0:
				break;
				//-------------------------------------------------//
				case 1://Inserir aluno
					system("cls");
					printf("\n Digite a chave\n");
					scanf("%d",&temp.chave);
					printf("\n Digite a cpf\n");
					scanf("%d",&temp.cpf);
					printf("\n Digite a dataN\n");
					scanf("%d",&temp.dataN);
					printf("\n Digite a nome\n");
					scanf("%d",&temp.nome);
					printf("\n Digite a ra\n");
					scanf("%d",&temp.ra);
					printf("\n Digite a sexo\n");
					scanf("%d",&temp.sexo);
					insere(&ptr,temp);
				break;
				//--------------------------------------------------//
				case 2://Retirar Aluno
					system("cls");
					printf("\n Digite a chave\n");
					scanf("%d",&remover);
					retira(&ptr,remover);
				break;
				//--------------------------------------------------//
				case 3://pesquisar chave
					system("cls");
					printf("\n Digite a chave\n");
					scanf("%d",&chavep);
					pesquisarIrmao(ptr,chavep);
					getchar();
					getchar();
				break;
				//--------------------------------------------------//
				case 4:
					system("cls");
					printf("\n***********************************");
					printf("\n*       Menu de percurso          *");
					printf("\n*     1- In-Ordem                 *");
					printf("\n*     2- Pre-Ordem                *");
					printf("\n*     3- Pos-Ordem                *");
					printf("\n***********************************");
					scanf("%d",&percurso);
					switch(percurso)
					{	
						//--------------------------------------------------//
						case 1:
							system("cls");
							in_ordem(ptr);
							getchar();
							getchar();
						break;
						//--------------------------------------------------//
						case 2:
							system("cls");
							pre_ordem(ptr);
							getchar();
							getchar();
						break;
						//--------------------------------------------------//
						case 3:
							system("cls");
							pos_ordem(ptr);
							getchar();
							getchar();
						break;
						//--------------------------------------------------//
						default:
							system("cls");
							printf("valor invalido!");
							getchar();
							getchar();
						break;
					}
				break;
				//--------------------------------------------------//
				default:
				break;
			}
		}
}
