#include <stdio.h>
#include "utils.h"

/*
	n: text length
	m: pattern length
*/
void bruteForce(TextType text, int n, PatternType pattern, int m)
{
	int i;
	int k;
	int j;

	i = 0;

	while(i <= n - m)
	{
		k = 0;
		j = i;

		while(k < m && pattern[k] == text[j]) {
			k++;
			j++;
		}

		if(k == m)
			printf("String matching at %u!\n", i + 1);

		i++;
	}
}
