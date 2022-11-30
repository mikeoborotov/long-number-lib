#include "../include/LongNumberLib.h"
#include "../include/LongNumberLibTest.h"
#include <ctime>

	LNL::pow(3, 5);
	time_t start, end;
	time(&start);
	LNL::pow(3, 5);
	time(&end);
	double seconds = difftime(end, start);
	printf("The time: %f seconds\n", seconds)
    return 0;
}
