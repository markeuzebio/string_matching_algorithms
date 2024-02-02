#include <stdio.h>
#include "utils.h"

#define CHARS_AMOUNT 128

typedef unsigned int BitsMask[CHARS_AMOUNT];

void shiftAndExact(TextType text, int n, PatternType pattern, int m)
{
	BitsMask table;
	unsigned int main_mask;
	unsigned int base_mask;

	// -------------------- PREPROCESSING -------------------- //
	for(int i = 0 ; i < CHARS_AMOUNT ; i++)
		table[i] = 0;

	for(int j = 1 ; j <= m ; j++)
		table[pattern[j - 1]] = table[pattern[j - 1]] | (1 << (m - j));
	// ------------------------------------------------------- //

	main_mask = 0;
	base_mask = ((unsigned int) 1 << (m - 1));

	for(int i = 0 ; i < n ; i++)
	{
		main_mask = ((main_mask >> 1) | base_mask) & table[text[i]];

		if(main_mask & 1 == 1)
			printf("String match at %d!\n", (i - m) + 2);
	}
}
