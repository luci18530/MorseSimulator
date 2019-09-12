#include <stdio.h>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int FREQ; //FREQUENCIA DO BEEP
#define DUR 75 // DURAÇÃO DO BEEP CURTO (PONTO) EM MILISEGUNDOS
#define TAMFRASE 512 // TAMANHO MAXIMO DA FRASE
int DURSLEEP_INTRACHAR = DUR; // TEMPO DE DELAY ENTRE O BEEP CURTO E BEEP LONGO
int DURSLEEP_ENTRECHAR = 3*DUR; // TEMPO DE DELAY ENTRE CADA CARACTERE
int DURSLEEP_ENTREPALAVRA = 7*DUR; // TEMPO DE DELAY ENTRE CADA PALAVRA
int opc; // SELETOR DE OPÇÃO

// DIT e DAT
void ponto (void){
	if (opc == 1 || opc == 3){
		Beep(FREQ,DUR);}  // BEEP CURTO
  	if (opc == 2 || opc == 4) {
  		printf(".");}
}

void linha (void){
	if (opc == 1 || opc == 3){
  		Beep(FREQ,DUR*3);} // BEEP LONGO
 	if (opc == 2 || opc == 4) {
 		printf("-");}
}

// ESPAÇOS
void INTRACHAR (void){
    Sleep(DURSLEEP_INTRACHAR); // DELAY ENTRE O BEEP CURTO E BEEP LONGO
}

void ENTRECHAR (void){
    Sleep(DURSLEEP_ENTRECHAR); // TEMPO DE DELAY ENTRE CADA CARACTERE
}

void ENTREPALAVRA (void){
    Sleep(DURSLEEP_ENTREPALAVRA); // TEMPO DE DELAY ENTRE CADA PALAVRA
}


// CODIGO PARA CADA CARACTERE
void codigo(caractere){
	
  if (caractere == 'a'|| caractere == 'A') {
       ponto();
       INTRACHAR();
       linha();
    }

  if (caractere == 'b'|| caractere == 'B') {
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
  }

  if (caractere == 'c'|| caractere == 'C') {
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
  }

  if (caractere == 'd'|| caractere == 'D') {
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
  }

  if (caractere == 'e'|| caractere == 'E') {
    ponto();
    
  }

  if (caractere == 'f'|| caractere == 'F') {
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
  }

  if (caractere == 'g'|| caractere == 'G') {
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
  }

  if (caractere == 'h'|| caractere == 'H') {
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
  }

  if (caractere == 'i'|| caractere == 'I') {
    ponto();
    INTRACHAR();
    ponto();
  }

  if (caractere == 'j'|| caractere == 'J') {
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
  }
  
  if (caractere == 'k'|| caractere == 'K') {
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();
  }

  if (caractere == 'l'|| caractere == 'L') {
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
  }

  if (caractere == 'm'|| caractere == 'M') {
    linha();
    INTRACHAR();
    linha();
  }

  if (caractere == 'n'|| caractere == 'N') {
    linha();
    INTRACHAR();
    ponto();
  }

  if (caractere == 'o'|| caractere == 'O') {
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
  }

  if (caractere == 'p'|| caractere == 'P') {
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
  }

  if (caractere == 'q'|| caractere == 'Q') {
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();
  }

  if (caractere == 'r'|| caractere == 'R') {
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();

  }

  if (caractere == 's'|| caractere == 'S') {
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();

  }

  if (caractere == 't'|| caractere == 'T') {
    linha();
  }

  if (caractere == 'u'|| caractere == 'U') {
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();

  }

  if (caractere == 'v'|| caractere == 'V') {
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();

  }

  if (caractere == 'w'|| caractere == 'W') {
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();

  }

  if (caractere == 'x' || caractere == 'X') {
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();

  }

  if (caractere == 'y' || caractere == 'Y') {
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();

  }

  if (caractere == 'z' || caractere == 'Z') {
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
}

if (caractere == '0') {
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
}

if (caractere == '1') {
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
}

if (caractere == '2') {
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
}

if (caractere == '3') {
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
}

if (caractere == '4') {
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();
}

if (caractere == '5') {
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
}

if (caractere == '6') {
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
}

if (caractere == '7') {
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
}

if (caractere == '8') {
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
}

if (caractere == '9') {
	
	
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
    
}

if (caractere == '&') {
	
	
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    INTRACHAR();
    ponto();
    
}

if (caractere == '\'') {
	
	
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
    
}

if (caractere == '@') {
	
	
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
    INTRACHAR();
    linha();
    INTRACHAR();
    ponto();
    
}

/*Punctuation Mark	Morse
& Ampersand	.-...
' Apostrophe	.----.
@ At sign	.--.-.
) Bracket, close (parenthesis)	-.--.-
( Bracket, open (parenthesis)	-.--.
: Colon	---...
, Comma	--..--
= Equals sign	-...-
! Exclamation mark
Not in ITU-R recommendation	-.-.--
. Full-stop (period)	.-.-.-
- Hyphen	-....-
+ Plus sign	.-.-.
" Quotation marks	.-..-.
? Question mark (query)	..--..
/ Slash	-..-.*/
}

