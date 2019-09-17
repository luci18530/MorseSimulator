#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "codigos.h"
#include "function5.h"
#include "pch.h"

int FREQ; //FREQUENCIA DO BEEP
int opc; // SELETOR DE OPÇÃO

int main(void) {
	setlocale(LC_ALL, "Portuguese"); // PERMITIR CARACTERES ACENTUADOS

	int cont_limite_opc1 = 0; // CONTADOR PARA SAIR DA OPÇÃO 1
	int cont_limite_opc2 = 0; // CONTADOR PARA SAIR DA OPÇÃO 2 
	char caractere; // PARA A OPÇÃO 1
	char frase[TAMFRASE]; // PARA A OPÇÃO 3
	char codigoescrito[TAMFRASE]; // PARA A OPÇÃO 5
	int leitor = 0; // leitor da frase/codigo
inicio:
	system("cls");
	printf("SISTEMA TELEGRAFO Versão Alpha 0.7.1\n-----------------------------------------\n");
	printf("Digite o modo de como você quer trabalhar\n(1)- Caractere para codigo sonoro\n(2)- Caractere para codigo escrito\n(3)- String para codigo sonoro\n(4)- String para codigo escrito\n(5)- Codigo para string\n(6)- Sair\n-----------------------------------------\n");
	printf("Digite a opção: "); // SELECIONAR A OPÇÃO
	scanf("%i", &opc);
	printf("-----------------------------------------\n");

	if (opc == 1 || opc == 3) {
		printf("Determine a frequência da onda do beep em Hertz: "); // SELECIONAR A FREQUENCIA 
		scanf("%i", &FREQ);
		printf("-----------------------------------------\n");
	}
		if (opc == 1) {
			// OPÇÃO 1 - CARACTERE PARA CODIGO SONORO
			while (1) {
				system("cls");
				printf("Digite a caractere (pressione 0 três vezes para sair): ");
				scanf(" %c", &caractere);
				if (caractere == '0') { cont_limite_opc1++; } // CONTADOR PARA SAIR DA OPÇÃO 1
				printf("\nDEBUG: %i \n", cont_limite_opc1);
				if (cont_limite_opc1 >= 3) {
					cont_limite_opc1 = 0;
					goto inicio;
				}
				codigo(caractere);
			}
		}


		if (opc == 3) {
			// OPÇÃO 3 - STRING PARA CODIGO SONORO

			while (1) {
				system("cls");
				printf("Digite os textos (pressione 000 para sair): ");
				fgets(frase, TAMFRASE, stdin);
				if (frase[0] == '0' && frase[1] == '0' && frase[2] == '0') { goto inicio; }
				else {
					for (leitor = 0; frase[leitor] != '\0'; leitor++) {
						codigo(frase[leitor]); // A CADA CARACTERE DA STRING SERA USADO A FUNÇÃO QUE GERA OS BEEPS ATÉ ENCONTRAR O '\0'
					}
				}
			}
		}


	if (opc == 2) {
		// OPÇÃO 2 - CARACTERE PARA CODIGO ESCRITO
		while (1) {
			system("cls");
			printf("Digite o caractere (pressione 0 três vezes para sair): ");
			scanf(" %c", &caractere);
			if (caractere == '0') { cont_limite_opc2++; } // CONTADOR PARA SAIR DA OPÇÃO 2
			if (cont_limite_opc2 >= 3) {
				cont_limite_opc2 = 0;
				goto inicio;

			}
			codigo(caractere);
			printf("\n");
			system("pause");
		}
	}

	if (opc == 4) {
		// OPÇÃO 4 - STRING PARA CODIGO ESCRITO
		while (1) {
			system("cls");
			printf("Digite o texto (pressione 000 para sair): ");
			fgets(frase, TAMFRASE, stdin);
			if (frase[0] == '0' && frase[1] == '0' && frase[2] == '0') { goto inicio; }

			else {
				for (leitor = 0; frase[leitor] != '\0'; leitor++) {
					codigo(frase[leitor]); // A CADA CARACTERE DA STRING SERA USADO A FUNÇÃO QUE GERA OS PONTOS E TRAÇOS ATÉ ENCONTRAR O '\0'
				}
				printf("\n");
				system("pause");
			}
		}
	}

	if (opc == 5) {
		// OPÇÃO 5 - CODIGO ESCRITO PARA STRING - NÃO SEI COMO FAÇO ISSO!!!!!!!!!!!
		while (1) {
		marcador:
			system("cls");
			printf("Digite o codigo (para voltar escreva SAIR): ");
			fgets(codigoescrito, TAMFRASE, stdin);
			if (codigoescrito[0] == 'S' && codigoescrito[1] == 'A' && codigoescrito[2] == 'I' && codigoescrito[3] == 'R') { break; }
			else {
				parsemorse(codigoescrito);
			}
				system("pause");
			}
	}

	if (opc == 6) {
		system("cls");
		printf("OBRIGADO POR USAR NOSSO PROGRAMA!\n");
		printf("-----------------------------------------\n");
		printf("Feito por:\n1- Luciano Pereira de Oliveira Filho\n2- Lucas Isaac Pissaia da Silva \n3- Erika Fernanda Andrade Bezerra\n4- Anthony Gabriel Lopes da Silva\n5- Samuel Torres Lourenço\n\nTURINHO - CIENCIA DA COMPUTAÇÃO 2019.1\n");
		printf("-----------------------------------------\n");
		system("pause");
		return 0;
	}


	return 0;
	/* FALTA:
		USO DO CLEAR SCREEN - ok
		FALAR COM MARITAN
		DESENVOLVER A OPÇÃO 2 - ok ,3 - ok,5
		APLICAR O DELAY ENTRE CARACTERES E FRASES - OK
		INCLUIR OS CARACTERES DE PONTUAÇÃO NA FUNÇÃO CODIGO - ok
		VER SE É POSSIVEL POR O CODIGO ESCRTIO NA FUNÇÃO CODIGO CASO A OPÇÃO SELECIONADA SEJA 2 OU 4 - ok


	 */

	 /* https://morsecode.scphillips.com/morse2.html*/

}
