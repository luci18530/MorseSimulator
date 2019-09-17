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

char* convert(char *mword)
{
	int  count3 = 0;
	char *stringnormal[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M","N", "O", "P", "Q", "R", "S", "T", "U",
					  "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "&", "'", "@",")","(",":",",",
					  "=", "!", "." ,"-", "?", " " };


	char *stringmorse[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---", "-.-",".-..","--","-.","---",".--.","--.-",
						 ".-.","...","-","..-", "...-",".--","-..-","-.--","--..", ".----","..---","...--","....-", ".....", "-....",
							 "--...","---..","----.","-----", ".-...", ".----.", ".--.-.", "-.--.", "---...","--..--", "-...-", "-.-.--", ".-.-.-", "-....-", "..--..", "/" };

	while (TRUE)
	{
		if (strcmp(mword,stringmorse[count3]) != 0)
		{
			count3++;
		}

		if (strcmp(mword, stringmorse[count3]) == 0)
		{
			return stringnormal[count3];
		}
	}
}

void parsemorse(char phrase[])
{
	char words[9964],v = '0', real[9964], ch[2];
	int count1 = 0, count2 = 0, i = 0, count4 = 0;
	while (v != '\0' && v != EOF)
	{
		while (ch[0] != '/' && ch[0] != ' ' && ch[0] != '\0')
		{
			words[i] = phrase[count2];
			ch[0] = phrase[count2];
			count2++;
			i++;
		}
		v = phrase[count2];
		printf("%s", convert(words));
		count1++;
	}
}