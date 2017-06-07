typedef struct{
	char cnpj[15];
	char nome[51];
	char endereco[101];
	char email[51];
}clientes;

void validar_cnpj_cliente(char *cnpj){
	int valido, i;
	do{
		system("cls || clear");
		printf("\nCNPJ........> ");;
		scanf(" %14[^\n]",  cnpj);
		valido = 1;
		for (i = 0; i < strlen(cnpj); i++){
			if (!isdigit(cnpj[i])){
				valido = 0;
				break;
			}
		}
	}while(strlen(cnpj) != 14 ||  valido == 0);
	cnpj[15] = '\0';
	return;
}

void preencher_cliente(clientes * c)
{
	system("cls || clear");
	printf("Digite o CNPJ do Cliente a ser cadastrado .....:\n");
	validar_cnpj_cliente(c->cnpj);
	printf("\n");

	system("cls || clear");
	printf("Digite o Nome do Cliente a ser cadastrado .....:\n");
	printf("\nNome........> ");
	scanf(" %50[^\n]", c->nome);
	printf("\n");

	printf("Digite o Endereco do Cliente a ser cadastrado..:\n");
	printf("\nEndereco....> ");
	scanf(" %100[^\n]", c->endereco);
	printf("\n");
	system("cls || clear");

	printf("Digite o e-mail do Cliente a ser cadastrado ...:\n");
	printf("\nE-Mail......> ");
	scanf(" %50[^\n]", c->email);
	system("cls || clear");

}

void exibir_cliente(clientes c)
{

	printf("CNPJ: %s\n", c.cnpj);
	printf("Nome: %s\n", c.nome);
	printf("Endereco: %s\n", c.endereco);
	printf("E-mail: %s\n", c.email);

	return;
}