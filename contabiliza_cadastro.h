void contabiliza_cadastro(void)
{
	FILE *pf;
	int quantidade, lendo_quantidade;
	//Lendo...
	pf = fopen("contabiliza_cadastro.bin", "rb");
	fread(&lendo_quantidade, sizeof(int), 1, pf);
	fclose(pf);
	//Escrevendo...
	quantidade = lendo_quantidade + 1;
	pf = fopen("contabiliza_cadastro.bin", "wb");
	if(!pf){
		printf("erro na abertura do arquivo");
		exit(1);
	}
	if(fwrite(&quantidade, sizeof(int), 1, pf) != 1){
		printf("Erro na escrita do arquivo\n");
	}
	fclose(pf);
	printf("\n\nNumero de clientes cadastrados: %d\n\n", quantidade);
	//fread(&quantidade);
	return;
}
