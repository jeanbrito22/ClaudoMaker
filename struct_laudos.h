typedef struct{
	char cnpj[15];
	char nome_produto[51];
	int qt_produto;
	char num_chamado[21];
	char opcao_embal[5];
	char estado_embalagem[21];
	char cond_embal[21];
	char opcao_pragas[5];
	char nivel_ident[21];
	char conclusao[200];
}laudos;



void preencher_laudo(laudos *laudo){
	int opcao;
	char sim[] = "Sim", nao[] = "Nao", none[] = "None";

	printf("CNPJ: ");
	scanf(" %14[^\n]", laudo->cnpj);

	printf("Nome do produto: ");
	scanf(" %50[^\n]", laudo->nome_produto);

	printf("Quantidade do produto: ");
	scanf("%d", &laudo->qt_produto);

	printf("Numero do chamado: ");
	scanf(" %20[^\n]", laudo->num_chamado);

	do{
		printf("Os produtos tinham embalagem: [1] SIM [2] NAO: ");
		scanf("%d", &opcao);
	}while(!(opcao == 1 || opcao == 2));

	if (opcao == 1){
		strcat(laudo->opcao_embal, sim);
		
		printf("Qual o estado da embalagem: ");
		scanf(" %20[^\n]", laudo->estado_embalagem);

		printf("Qual a condicao da embalagem: ");
		scanf(" %20[^\n]", laudo->cond_embal);
	}
	else{
		strcat(laudo->opcao_embal, nao);
		strcat(laudo->estado_embalagem, none);
		strcat(laudo->cond_embal, none);
	}


	do{
		printf("Os produtos tinham praga: [1] SIM [2] NAO: ");
		scanf("%d", &opcao);
	}while(!(opcao == 1 || opcao == 2));

	if (opcao == 1){
		strcat(laudo->opcao_pragas, sim);
		printf("Qual o nivel de identificacao? : ");
		scanf(" %20[^\n]", laudo->nivel_ident);

	}
	else{
		strcat(laudo->opcao_pragas, nao);
		strcat(laudo->nivel_ident, none);
	}

	printf("Conclusao: ");
	scanf(" %200[^\n]", laudo->conclusao);


}


void exibir_laudo(laudos laudo){
	printf("CNPJ: %s\n", laudo.cnpj);
	printf("Nome do produto: %s\n", laudo.nome_produto);
	printf("Quantidade do produto: %d\n", laudo.qt_produto);
	printf("Numero do chamado: %s\n", laudo.num_chamado);
	printf("Ha embalagem: %s\n", laudo.opcao_embal);
	printf("Estado da embalagem: %s\n", laudo.estado_embalagem);
	printf("Condicao da embalagem: %s\n", laudo.cond_embal);
	printf("Ha praga: %s\n", laudo.opcao_pragas);
	printf("Nivel de identificacao: %s\n", laudo.nivel_ident);
	printf("Conclusao: %s\n", laudo.conclusao);
	return;
}