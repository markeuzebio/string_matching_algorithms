#include <string.h>
#include "utils.h"
#include "brute_force.h"
#include "boyer_moore.h"
#include "boyer_moore_horspool.h"
#include "boyer_moore_horspool_sunday.h"
#include "shift_and_exact.h"
#include "shift_and_approximate.h"

int main()
{
	TextType text = "o teste testam os testes";
	PatternType pattern = "teste";

	//bruteForce(text, strlen(text), pattern, strlen(pattern));

	//BMOccurrenceHeuristic(text, strlen(text), pattern, strlen(pattern));

	//boyerMooreHorspool(text, strlen(text), pattern, strlen(pattern));

    //boyerMooreHorspoolSunday(text, strlen(text), pattern, strlen(pattern));

	//shiftAndExact(text, strlen(text), pattern, strlen(pattern));
	
	//shiftAndApproximate(text, strlen(text), pattern, strlen(pattern), 1);

	return 0;
}
