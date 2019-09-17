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
int opc; // SELETOR DE OP��O

int main(void) {
	setlocale(LC_ALL, "Portuguese"); // PERMITIR CARACTERES ACENTUADOS

	int cont_limite_opc1 = 0; // CONTADOR PARA SAIR DA OP��O 1
	int cont_limite_opc2 = 0; // CONTADOR PARA SAIR DA OP��O 2 
	char caractere; // PARA A OP��O 1
	char frase[TAMFRASE]; // PARA A OP��O 3
	char codigoescrito[TAMFRASE]; // PARA A OP��O 5
	int leitor = 0; // leitor da frase/codigo
inicio:
	system("cls");
	printf("SISTEMA TELEGRAFO Vers�o Alpha 0.7.1\n-----------------------------------------\n");
	printf("Digite o modo de como voc� quer trabalhar\n(1)- Caractere para codigo sonoro\n(2)- Caractere para codigo escrito\n(3)- String para codigo sonoro\n(4)- String para codigo escrito\n(5)- Codigo para string\n(6)- Sair\n-----------------------------------------\n");
	printf("Digite a op��o: "); // SELECIONAR A OP��O
	scanf("%i", &opc);
	printf("-----------------------------------------\n");

	if (opc == 1 || opc == 3) {
		printf("Determine a frequ�ncia da onda do beep em Hertz: "); // SELECIONAR A FREQUENCIA 
		scanf("%i", &FREQ);
		printf("-----------------------------------------\n");
	}
		if (opc == 1) {
			// OP��O 1 - CARACTERE PARA CODIGO SONORO
			while (1) {
				system("cls");
				printf("Digite a caractere (pressione 0 tr�s vezes para sair): ");
				scanf(" %c", &caractere);
				if (caractere == '0') { cont_limite_opc1++; } // CONTADOR PARA SAIR DA OP��O 1
				printf("\nDEBUG: %i \n", cont_limite_opc1);
				if (cont_limite_opc1 >= 3) {
					cont_limite_opc1 = 0;
					goto inicio;
				}
				codigo(caractere);
			}
		}


		if (opc == 3) {
			// OP��O 3 - STRING PARA CODIGO SONORO

			while (1) {
				system("cls");
				printf("Digite os textos (pressione 000 para sair): ");
				fgets(frase, TAMFRASE, stdin);
				if (frase[0] == '0' && frase[1] == '0' && frase[2] == '0') { goto inicio; }
				else {
					for (leitor = 0; frase[leitor] != '\0'; leitor++) {
						codigo(frase[leitor]); // A CADA CARACTERE DA STRING SERA USADO A FUN��O QUE GERA OS BEEPS AT� ENCONTRAR O '\0'
					}
				}
			}
		}


	if (opc == 2) {
		// OP��O 2 - CARACTERE PARA CODIGO ESCRITO
		while (1) {
			system("cls");
			printf("Digite o caractere (pressione 0 tr�s vezes para sair): ");
			scanf(" %c", &caractere);
			if (caractere == '0') { cont_limite_opc2++; } // CONTADOR PARA SAIR DA OP��O 2
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
		// OP��O 4 - STRING PARA CODIGO ESCRITO
		while (1) {
			system("cls");
			printf("Digite o texto (pressione 000 para sair): ");
			fgets(frase, TAMFRASE, stdin);
			if (frase[0] == '0' && frase[1] == '0' && frase[2] == '0') { goto inicio; }

			else {
				for (leitor = 0; frase[leitor] != '\0'; leitor++) {
					codigo(frase[leitor]); // A CADA CARACTERE DA STRING SERA USADO A FUN��O QUE GERA OS PONTOS E TRA�OS AT� ENCONTRAR O '\0'
				}
				printf("\n");
				system("pause");
			}
		}
	}

	if (opc == 5) {
		// OP��O 5 - CODIGO ESCRITO PARA STRING - N�O SEI COMO FA�O ISSO!!!!!!!!!!!
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
		printf("Feito por:\n1- Luciano Pereira de Oliveira Filho\n2- Lucas Isaac Pissaia da Silva \n3- Erika Fernanda Andrade Bezerra\n4- Anthony Gabriel Lopes da Silva\n5- Samuel Torres Louren�o\n\nTURINHO - CIENCIA DA COMPUTA��O 2019.1\n");
		printf("-----------------------------------------\n");
		system("pause");
		return 0;
	}


	return 0;
	/* FALTA:
		USO DO CLEAR SCREEN - ok
		FALAR COM MARITAN
		DESENVOLVER A OP��O 2 - ok ,3 - ok,5
		APLICAR O DELAY ENTRE CARACTERES E FRASES - OK
		INCLUIR OS CARACTERES DE PONTUA��O NA FUN��O CODIGO - ok
		VER SE � POSSIVEL POR O CODIGO ESCRTIO NA FUN��O CODIGO CASO A OP��O SELECIONADA SEJA 2 OU 4 - ok


	 */

	 /* https://morsecode.scphillips.com/morse2.html*/

}