// AINDA A SER ADICIONADO OS CARACTERES DE PONTUAÇÃO!!

int main(void) {
  setlocale(LC_ALL, "Portuguese"); // PERMITIR CARACTERES ACENTUADOS
  
  int cont_limite_opc1 = 0; // CONTADOR PARA SAIR DA OPÇÃO 1 
  char caractere; // PARA A OPÇÃO 1
  char frase[TAMFRASE]; // PARA A OPÇÃO 3
  int leitorfrase = 0; // leitor da frase
  printf("SISTEMA TELEGRAFO Versão Alpha 0.6.1\n-----------------------------------------\n");
  printf("Digite o modo de como você quer trabalhar\n(1)- Caractere para codigo sonoro\n(2)- Caractere para codigo escrito\n(3)- String para codigo sonoro\n(4)- String para codigo escrito\n(5)- Codigo para string\n(6)- Sair\n-----------------------------------------\n");
  printf("Digite a opção: "); // SELECIONAR A OPÇÃO
  scanf("%i", &opc);
  printf("-----------------------------------------\n");
  
  if (opc == 1 || opc == 3){
    printf("Determine a frequência da onda do beep em Hertz: "); // SELECIONAR A FREQUENCIA 
    scanf("%i", &FREQ);
    printf("-----------------------------------------\n");
    
    if (opc == 1){
		// OPÇÃO 1 = CARACTERE PARA CODIGO SONORO
    	while(1){
    		printf("Digite a caractere (pressione 0 três vezes para sair): ");
    		scanf(" %c", &caractere);
    		if (caractere  == '0'){cont_limite_opc1++;} // CONTADOR PARA SAIR DA OPÇÃO 1
	  		if (cont_limite_opc1>=3){break;} // FUTURAMENTE USAR GOTO PARA VOLTAR A SELEÇÃO DE OPÇÃO
    		codigo(caractere);
 	}
	}
	
	
		
		
	}
  
  	if (opc == 3) {
  		// OPÇÃO 3 - STRING PARA CODIGO SONORO
  		printf("Digite as frases (pressione 000 para sair): ");	
		while(1){
			fgets(frase, TAMFRASE, stdin);
  			if (frase[0] == '0' && frase[1] == '0' && frase[2] == '0'){break;}
  			else {
			  for (leitorfrase = 0; frase[leitorfrase] != '\0'; leitorfrase++){
  				codigo(frase[leitorfrase]); // A CADA CARACTERE DA STRING SERA USADO A FUNÇÃO QUE GERA OS BEEPS ATÉ ENCONTRAR O '\0'
			  }
  	}
	}
	}
	
	if (opc == 2){
		while(1){
    		printf("\nDigite a caractere (pressione 0 três vezes para sair): ");
    		scanf(" %c", &caractere);
    		if (caractere  == '0'){cont_limite_opc1++;} // CONTADOR PARA SAIR DA OPÇÃO 2
	  		if (cont_limite_opc1>=3){break;} // FUTURAMENTE USAR GOTO PARA VOLTAR A SELEÇÃO DE OPÇÃO
    		codigo(caractere);
 	}
}
	if (opc == 6){
		printf("OBRIGADO POR USAR NOSSO PROGRAMA!\n");
		printf("-----------------------------------------\n");
		printf("Feito por:\n1- Luciano Pereira de Oliveira Filho\n2- Lucas Isaac Pissaia da Silva \n3- Erika Fernanda Andrade Bezerra\n4- Anthony Gabriel Lopes da Silva\n5- Samuel Torres Lourenço\n\nTURINHO - CIENCIA DA COMPUTAÇÃO 2019.1\n");
		printf("-----------------------------------------\n");
		system("pause");
		return 0;
		}
  
  
  return 0;
	/* FALTA:
		USO DO CLEAR SCREEN
		FALAR COM MARITAN
		DESENVOLVER A OPÇÃO 2,3,5
		APLICAR O DELAY ENTRE CARACTERES E FRASES
		INCLUIR OS CARACTERES DE PONTUAÇÃO NA FUNÇÃO CODIGO
		VER SE É POSSIVEL POR O CODIGO ESCRTIO NA FUNÇÃO CODIGO CASO A OPÇÃO SELECIONADA SEJA 2 OU 4
	
	
	 */
	 
	 /* https://morsecode.scphillips.com/morse2.html*/

}
