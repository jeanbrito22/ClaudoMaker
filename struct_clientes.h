typedef struct{
	char cnpj[15];
	char nome[51];
	char endereco[101];
	char email[51];
}clientes;


void preencher_cliente(clientes * c)
{
	printf("CNPJ: ");
	scanf(" %14[^\n]", c->cnpj);
	
	printf("Nome: ");
	scanf(" %50[^\n]", c->nome);

	printf("Endereco: ");
	scanf(" %100[^\n]", c->endereco);

	printf("Email: ");
	scanf(" %50[^\n]", c->email);

}

void exibir_cliente(clientes c)
{

	printf("%s\n", c.cnpj);
	printf("%s\n", c.nome);
	printf("%s\n", c.endereco);
	printf("%s\n", c.email);

	return;
}