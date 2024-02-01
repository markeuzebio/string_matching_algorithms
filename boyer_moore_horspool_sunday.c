#include <stdio.h>
#include "utils.h"

#define CHARS_AMOUNT 128

typedef int DisplacementTable[CHARS_AMOUNT];

void boyerMooreHorspoolSunday(TextType text, int n, PatternType pattern, int m)
{
	int i;
	int j;
	int k;
	int aligned_texts_char;

	DisplacementTable table;

	// ------------ PREPROCESSING -------------- //
	for(int i = 0 ; i < CHARS_AMOUNT ; i++)
		table[i] = m + 1;

	for(int j = 1 ; j <= m ; j++)
		table[pattern[j - 1]] = (m - j) + 1;
    // ----------------------------------------- //

	i = m - 1;

	while(i < n)
	{
		k = m - 1;
		j = i;
		aligned_texts_char = j + 1;

		while(k >= 0 && text[j] == pattern[k])
		{
			k--;
			j--;
		}

		if(k < 0)
            printf("String matching at %u!\n", (i - m) + 2);

		i += table[text[aligned_texts_char]];
	}
}
