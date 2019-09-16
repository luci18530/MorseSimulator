#include <stdio.h>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int FREQ; //FREQUENCIA DO BEEP
#define DUR 70 // DURA��O DO BEEP CURTO (PONTO) EM MILISEGUNDOS
#define TAMFRASE 1024 // TAMANHO MAXIMO DA FRASE
int DURSLEEP_INTRACHAR = DUR; // TEMPO DE DELAY ENTRE O BEEP CURTO E BEEP LONGO
int DURSLEEP_ENTRECHAR = 2*DUR; // TEMPO DE DELAY ENTRE CADA CARACTERE
int DURSLEEP_ENTREPALAVRA = 5*DUR; // TEMPO DE DELAY ENTRE CADA PALAVRA
int opc; // SELETOR DE OP��O

// ESPA�OS
void INTRACHAR (void){
    Sleep(DURSLEEP_INTRACHAR); // DELAY ENTRE O BEEP CURTO E BEEP LONGO
}

void ENTRECHAR (void){
	if (opc == 1 || opc == 3){
       Sleep(DURSLEEP_ENTRECHAR);} // DELAY ENTRE CADA CARACTERE
    if (opc == 2 || opc == 4) {
	   printf(" "); 
}
}

void ENTREPALAVRA (void){
	if (opc == 1 || opc == 3){
	    Sleep(DURSLEEP_ENTREPALAVRA);} // DELAY ENTRE CADA PALAVRA
	if (opc == 2 || opc == 4) {
  		printf("   "); 
}}


// DIT e DAT
void ponto (void){
	if (opc == 1 || opc == 3){
		Beep(FREQ,DUR);
		INTRACHAR();
		} // BEEP CURTO
  	if (opc == 2 || opc == 4) {
  		printf(".");}
}

void linha (void){
	if (opc == 1 || opc == 3){
  		Beep(FREQ,DUR*3);
		INTRACHAR();
		} // BEEP LONGO
 	if (opc == 2 || opc == 4) {
 		printf("-");}
}




