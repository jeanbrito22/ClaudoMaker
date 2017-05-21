void contabiliza_laudo(void)
{
	FILE *pf;
	int quantidade, lendo_quantidade;
	//Lendo...
	pf = fopen("contabiliza_laudo.bin", "rb");
	fread(&lendo_quantidade, sizeof(int), 1, pf);
	fclose(pf);
	//Escrevendo...
	quantidade = lendo_quantidade + 1;
	pf = fopen("contabiliza_laudo.bin", "wb");
	fwrite(&quantidade, sizeof(int), 1, pf);
	fclose(pf);
	printf("Numero de laudos cadastrados: %d\n", quantidade);
	return;
}
