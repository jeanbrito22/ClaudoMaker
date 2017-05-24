#include <stdio.h>

int main()
{
	int cadastros, laudos;
	FILE *pf;
	cadastros = 1;
	pf = fopen("contabiliza_cadastro.bin", "rb");
	fread(&cadastros, sizeof(int), 1, pf);
	fclose(pf);
	
	pf = fopen("contabiliza_laudo.bin", "rb");
	fread(&laudos, sizeof(int), 1, pf);
	fclose(pf);
	
	printf("Cadastros criados: %d\n", cadastros);
	printf("Laudos criados: %d\n", laudos);

	return 0;

}