// CODIGO PARA CADA CARACTERE
void codigo(caractere){
	
  if (caractere == 'a'|| caractere == 'A') {
  	ponto();
    linha();
    ENTRECHAR();
    }

  if (caractere == 'b'|| caractere == 'B') {
    linha();
    ponto();
    ponto();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 'c'|| caractere == 'C') {
    linha();
    ponto();
    linha();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 'd'|| caractere == 'D') {
    linha();
    ponto();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 'e'|| caractere == 'E') {
    ponto();
    ENTRECHAR();
    
  }

  if (caractere == 'f'|| caractere == 'F') {
    ponto();
    ponto();
    linha();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 'g'|| caractere == 'G') {
    linha();
    linha();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 'h'|| caractere == 'H') {
    ponto();
    ponto();
    ponto();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 'i'|| caractere == 'I') {
    ponto();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 'j'|| caractere == 'J') {
    ponto();
    linha();
    linha();
    linha();
    ENTRECHAR();
  }
  
  if (caractere == 'k'|| caractere == 'K') {
    linha();
    ponto();
    linha();
    ENTRECHAR();
  }

  if (caractere == 'l'|| caractere == 'L') {
    ponto();
    linha();
    ponto();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 'm'|| caractere == 'M') {
    linha();
    linha();
    ENTRECHAR();
  }

  if (caractere == 'n'|| caractere == 'N') {
    linha();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 'o'|| caractere == 'O') {
    linha();
    linha();
    linha();
    ENTRECHAR();
  }

  if (caractere == 'p'|| caractere == 'P') {
    ponto();
    linha();
    linha();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 'q'|| caractere == 'Q') {
    linha();
    linha();
    ponto();
    linha();
    ENTRECHAR();
  }

  if (caractere == 'r'|| caractere == 'R') {
    ponto();
    linha();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 's'|| caractere == 'S') {
    ponto();
    ponto();
    ponto();
    ENTRECHAR();
  }

  if (caractere == 't'|| caractere == 'T') {
    linha();
    ENTRECHAR();
  }

  if (caractere == 'u'|| caractere == 'U') {
    ponto();
    ponto();
    linha();
    ENTRECHAR();
  }

  if (caractere == 'v'|| caractere == 'V') {
    ponto();
    ponto();
    ponto();
    linha();
    ENTRECHAR();
  }

  if (caractere == 'w'|| caractere == 'W') {
    ponto();
    linha();
    linha();
    ENTRECHAR();
  }

  if (caractere == 'x' || caractere == 'X') {
    linha();
    ponto();
    ponto();
    linha();
    ENTRECHAR();
  }

  if (caractere == 'y' || caractere == 'Y') {
    linha();
    ponto();
    linha();
    linha();
    ENTRECHAR();
  }

  if (caractere == 'z' || caractere == 'Z') {
    linha();
    linha();
    ponto();
    ponto();
    ENTRECHAR();
  }

if (caractere == '0') {
    linha();
    linha();
    linha();
    linha();
    linha();
    ENTRECHAR();
}

if (caractere == '1') {
    ponto();
    linha();
    linha();
    linha();
    linha();
    ENTRECHAR();
}

if (caractere == '2') {
    ponto();
    ponto();
    linha();
    linha();
    linha();
    ENTRECHAR();
}

if (caractere == '3') {
    ponto();
    ponto();
    ponto();
    linha();
    linha();
    ENTRECHAR();
}

if (caractere == '4') {
    ponto();
    ponto();
    ponto();
    ponto();
    linha();
    ENTRECHAR();
}

if (caractere == '5') {
    ponto();
    ponto();
    ponto();
    ponto();
    ponto();
    ENTRECHAR();
}

if (caractere == '6') {
    linha();
    ponto();
    ponto();
    ponto();
    ponto();
    ENTRECHAR();
}

if (caractere == '7') {
    linha();
    linha();
    ponto();
    ponto();
    ponto();
    ENTRECHAR();
}

if (caractere == '8') {
    linha();
    linha();
    linha();
    ponto();
    ponto();
    ENTRECHAR();
}

if (caractere == '9') {
	linha();
    linha();
    linha();
    linha();
    ponto();
    ENTRECHAR();
}

if (caractere == '&') {
	ponto();
    linha();
    ponto();
    ponto();
    ponto();
    ENTRECHAR();
}

if (caractere == '\'') {
	ponto();
    linha();
    linha();
    linha();
    linha();
    ponto();
    ENTRECHAR();
}

if (caractere == '@') {
	ponto();
    linha();
    linha();
    ponto();
    linha();
    ponto();
    ENTRECHAR();
}

if (caractere == ')') {
	linha();
    ponto();
    linha();
    linha();
    ponto();
    linha();
    ENTRECHAR();
}

if (caractere == '(') {
	linha();
    ponto();
    linha();
    linha();
    ponto();
    ENTRECHAR(); 
}

if (caractere == ':') {
	linha();
    linha();
    linha();
    ponto();
    ponto();
    ponto();
    ENTRECHAR();
}

if (caractere == ',') {
	linha();
    linha();
    ponto();
    ponto();
    linha();
    linha();
    ENTRECHAR();
}

if (caractere == '=') {
	linha();
    ponto();
    ponto();
    ponto();
    linha();
    ENTRECHAR();
}

if (caractere == '!') {
	linha();
    ponto();
    linha();
    ponto();
    linha();
    linha();
    ENTRECHAR();
}

if (caractere == '.') {
	ponto();
    linha();
    ponto();
    linha();
    ponto();
    linha();
    ENTRECHAR();
}

if (caractere == '-') {
	linha();
    ponto();
    ponto();
    ponto();
    ponto();
    linha();
    ENTRECHAR();
}

if (caractere == '?') {
	ponto();
    ponto();
    linha();
    linha();
    ponto();
    ponto();
    ENTRECHAR();
}

if (caractere == ' ') {
	ENTREPALAVRA();
}
}



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
  
  if (opc == 1 || opc == 3){
    printf("Determine a frequ�ncia da onda do beep em Hertz: "); // SELECIONAR A FREQUENCIA 
    scanf("%i", &FREQ);
    printf("-----------------------------------------\n");
}
    if (opc == 1){
		// OP��O 1 - CARACTERE PARA CODIGO SONORO
    	while(1){
    		system("cls");
    		printf("Digite a caractere (pressione 0 tr�s vezes para sair): ");
    		scanf(" %c", &caractere);
    		if (caractere  == '0'){cont_limite_opc1++;} // CONTADOR PARA SAIR DA OP��O 1
    		printf("\nDEBUG: %i \n", cont_limite_opc1);
	  		if (cont_limite_opc1>=3){
	  		  cont_limite_opc1 = 0;	
			  goto inicio;
			  } 
    		codigo(caractere);
 	}
	}
	
  
  	if (opc == 3) {
  		// OP��O 3 - STRING PARA CODIGO SONORO
  			
		while(1){
			system("cls");
			printf("Digite os textos (pressione 000 para sair): ");
			fgets(frase, TAMFRASE, stdin);
  			if (frase[0] == '0' && frase[1] == '0' && frase[2] == '0'){goto inicio;}
  			else {
			  for (leitor = 0; frase[leitor] != '\0'; leitor++){
  				codigo(frase[leitor]); // A CADA CARACTERE DA STRING SERA USADO A FUN��O QUE GERA OS BEEPS AT� ENCONTRAR O '\0'
			  }
  	}
	}
	}

	
	if (opc == 2){
		// OP��O 2 - CARACTERE PARA CODIGO ESCRITO
		while(1){
			system("cls");
    		printf("Digite o caractere (pressione 0 tr�s vezes para sair): ");
    		scanf(" %c", &caractere);
    		if (caractere  == '0'){cont_limite_opc2++;} // CONTADOR PARA SAIR DA OP��O 2
	  		if (cont_limite_opc2>=3){
	  		  cont_limite_opc2 = 0;	
			  goto inicio;
			  
			  } 
    		codigo(caractere);
    		printf("\n");
    		system("pause");
 	}
}

