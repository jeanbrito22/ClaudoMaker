#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_clientes.h"
#include "contabiliza_cadastro.h"
#include "struct_laudos.h"
#include "contabiliza_laudo.h"
int main()
{
	int opcao, qt_clientes, i, j, check_cpf, check_laudo = 0;

	printf("Digite a opcao desejada:\n[1] Cadastrar Cliente\n[2] Criar Laudo\n[3] Consultar Laudo\n[4] Sair:\n\n");
	scanf("%d", &opcao);
	printf("\nOpcao escolhida: ");
	
	switch(opcao){
		case 1:
			
			printf("Cadastrar Cliente\n");
			
			
			FILE *pf;
			pf = fopen("contabiliza_cadastro.bin", "rb");
			fread(&qt_clientes, sizeof(int), 1, pf);
			fclose(pf); 

			if(qt_clientes == 0){
				//Criando o cliente e chamando as funcoes do "struct_clientes.h" para preenchimento dos dados do cliente.
				clientes cliente;
				preencher_cliente(&cliente);
				exibir_cliente(cliente); //exibindo os dados do cliente para ver se esta correto.
				//armazenar os clientes(struct) em um arquivo .bin
				FILE *pf;
				pf = fopen("clientes.bin", "wb");
				fwrite(&cliente, sizeof(cliente), 1, pf);
				fclose(pf);
				contabiliza_cadastro();
			}else{
				// Quantidade de clientes para se armazenar no vetor da struct.
				clientes cliente_cadastrado[qt_clientes];
				// Guardando todos os clientes cadastrados no vetor da struct clientes.
				pf = fopen("clientes.bin", "rb");
				fread(&cliente_cadastrado, sizeof(cliente_cadastrado), 1, pf);
				fclose(pf);

				printf("\nNUMERO DE CLIENTES CADASTRADOS: %d\n", qt_clientes);
				printf("CNPJS CADASTRADOS: \n");
				for (i = 0; i < qt_clientes; i++){
					printf("%s\n",cliente_cadastrado[i].cnpj);
				}
				printf("\n");

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
						printf("\nCNPJ ja cadastrado!!\n");
						break;
					}else{
						pf = fopen("clientes.bin", "a+b");
						fwrite(&cliente, sizeof(cliente), 1, pf);
						fclose(pf);
						contabiliza_cadastro();
						break;
					}
				}

			}
		break;
		
		case 2:
			
			printf("Criar Laudo\n");
			
			laudos laudo;
			preencher_laudo(&laudo);

			pf = fopen("contabiliza_cadastro.bin", "rb");
			fread(&qt_clientes, sizeof(int), 1, pf);
			fclose(pf); 

			if (qt_clientes == 0)
				printf("Nao ha clientes cadastrados\n");
			else{
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
						printf("\nCliente cadastrado\n");
						printf("Cliente: %s\n", cliente_cadastrado[i].nome);
						exibir_laudo(laudo);
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

			break;
		case 3:
			printf("Consultar Laudo\n");
			break;
		case 4:
			printf("Sair\n");
			break;
		default:
			printf("Opcao invalida\n");
	}

		printf("\n");
	return 0;
}
