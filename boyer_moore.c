#include <stdio.h>
#include "utils.h"

void BMOccurrenceHeuristic(TextType text, int n, PatternType pattern, int m)
{
	int i;
	int k;
	int j;
	int move;

	i = m - 1;

	while(i < n)
	{
		k = m - 1;
		j = i;

		while(k >= 0 && text[j] == pattern[k])
		{
			k--;
			j--;
		}

		if(k < 0)
		{
			printf("String matching at %u!\n", (i - m) + 2);
			i++;
		}
		else
		{
			k = k - 1;
			move = 1;

			while(k >= 0 && pattern[k] != text[j])
			{
				k--;
				move++;
			}

			i += move;
		}
	}
}
