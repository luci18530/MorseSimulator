#include <windows.h>
#include <dos.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "codigos.h"
#include "pch.h"

int FREQ; //FREQUENCIA DO BEEP
int DURSLEEP_INTRACHAR = DUR; // TEMPO DE DELAY ENTRE O BEEP CURTO E BEEP LONGO
int DURSLEEP_ENTRECHAR = 2 * DUR; // TEMPO DE DELAY ENTRE CADA CARACTERE
int DURSLEEP_ENTREPALAVRA = 5 * DUR; // TEMPO DE DELAY ENTRE CADA PALAVRA
int opc; // SELETOR DE OPÇÃO

// ESPAÇOS
void INTRACHAR(void) {
	Sleep(DURSLEEP_INTRACHAR); // DELAY ENTRE O BEEP CURTO E BEEP LONGO
}

void ENTRECHAR(void) {
	if (opc == 1 || opc == 3) {
		Sleep(DURSLEEP_ENTRECHAR);
	} // DELAY ENTRE CADA CARACTERE
	if (opc == 2 || opc == 4) {
		printf(" ");
	}
}

void ENTREPALAVRA(void) {
	if (opc == 1 || opc == 3) {
		Sleep(DURSLEEP_ENTREPALAVRA);
	} // DELAY ENTRE CADA PALAVRA
	if (opc == 2 || opc == 4) {
		printf("   ");
	}
}


// DIT e DAT
void ponto(void) {
	if (opc == 1 || opc == 3) {
		Beep(FREQ, DUR);
		INTRACHAR();
	} // BEEP CURTO
	if (opc == 2 || opc == 4) {
		printf(".");
	}
}

void linha(void) {
	if (opc == 1 || opc == 3) {
		Beep(FREQ, DUR * 3);
		INTRACHAR();
	} // BEEP LONGO
	if (opc == 2 || opc == 4) {
		printf("-");
	}
}




// CODIGO PARA CADA CARACTERE
void codigo(caractere) {

	if (caractere == 'a' || caractere == 'A') {
		ponto();
		linha();
		ENTRECHAR();
	}

	if (caractere == 'b' || caractere == 'B') {
		linha();
		ponto();
		ponto();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 'c' || caractere == 'C') {
		linha();
		ponto();
		linha();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 'd' || caractere == 'D') {
		linha();
		ponto();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 'e' || caractere == 'E') {
		ponto();
		ENTRECHAR();

	}

	if (caractere == 'f' || caractere == 'F') {
		ponto();
		ponto();
		linha();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 'g' || caractere == 'G') {
		linha();
		linha();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 'h' || caractere == 'H') {
		ponto();
		ponto();
		ponto();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 'i' || caractere == 'I') {
		ponto();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 'j' || caractere == 'J') {
		ponto();
		linha();
		linha();
		linha();
		ENTRECHAR();
	}

	if (caractere == 'k' || caractere == 'K') {
		linha();
		ponto();
		linha();
		ENTRECHAR();
	}

	if (caractere == 'l' || caractere == 'L') {
		ponto();
		linha();
		ponto();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 'm' || caractere == 'M') {
		linha();
		linha();
		ENTRECHAR();
	}

	if (caractere == 'n' || caractere == 'N') {
		linha();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 'o' || caractere == 'O') {
		linha();
		linha();
		linha();
		ENTRECHAR();
	}

	if (caractere == 'p' || caractere == 'P') {
		ponto();
		linha();
		linha();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 'q' || caractere == 'Q') {
		linha();
		linha();
		ponto();
		linha();
		ENTRECHAR();
	}

	if (caractere == 'r' || caractere == 'R') {
		ponto();
		linha();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 's' || caractere == 'S') {
		ponto();
		ponto();
		ponto();
		ENTRECHAR();
	}

	if (caractere == 't' || caractere == 'T') {
		linha();
		ENTRECHAR();
	}

	if (caractere == 'u' || caractere == 'U') {
		ponto();
		ponto();
		linha();
		ENTRECHAR();
	}

	if (caractere == 'v' || caractere == 'V') {
		ponto();
		ponto();
		ponto();
		linha();
		ENTRECHAR();
	}

	if (caractere == 'w' || caractere == 'W') {
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