#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_clientes.h"
#include "contabiliza_cadastro.h"
#include "struct_laudos.h"
#include "contabiliza_laudo.h"
int main()
{
	int var, qt_clientes, i, j, check_cpf, check_laudo = 0;

	do {
		system("cls || clear");
		printf("*----------------------------------------------------------------------------------------------*\n");
		printf("*                                        LAUDO DE MAKER                                        *\n");
		printf("*----------------------------------------------------------------------------------------------*\n\n");
        printf("Escolha a opcao Desejada:\n\n");
        printf("\tDigite 1 - Para Cadastro de Clientes\n\n");
        printf("\tDigite 2 - Para Elaboracao de Laudos\n\n");
        printf("\tDigite 0 - Para Sair\n");
        printf("\nOpcao....> ");
        scanf("%d", &var);
		switch(var){
			case 1:
				system("cls || clear");
				printf("*----------------------------------------------------------------------------------------------*\n");
				printf("*                                   CADASTRO DE CLIENTE                                        *\n");
				printf("*----------------------------------------------------------------------------------------------*\n\n");


				FILE *pf;
				pf = fopen("contabiliza_cadastro.bin", "rb");
				if(!pf){
					printf("Erro na abertura do arquivo");
					exit(0);
				}

				if(fread(&qt_clientes, sizeof(int), 1, pf) != 1){
					printf("Erro na leitura do arquivo");
				}
				fclose(pf);

				if(qt_clientes == 0){
					//Criando o cliente e chamando as funcoes do "struct_clientes.h" para preenchimento dos dados do cliente.
					clientes cliente;
					preencher_cliente(&cliente);
					exibir_cliente(cliente); //exibindo os dados do cliente para ver se esta correto.
					//armazenar os clientes(struct) em um arquivo .bin
					pf = fopen("clientes.bin", "wb");
					if (!pf){
						printf("Erro na abertura do arquivo\n");
						exit(1);
					}
					if(fwrite(&cliente, sizeof(cliente), 1, pf) != 1){
						printf("Erro na escrita do arquivo\n");
					}
					contabiliza_cadastro();
					fclose(pf);
				}else{
					// Quantidade de clientes para se armazenar no vetor da struct.
					clientes cliente_cadastrado[qt_clientes];
					// Guardando todos os clientes cadastrados no vetor da struct clientes.
					pf = fopen("clientes.bin", "rb");
					if(!pf){
						printf("Erro na abertura do arquivo\n");
						exit(1);
					}
					if(fread(&cliente_cadastrado, sizeof(cliente_cadastrado), 1, pf) != 1){
						printf("erro na leitura do arquivo\n");
					}
					fclose(pf);

					printf("\n\n\nNUMERO DE CLIENTES CADASTRADOS: %d\n\n\n", qt_clientes);
					printf("CNPJS CADASTRADOS: \n");
					for (i = 0; i < qt_clientes; i++){
						printf("%s\n",cliente_cadastrado[i].cnpj);
					}
					printf("\n\n\n");

					clientes cliente;
					preencher_cliente(&cliente);
					exibir_cliente(cliente);

					for (i = 0; i < qt_clientes; i++){
						check_cpf = 0;
						for (j = 0; j < 14; j++){
							if (cliente_cadastrado[i].cnpj[j] == cliente.cnpj[j]){
								check_cpf++;
							}
						}

						if (check_cpf == 14){
							printf("*----------------------------------------------------------------------------------------------*\n");
							printf("*                                   CNPJ JA CADASTRADO                                         *\n");
							printf("*----------------------------------------------------------------------------------------------*\n\n");
							break;
						}else{
							printf("*----------------------------------------------------------------------------------------------*\n");
							printf("*                                   CLIENTE CADASTRADO COM SUCESSO                             *\n");
							printf("*----------------------------------------------------------------------------------------------*\n\n");
							pf = fopen("clientes.bin", "ab");
							if(!pf){
								printf("erro na abertura do arquivo\n");
								exit(1);
							}
							if(fwrite(&cliente, sizeof(cliente), 1, pf) != 1){
								printf("erro na abertura do arquivo\n");
								contabiliza_cadastro();
							}
							fclose(pf);
							break;
						}
					}

				}
				system("pause || echo Presione ENTER para continuar... && sed -n q </dev/tty");
				system("cls || clear");
			break;

			case 2:
				system("cls || clear");
				printf("*----------------------------------------------------------------------------------------------*\n");
				printf("*                                   ELABORACAO DE LAUDO                                        *\n");
				printf("*----------------------------------------------------------------------------------------------*\n\n");

				laudos laudo;
				preencher_laudo(&laudo);

				pf = fopen("contabiliza_cadastro.bin", "rb");
				fread(&qt_clientes, sizeof(int), 1, pf);
				fclose(pf);

				if (qt_clientes == 0){
					printf("*----------------------------------------------------------------------------------------------*\n");
					printf("*                                        NAO HA CLIENTES CADASTRADOS                           *\n");
					printf("*----------------------------------------------------------------------------------------------*\n\n");
				}else{

					clientes cliente_cadastrado[qt_clientes];

					pf = fopen("clientes.bin", "rb");
					fread(&cliente_cadastrado, sizeof(cliente_cadastrado), 1, pf);
					fclose(pf);

					for (i = 0; i < qt_clientes; i++){
						check_cpf = 0;
						for (j = 0; j < 14; j++){
							if (cliente_cadastrado[i].cnpj[j] == laudo.cnpj[j]){
								check_cpf++;
							}
						}

						if (check_cpf == 14){
							check_laudo = 1;
							printf("*----------------------------------------------------------------------------------------------*\n");
							printf("*                                   LAUDO CADASTRADO COM SUCESSO                              *\n");
							printf("*----------------------------------------------------------------------------------------------*\n\n");

							printf("Cliente: %s\n", cliente_cadastrado[i].nome);
							exibir_laudo(laudo);
							printf("\n");
							break;
						}else{
							printf("Nenhum cliente foi encotrado com esse CNPJ.\n");
							break;
							}
					}

					if (check_laudo == 1){
						pf = fopen("laudos.bin", "wb");
						fwrite(&laudo, sizeof(laudo), 1, pf);
						fclose(pf);
						contabiliza_laudo();
					}

				}
				system("pause || echo Presione ENTER para continuar... && sed -n q </dev/tty");

				break;
			case 0:
				printf("*----------------------------------------------------------------------------------------------*\n");
				printf("*                                   VOCE SAIU DO LAUDO MAKER                                   *\n");
				printf("*----------------------------------------------------------------------------------------------*\n\n");
				break;
			default:
				system("cls || clear");
				printf("Opcao invalida\n");
		}

	} while(var != 0);

		printf("\n");
	return 0;
}
