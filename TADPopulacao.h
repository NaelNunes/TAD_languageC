//Estruturas de Dados
struct TpCidade
{
	char Nome[50];
	int Populacao;
};

//Protótipos das Operações Associadas
void Cadastrar(void);
void InserirRegistro(FILE *PtrArq, TpCidade Reg);
int BuscarNome(FILE *PtrArq, char NomeCidade[50]);
void Relatorio(void);
void Ordenar(void);
void Consultar(void);

//Operações Associadas
void Cadastrar(void)
{
	FILE *PtrArq = fopen("Cidades.dat","ab+");
	TpCidade RCidade;
	printf("\n*** Cadastrar Cidades ***\n");
	printf("Cidade: ");
	fflush(stdin);
	gets(RCidade.Nome);
	while (strcmp(RCidade.Nome,"\0")!=0)
	{
		printf("Populacao: ");
		scanf("%d",&RCidade.Populacao);
		InserirRegistro(PtrArq,RCidade);
		
		printf("\nCidade: ");
		fflush(stdin);
		gets(RCidade.Nome);	
	}
	fclose(PtrArq);
}

int BuscarNome(FILE *PtrArq, char NomeCidade[50])
{
	TpCidade Reg;
	rewind(PtrArq);
	
	fread(&Reg, sizeof(TpCidade), 1, PtrArq);
	while(strcmp(Reg.Nome,NomeCidade) != 0 && !feof(PtrArq))
		fread(&Reg, sizeof(TpCidade), 1, PtrArq);
		
	if(feof(PtrArq))
		return -1;
	else 
		return ftell(PtrArq) - sizeof(TpCidade);
}

void Relatorio(void)
{
	FILE *PtrArq = fopen("Cidades.dat", "rb");
	TpCidade Reg;
	
	fread(&Reg, sizeof(TpCidade), 1, PtrArq);
	while(!feof(PtrArq))
	{
		printf("Nome da cidade: %s", Reg.Nome);
		printf("Populacao da cidade: %d", Reg.Populacao);
		fread(&Reg, sizeof(TpCidade), 1, PtrArq);	
	}
	fclose(PtrArq);

}

void OrdenarNome(void)
{
	FILE *PtrArq = fopen("Cidades.dat", "rb+");
	TpCidade Reg;
	TpCidade Reg1;
	
	int a, b, contPos;
	
	fseek(PtrArq, 2, 0);
	contPos = ftell(PtrArq)/sizeof(TpCidade);
	
	for(a = 0; a < contPos - 1; a++)
	{
		for(b = a + 1; b < contPos; b++)
		{
			fseek(PtrArq, 0, a*contPos);
			fread(&Reg, sizeof(TpCidade), 1, PtrArq);
			
			fseek(PtrArq, 0, b*contPos);
			fread(&Reg1, sizeof(TpCidade), 1, PtrArq);
			
			if(strcmp(Reg.Nome,Reg1.Nome) > 0)
			{
				fseek(PtrArq, 0, b*contPos);
				fwrite(&Reg, sizeof(TpCidade), 1, PtrArq);
			
				fseek(PtrArq, 0, a*contPos);
				fwrite(&Reg1, sizeof(TpCidade), 1, PtrArq);
			}
		}
	}
	fclose(PtrArq);
}

void OrdenarPop(void)
{
	FILE *PtrArq = fopen("Cidades.dat", "rb+");
	TpCidade Reg;
	TpCidade Reg1;
	
	int a, b, contPos;
	
	fseek(PtrArq, 2, 0);
	contPos = ftell(PtrArq)/sizeof(TpCidade);
	
	for(a = 0; a < contPos - 1; a++)
	{
		for(b = a + 1; b < contPos; b++)
		{
			fseek(PtrArq, 0, a*contPos);
			fread(&Reg, sizeof(TpCidade), 1, PtrArq);
			
			fseek(PtrArq, 0, b*contPos);
			fread(&Reg1, sizeof(TpCidade), 1, PtrArq);
			
			if(Reg.Populacao > Reg1.Populacao)
			{
				fseek(PtrArq, 0, b*contPos);
				fwrite(&Reg, sizeof(TpCidade), 1, PtrArq);
			
				fseek(PtrArq, 0, a*contPos);
				fwrite(&Reg1, sizeof(TpCidade), 1, PtrArq);
			}
		}
	}
	fclose(PtrArq);
}

void Consultar(void)
{
	FILE *PtrArq = fopen("Cidades.dat", "rb");
	TpCidade Reg;
	int pos;
	
	printf("Digite o nome da cidade para buscar: ");
	fflush(stdin);
	gets(Reg.Nome);
	while(strcmp(Reg.Nome,"\0") != 0)
	{
		pos = BuscarNome(PtrArq, Reg.Nome);
		if(pos == -1)
		{
			printf("Cidade nao encontrada!");
		} else {
			fseek(PtrArq, 0, pos);
			fread(&Reg, sizeof(TpCidade), 1, PtrArq);
			printf("Cidade: %s", Reg.Nome);
			printf("Populacao: %d", Reg.Populacao);
			printf("Posicao: %d", pos);		
		}	
		
		printf("Digite o nome da cidade para buscar: ");
		fflush(stdin);
		gets(Reg.Nome);
	}
	fclose(PtrArq);
}

void InserirRegistro(FILE *PtrArq, TpCidade Reg)
{
	fwrite(&Reg,sizeof(TpCidade),1,PtrArq);
}







