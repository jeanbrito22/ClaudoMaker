typedef struct{
	char cnpj[15];
	char nome[51];
	char endereco[101];
	char email[51];
}clientes;

void validar_cnpj_cliente(char *cnpj){
	int valido, i;
	do{
		printf("CNPJ [apenas numeros]: ");
		scanf(" %14[^\n]",  cnpj);
		valido = 1;
		for (i = 0; i < strlen(cnpj); i++){
			if (!isdigit(cnpj[i])){
				valido = 0;
				break;
			}
		}
	}while(strlen(cnpj) != 14 ||  valido == 0);

	return;
}

void preencher_cliente(clientes * c)
{
	validar_cnpj_cliente(c->cnpj);

	printf("Nome: ");
	scanf(" %50[^\n]", c->nome);

	printf("Endereco: ");
	scanf(" %100[^\n]", c->endereco);

	printf("Email: ");
	scanf(" %50[^\n]", c->email);

}

void exibir_cliente(clientes c)
{

	printf("CNPJ: %s\n", c.cnpj);
	printf("Nome: %s\n", c.nome);
	printf("ENdereco: %s\n", c.endereco);
	printf("E-mail: %s\n", c.email);

	return;
}