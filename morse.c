#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "codigo.h"
#include "function5.h"

int FREQ; //FREQUENCIA DO BEEP
int opc; // SELETOR DE OP��O
int opc6;

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
	printf("SISTEMA TELEGRAFO Vers�o Beta 0.9.9\n-----------------------------------------\n");
	printf("Digite o modo de como voc� quer trabalhar\n(1) - Caractere para codigo sonoro\n(2) - Caractere para codigo escrito\n(3) - String para codigo sonoro\n(4) - String para codigo escrito\n(5) - Codigo para string\n(6) - Sobre\n(7) - Sair\n-----------------------------------------\n");
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
			printf("Digite os textos (digite 000 para sair): ");
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
		getchar();
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
		// OP��O 5 - CODIGO ESCRITO PARA STRING
		getchar();
		while (1) {
			system("cls");
			printf("Digite o codigo (para voltar escreva SAIR): ");
			fgets(codigoescrito, TAMFRASE, stdin);
			int lol = 1;
			while (lol <= TAMFRASE)
			{
				if (codigoescrito[lol] == '\n')
				{
					codigoescrito[lol] = '\0';
				}
				lol++;
			}
			if (codigoescrito[0] == 'S' && codigoescrito[1] == 'A' && codigoescrito[2] == 'I' && codigoescrito[3] == 'R') { goto inicio; }
			else {
				parsemorse(codigoescrito);
			}
			system("pause");
		}
	}
	
	if (opc == 6){
        op6:
        system("cls");
        
        printf("-----------------------------------\n");
        printf("(1) - Hist�ria do Codigo Morse\n");
        printf("(2) - Funcionamento do Codigo Morse\n");
        printf("(3) - Tabela do c�digo\n");
        printf("-----------------------------------\n");
        printf("Digite outro numero para voltar\n");
        printf("-----------------------------------\n");
        printf("Digite a op��o: ");
        scanf("%i", &opc6);
            if (opc6 == 1){
                system("cls");
                printf("Desenvolvido em 1835, pelo pintor e inventor Samuel Finley Breese Morse, o C�digo Morse � um sistema bin�rio de representa��o � dist�ncia de n�meros, letras e sinais gr�ficos, utilizando-se de sons curtos e longos, al�m de pontos e tra�os para transmitir mensagens.\nEsse sistema � composto por todas as letras do alfabeto e todos os n�meros. Os caracteres s�o representados por uma combina��o espec�fica de pontos e tra�os, para formar as palavras, basta realizar a combina��o correta de s�mbolos. As mensagens s�o transmitidas por meio e intervalos de som (apito) ou luz (lanterna), podendo ser captadas por diversos aparelhos, como, por exemplo, o radiotel�grafo e o tel�grafo.\nDurante a Segunda Guerra Mundial, o C�digo Morse foi fundamental no envio de mensagens r�pidas de longa dist�ncia entre navios e avi�es dos ex�rcitos. O c�digo foi usado at� 1999 como linguagem oficial para opera��es mar�timas, quando ent�o foi substitu�do pelo sistema GMDSS de comunica��o. O ex�rcito americano tamb�m treinava soldados em C�digo Morse at� 2015. Ao se popularizar, o c�digo foi adaptado para que cada letra e cada algarismo tivesse sua representa��o. Ao fazer a marca, a agulha fazia um barulho e logo os operadores aprenderam a decifrar o C�digo Morse, nem mesmo precisando ver o resultado das fitas marcadas. S� de ouvir os barulhos (curto, longo ou sil�ncio), eles j� conseguiam dizer a mensagem passada.\nCom a inven��o do telefone, no fim do s�culo XIX, o C�digo Morse caiu em desuso. O desenvolvimento de novas tecnologias de comunica��o mais eficazes desencadeou a substitui��o desse sistema por outros aparelhos. Na Fran�a, por exemplo, o C�digo Morse deixou de ser utilizado pelas grandes navega��es desde 1997.\n");
                system("pause");
                goto op6;
            }

            else if (opc6 == 2){
                system("cls");
                printf("BEM VINDO USU�RIO !\n");
                printf("-------------------\n");
                printf("O c�digo Morse internacional � composto de seis elementos:\n\n");
                printf("* Sinal curto, ponto ou 'dit' (�)\n* Sinal longo, tra�o ou 'dah' (-)\n* Intervalo entre caracteres (entre pontos e tra�os)\n* Intervalo curto (entre letras)\n* Intervalo m�dio (entre palavras)\n* Intervalo longo (entre frases)\n");
                printf("-------------------\n");
				printf("Os dois primeiros elementos s�o usados para representar caracteres.\nA dura��o do dit, predefinida nesse programa, determina o ritmo a qual a mensagem � enviada.\nAqui est� uma ilustra��o de conven��es de ritmo. Sua inten��o � mostrar exatamente o ritmo\nNormalmente seria escrito algo como isso:\n\n");
				printf("-.-. --- -.. .. --. ---  /       -- --- .-. ... .\n");
				printf("C    O   D   I  G   O  (espa�o)   M  O   R   S  E\n");
				printf("-------------------\n");
				printf("Dura��o dos Elementos do Morse\n\n");
				printf("* Um dah � convencionalmente 3 vezes a dura��o do dit\n");
				printf("* Espa�os entre dits e dahs em um caractere t�m a dura��o de um dit.\n");
				printf("* Espa�os entre letras em uma palavra t�m a dura��o de um dah (3 dits).\n");
				printf("* Espa�os entre palavras t�m a dura��o de 7 dits.\n");
                system("pause");
                goto op6;
            }
			else if(opc6 == 3){
				system("cls");
				printf("TABELA DO CODIGO\n");
                printf("----------------\n");
                printf("CHAR\tCODIGO\n----------------\nA\t.-\tN\t-.\n");
				printf("B\t-...\tO\t---\n");
				printf("C\t-.-.\tP\t.--.\n");
				printf("D\t-..\tQ\t--.-\n");
				printf("E\t.\tR\t.-.\n");
				printf("F\t..-.\tS\t...\n");
				printf("G\t--.\tT\t-\n");
				printf("H\t....\tU\t..-\n");
				printf("I\t..\tV\t...-\n");
				printf("J\t.---\tW\t.--\n");
				printf("K\t-.-\tX\t-..-\n");
				printf("L\t.-..\tY\t-.--\n");
				printf("M\t--\tZ\t--..\n\n");
				printf("0\t-----\t&\t.-...\t-\t-....-\n");
				printf("1\t.----\t'\t.----.\t?\t..--..\n");
				printf("2\t..---\t@\t.--.-.\n");
				printf("3\t...--\t)\t-.--.-\n");
				printf("4\t....-\t(\t-.--.\n");
				printf("5\t.....\t:\t---...\n");
				printf("6\t-....\t,\t--..--\n");
				printf("7\t--...\t=\t-...-\n");
				printf("8\t---..\t!\t-.-.--\n");
				printf("9\t----.\t.\t.-.-.-\n");
				system("pause");
				goto op6;
			}
            else {
                goto inicio;
            }
        
    }

	if (opc == 7) {
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
		DESENVOLVER A OP��O 2 - ok ,3 - ok,5 - ok
		APLICAR O DELAY ENTRE CARACTERES E FRASES - OK
		INCLUIR OS CARACTERES DE PONTUA��O NA FUN��O CODIGO - ok
		VER SE � POSSIVEL POR O CODIGO ESCRTIO NA FUN��O CODIGO CASO A OP��O SELECIONADA SEJA 2 OU 4 - ok
	 */

	 /* https://morsecode.scphillips.com/morse2.html */

}
