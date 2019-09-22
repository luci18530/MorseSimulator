#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define DUR 75 // DURAÇÃO DO BEEP CURTO (PONTO) EM MILISEGUNDOS
#define TAMFRASE 4096 // TAMANHO MAXIMO DA FRASE

char* convert(char* mword);
void parsemorse(char phrase[]);

#endif
