#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "codigo.h"
#include "function5.h"

char* convert(char* mword)
{
	int  count3 = 0;
	char* stringnormal[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M","N", "O", "P", "Q", "R", "S", "T", "U",
					  "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "&", "'", "@",")","(",":",",",
					  "=", "!", "." ,"-", "?", " " };


	static char* stringmorse[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---", "-.-",".-..","--","-.","---",".--.","--.-",
						 ".-.","...","-","..-", "...-",".--","-..-","-.--","--..", ".----","..---","...--","....-", ".....", "-....",
							 "--...","---..","----.","-----", ".-...", ".----.", ".--.-.", "-.--.", "---...","--..--", "-...-", "-.-.--", ".-.-.-", "-....-", "..--..", "//" };

	while (TRUE)
	{
		if (strcmp(mword, stringmorse[count3]) != 0)
		{
			count3++;
		}

		if (strcmp(mword, stringmorse[count3]) == 0)
		{
			return stringnormal[count3];
		}
		if (count3 >= 47)
		{
			printf("%s: Caractere não Cadastrado\n", stringnormal[count3]);
			return "FATAL ERROR";
		}
	}
}

void parsemorse(char phrase[])
{
	char words[TAMFRASE], v = '0', real[TAMFRASE];
	int count1 = 0, count2 = 0, i = 0, count4 = 0;
	while (phrase[count2] != '\0' && phrase[count2] != EOF)
	{
		while (count4 < TAMFRASE)
		{
			words[count4] = '\0';
			count4++;
		}
		count4 = 0;
		while (phrase[count2] != '/' && phrase[count2] != ' ' && phrase[count2] != '\0')
		{
			words[i] = phrase[count2];
			count2++;
			i++;
		}
		words[i] = '\0';
		if (words[i] == '\0')
		{
			count2++;
			i = 0;
		}
		printf("%s", convert(words));
		count1++;
	}
	printf("\n");
}