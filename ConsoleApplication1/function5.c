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
	int b = 0, count3 = 0;
	char *stringnormal[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M","N", "O", "P", "Q", "R", "S", "T", "U",
					  "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "&", "'", "@",")","(",":",",",
					  "=", "!", "." ,"-", "?", " " };


	char *stringmorse[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---", "-.-",".-..","--","-.","---",".--.","--.-",
						 ".-.","...","-","..-", "...-",".--","-..-","-.--","--..", ".----","..---","...--","....-", ".....", "-....",
							 "--...","---..","----.","-----", ".-...", ".----.", ".--.-.", "-.--.", "---...","--..--", "-...-", "-.-.--", ".-.-.-", "-....-", "..--..", "/" };

	while (b == 0)
	{
		if (strcmp(mword, stringmorse[count3]) != 0)
		{
			count3++;
		}

		if (strcmp(mword, stringmorse[count3]) == 0)
		{
			return stringnormal[count3];
		}
	}
}

char* parsemorse(char *phrase)
{
	char words[9999964], ch, v = '0', real[9999964];
	int count1 = 0, count2 = 0, i = 0, count4 = 0;
	while (v != '\0' && v != EOF)
	{
		while (ch != ' ' && ch != '/' && ch != '|')
		{
			words[i] = phrase[count2];
			count2++;
			i++;
			ch = words[i];
		}
		words[i] = '\0';
		real[count1] = convert(words);
		v = phrase[count2];
		printf(real[count1]);
		count1++;
	}
}