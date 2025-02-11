#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "TADPopulacao.h"

char Menu(void)
{
	clrscr();
	printf("\n# # #  M E N U  # # #\n");
	printf("[A] Cadastrar Cidades\n");
	printf("[B] Consultar Cidades pelo Nome\n");
	printf("[C] Ordenar Cidades pelo Nome\n");
	printf("[D] Ordenar Cidades pela Populacao\n");
	printf("[ESC] Finalizar\n");
	printf("\nOpcao desejada: \n");
	return toupper(getch());
}

void Executar(void)
{
	char opcao;
	do
	{
		opcao = Menu();
		switch (opcao)
		{
			case 'A': clrscr();
					  Cadastrar();
					  break;
			
			case 'B': clrscr();
					  Consultar();
					  break;
					  
			case 'C': clrscr();
					  OrdenarNome();
					  break;
					  
			case 'D': clrscr();
					  OrdenarPop();
					  break;
		}
	}while (opcao!=27);
}

int main(void)
{
	Executar();
	return 0;
}