if (opc == 4){
	    // OP��O 4 - STRING PARA CODIGO ESCRITO
		while(1){
			system("cls");
    		printf("Digite o texto (pressione 000 para sair): ");
    		fgets(frase, TAMFRASE, stdin);
    		if (frase[0] == '0' && frase[1] == '0' && frase[2] == '0'){goto inicio;}
    		
    		else {
			  for (leitor = 0; frase[leitor] != '\0'; leitor++){
  				codigo(frase[leitor]); // A CADA CARACTERE DA STRING SERA USADO A FUN��O QUE GERA OS PONTOS E TRA�OS AT� ENCONTRAR O '\0'
			  }
    		printf("\n");
    		system("pause");
 	}
}
}

 	if (opc == 5){
	// OP��O 5 - CODIGO ESCRITO PARA STRING - N�O SEI COMO FA�O ISSO!!!!!!!!!!!
	while (1){
		marcador:
		system("cls");
		printf("Digite o codigo (para voltar escreva SAIR): ");
		fgets(codigoescrito, TAMFRASE, stdin);
		if (codigoescrito[0] == 'S' && codigoescrito[1] == 'A' && codigoescrito[2] == 'I' && codigoescrito[3] == 'R'){break;}
		else{
		 for (leitor = 0; codigoescrito[leitor] != '\0'; leitor++){
		 	//if (codigoescrito[leitor] != '.' && codigoescrito[leitor] != '-' && codigoescrito[leitor] != ' ' && codigoescrito[leitor] != '\0' ) {
		 	//	printf("Isso n�o � codigo morse, escreva novamente\n");
		 	//	system("pause");
		 	//	goto marcador;
			// }
			 
		 	
			 	if (codigoescrito[leitor] == '.' && (codigoescrito[leitor+1] == ' ' || codigoescrito[leitor+1] == '\0' )){
			 		printf("e\n");
				 }
			
			 
		 	
		 }
		 system("pause");
	}
	}
}

	if (opc == 6){
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
