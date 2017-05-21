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
	fwrite(&quantidade, sizeof(int), 1, pf);
	fclose(pf);
	printf("Numero de clientes cadastrados: %d\n", quantidade);
	//fread(&quantidade);
	return;
}
