#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define CHARS_AMOUNT 128

typedef unsigned int BitsMask[CHARS_AMOUNT];

void shiftAndApproximate(TextType text, int n, PatternType pattern, int m, int max_errors)
{
	BitsMask table;
	unsigned int *masks;
	unsigned int base_mask;
    unsigned int changed_mask_before;
	unsigned int unchanged_mask_before;

	// ----------------- PREPROCESSING ----------------- //	
	for(int i = 0 ; i < CHARS_AMOUNT ; i++)
		table[i] = 0;

	for(int j = 1 ; j <= m ; j++)
		table[pattern[j - 1]] = table[pattern[j - 1]] | (1 << (m - j));

	masks = (unsigned int*) malloc((max_errors + 1) * sizeof(unsigned int));
	// ------------------------------------------------- //

	masks[0] = 0;
	base_mask = ((unsigned long) 1 << (m - 1));

	for(int i = 1 ; i <= max_errors ; i++)
		masks[i] = masks[i - 1] | (1 << (m - i));

	for(int i = 0 ; i < n ; i++)
	{
		unchanged_mask_before = masks[0];
		masks[0] = ((masks[0] >> 1) | base_mask) & table[text[i]];
		changed_mask_before = masks[0];

		for(int j = 1 ; j <= max_errors ; j++)
		{
			changed_mask_before = (((unsigned int) masks[j] >> 1) & table[text[i]]) | unchanged_mask_before | (unchanged_mask_before >> 1) | (changed_mask_before >> 1) | base_mask;
			unchanged_mask_before = masks[j];
			masks[j] = changed_mask_before;
		}

		if((changed_mask_before & 1) != 0)
			printf("String match at %d!\n", (i - m) + 2);
	}

	free(masks);
}
