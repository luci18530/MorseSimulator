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
int opc; // SELETOR DE OPÇÃO
int opc6;

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
	printf("SISTEMA TELEGRAFO Versão Beta 0.9.9\n-----------------------------------------\n");
	printf("Digite o modo de como você quer trabalhar\n(1) - Caractere para codigo sonoro\n(2) - Caractere para codigo escrito\n(3) - String para codigo sonoro\n(4) - String para codigo escrito\n(5) - Codigo para string\n(6) - Sobre\n(7) - Sair\n-----------------------------------------\n");
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
			printf("Digite os textos (digite 000 para sair): ");
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
		getchar();
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
		// OPÇÃO 5 - CODIGO ESCRITO PARA STRING
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
        printf("(1) - História do Codigo Morse\n");
        printf("(2) - Funcionamento do Codigo Morse\n");
        printf("(3) - Tabela do código\n");
        printf("-----------------------------------\n");
        printf("Digite outro numero para voltar\n");
        printf("-----------------------------------\n");
        printf("Digite a opção: ");
        scanf("%i", &opc6);
            if (opc6 == 1){
                system("cls");
                printf("Desenvolvido em 1835, pelo pintor e inventor Samuel Finley Breese Morse, o Código Morse é um sistema binário de representação à distância de números, letras e sinais gráficos, utilizando-se de sons curtos e longos, além de pontos e traços para transmitir mensagens.\nEsse sistema é composto por todas as letras do alfabeto e todos os números. Os caracteres são representados por uma combinação específica de pontos e traços, para formar as palavras, basta realizar a combinação correta de símbolos. As mensagens são transmitidas por meio e intervalos de som (apito) ou luz (lanterna), podendo ser captadas por diversos aparelhos, como, por exemplo, o radiotelégrafo e o telégrafo.\nDurante a Segunda Guerra Mundial, o Código Morse foi fundamental no envio de mensagens rápidas de longa distância entre navios e aviões dos exércitos. O código foi usado até 1999 como linguagem oficial para operações marítimas, quando então foi substituído pelo sistema GMDSS de comunicação. O exército americano também treinava soldados em Código Morse até 2015. Ao se popularizar, o código foi adaptado para que cada letra e cada algarismo tivesse sua representação. Ao fazer a marca, a agulha fazia um barulho e logo os operadores aprenderam a decifrar o Código Morse, nem mesmo precisando ver o resultado das fitas marcadas. Só de ouvir os barulhos (curto, longo ou silêncio), eles já conseguiam dizer a mensagem passada.\nCom a invenção do telefone, no fim do século XIX, o Código Morse caiu em desuso. O desenvolvimento de novas tecnologias de comunicação mais eficazes desencadeou a substituição desse sistema por outros aparelhos. Na França, por exemplo, o Código Morse deixou de ser utilizado pelas grandes navegações desde 1997.\n");
                system("pause");
                goto op6;
            }

            else if (opc6 == 2){
                system("cls");
                printf("BEM VINDO USUÁRIO !\n");
                printf("-------------------\n");
                printf("O código Morse internacional é composto de seis elementos:\n\n");
                printf("* Sinal curto, ponto ou 'dit' (·)\n* Sinal longo, traço ou 'dah' (-)\n* Intervalo entre caracteres (entre pontos e traços)\n* Intervalo curto (entre letras)\n* Intervalo médio (entre palavras)\n* Intervalo longo (entre frases)\n");
                printf("-------------------\n");
				printf("Os dois primeiros elementos são usados para representar caracteres.\nA duração do dit, predefinida nesse programa, determina o ritmo a qual a mensagem é enviada.\nAqui está uma ilustração de convenções de ritmo. Sua intenção é mostrar exatamente o ritmo\nNormalmente seria escrito algo como isso:\n\n");
				printf("-.-. --- -.. .. --. ---  /       -- --- .-. ... .\n");
				printf("C    O   D   I  G   O  (espaço)   M  O   R   S  E\n");
				printf("-------------------\n");
				printf("Duração dos Elementos do Morse\n\n");
				printf("* Um dah é convencionalmente 3 vezes a duração do dit\n");
				printf("* Espaços entre dits e dahs em um caractere têm a duração de um dit.\n");
				printf("* Espaços entre letras em uma palavra têm a duração de um dah (3 dits).\n");
				printf("* Espaços entre palavras têm a duração de 7 dits.\n");
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
		printf("Feito por:\n1- Luciano Pereira de Oliveira Filho\n2- Lucas Isaac Pissaia da Silva \n3- Erika Fernanda Andrade Bezerra\n4- Anthony Gabriel Lopes da Silva\n5- Samuel Torres Lourenço\n\nTURINHO - CIENCIA DA COMPUTAÇÃO 2019.1\n");
		printf("-----------------------------------------\n");
		system("pause");
		return 0;
	}


	return 0;
	/* FALTA:
		USO DO CLEAR SCREEN - ok
		FALAR COM MARITAN
		DESENVOLVER A OPÇÃO 2 - ok ,3 - ok,5 - ok
		APLICAR O DELAY ENTRE CARACTERES E FRASES - OK
		INCLUIR OS CARACTERES DE PONTUAÇÃO NA FUNÇÃO CODIGO - ok
		VER SE É POSSIVEL POR O CODIGO ESCRTIO NA FUNÇÃO CODIGO CASO A OPÇÃO SELECIONADA SEJA 2 OU 4 - ok
	 */

	 /* https://morsecode.scphillips.com/morse2.html */

}
