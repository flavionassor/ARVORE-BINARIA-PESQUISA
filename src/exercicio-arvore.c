#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include <string.h>

main()
{
		int menu=-1,remover=0,percurso=0,chavep=0, pesquisarc,igualdade=2, contador=0,opcao=0;
		TNo *ptr;
		inicializa(&ptr);
		tAluno temp;
		int chaveTemp;	
		
		system("cls");
			printf("\n***********************************");
			printf("\n*       Menu de ocoes             *");
			printf("\n*     1- Ler arquivo              *");
			printf("\n* Qualquer outra tecla para pular *");
			printf("\n***********************************\n");
			scanf("%d",&opcao);
			
		switch(opcao)
		{			
			case 1:
				printf("Lendo arquivo!\n");
				FILE *pont_arq;
				char texto_str[50];
				  
				//abrindo o arquivo_frase em modo "somente leitura"
				pont_arq = fopen("teste.dat", "r");
				  
				//enquanto não for fim de arquivo o looping será executado
				//e será impresso o texto
				while(!feof(pont_arq))
				{ 
					if(contador < 6)
					{
						if(contador == 0)
						{
							fscanf(pont_arq,"%d",&chaveTemp);
							temp.chave = chaveTemp;
							contador++;
							printf("%d\n",chaveTemp);
							fgets(texto_str, 20, pont_arq);
						}else
						{
								if(contador == 1)
							{
								fgets(texto_str, 20, pont_arq);
								strcpy(temp.cpf,texto_str);
								contador++;
								puts(texto_str);
							}else
							{
									if(contador == 2)
								{
									fgets(texto_str, 20, pont_arq);
									strcpy(temp.dataN,texto_str);
									contador++;
									puts(texto_str);
								}else
								{
										if(contador == 3)
									{
										fgets(texto_str, 20, pont_arq);
										strcpy(temp.nome,texto_str);
										contador++;
										puts(texto_str);
									}else
									{
											if(contador == 4)
										{
											fgets(texto_str, 20, pont_arq);
											strcpy(temp.ra,texto_str);
											contador++;
											puts(texto_str);
										}else
										{
												if(contador == 5)
											{
												fgets(texto_str, 20, pont_arq);
												strcpy(temp.sexo,texto_str);
												contador++;
												puts(texto_str);
											}
										}
									}
								}
							}
						}				
					}else
					{
						contador=0;
						insere(&ptr,temp);
						fgets(texto_str, 20, pont_arq);
					}
					
				}
				
				
				  
				//fechando o arquivo
				fclose(pont_arq);
			break;
			//-------------------------------------------------//
			default:
			break;
		}
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
							fflush(stdin);
							printf("\n Digite a chave\n");
							scanf("%d",&temp.chave);
							fflush(stdin);
							
							igualdade = pesquisar(ptr,temp.chave);
							if(igualdade == 0)
							{
								printf("\n Digite a cpf\n");
								gets(temp.cpf);
								fflush(stdin);
								printf("\n Digite a dataN\n");
								gets(temp.dataN);
								fflush(stdin);
								printf("\n Digite a nome\n");
								gets(temp.nome);
								fflush(stdin);
								printf("\n Digite a ra\n");
								gets(temp.ra);
								fflush(stdin);
								printf("\n Digite a sexo\n");
								gets(temp.sexo);
								fflush(stdin);					
							
								insere(&ptr,temp);
							}
							
							
							
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
							printf("\n***********************************");
							printf("\n*       Menu de pesquisa          *");
							printf("\n*     1- Pesquisar na arvore      *");
							printf("\n*     2- pesquisar pai            *");
							printf("\n*     3- pesquisar irmao          *");
							printf("\n***********************************");
							scanf("%d",&pesquisarc);					
							switch(pesquisarc)
							{
								case 1:
									system("cls");
									printf("\n Digite a chave\n");
									scanf("%d",&chavep);
									pesquisar(ptr,chavep);
									getchar();
									getchar();
								break;
								//--------------------------------------------------//
								case 2:
									system("cls");
									printf("\n Digite a chave\n");
									scanf("%d",&chavep);
									pesquisarPai(ptr,chavep);
									getchar();
									getchar();
								break;
								//--------------------------------------------------//
								case 3:
									system("cls");
									printf("\n Digite a chave\n");
									scanf("%d",&chavep);
									pesquisarIrmao(ptr,chavep);
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
