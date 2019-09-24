#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "codigo.h"
#include "function5.h"

char* convert(char* mword) //converte diretamente codigo morse para um caractere UTF-8
{
	int  count3 = 0; //inicialoização do contador 3
	char* stringnormal[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M","N", "O", "P", "Q", "R", "S", "T", "U",
					  "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "&", "'", "@",")","(",":",",",
					  "=", "!", "." ,"-", "?", " " , "\47"}; //string contendo os caracteres UTF-8


	static char* stringmorse[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---", "-.-",".-..","--","-.","---",".--.","--.-",
						 ".-.","...","-","..-", "...-",".--","-..-","-.--","--..", ".----","..---","...--","....-", ".....", "-....",
							 "--...","---..","----.","-----", ".-...", ".----.", ".--.-.", "-.--.", "---...","--..--", "-...-", "-.-.--", ".-.-.-", "-....-", "..--..", "\47"," " };
	//array contendo a letras e símbolos em morse

	while (TRUE) //procura por uma sequência de pontos e traços que correspondam a uma letra
	{
		if (strcmp(mword, stringmorse[count3]) != 0) //isso faz o contador 3 aumentar, para verificar igualdade ná próxima string do array
		{
			count3++;
		}

		if (strcmp(mword, stringmorse[count3]) == 0) //caso encontrado correspondência, retorna a respectivo caractere UTF-8
		{
			return stringnormal[count3];
		}
		if (count3 >= 48) //caso não encontrado correspondência, o programa retorna um erro
		{
			printf("%s: Caractere não Cadastrado\n", stringnormal[count3]);
			return "FATAL ERROR\n";
		}
	}
}

void parsemorse(char phrase[])  //parser, separa as letras da frase inteira para traduzir
{
	char words[TAMFRASE], v = '0'; //string que vai segurar uma letra pra jogar pra função convert e o verificador v
	int count1 = 0, count2 = 0, i = 0, count4 = 0; //inicialização dos contadores
	while (phrase[count2] != '\0' && phrase[count2] != EOF) //o parser funciona até encontrar um '\0' ou final de arquivo
	{
		while (count4 < TAMFRASE) //isso atribui a cada caractere da string que vai a letra, '\0'
		{
			words[count4] = '\0'; 
			count4++;
		}
		count4 = 0; //reseta o contador 4
		while (phrase[count2] != '/' && phrase[count2] != ' ' && phrase[count2] != '\0') //parser de letras, ao encontar espaço ou barra, ele para de capturar código
		{
			words[i] = phrase[count2];  //atribui o carcatere da frase de recebimento (pela chamada da função)
			count2++;
			i++;
		}
		words[i] = '\0'; //adiciona '\0' no final da string a ser passada pra convert
		if (words[i] == '\0')  
		{
			count2++; //aumenta o contador 2 para pegar a próxima letra da frase de recebimento
			i = 0; //reseta i, para sempre colocar a letra em morse nos primeiros caracteres da string
		}
		printf("%s", convert(words)); // cahamada da função convert, que vai retornar um caractere, que vai ser imprimido na tela
		if (phrase[count2 - 1] == ' ' && (phrase[count2] == '/' || phrase[count2] == '|') && phrase[count2 + 1] == ' ') 
		{
			printf(" ");
			count2 += 2; //faz que phrase[count2] esteja em código morse valido (não num espaço ou barra)
		}
		if (phrase[count2] == '/' || phrase[count2] == '|') //faz que phrase[count2] esteja em código morse valido (não num espaço ou barra)
		{
			printf(" ");
			if (phrase[count2 + 1] == ' ') //faz que phrase[count2] esteja em código morse valido (não num espaço ou barra)
			{
				count2++;
			}
		}
		count1++; //resto de código anterior, provavelmente
	}
	printf("\n"); //imprime a quebra de linha
}