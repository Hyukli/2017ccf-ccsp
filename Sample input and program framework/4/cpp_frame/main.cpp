#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

#define TEST_NUM 5

static int MAIN_i;

void MAIN_output(int id, int dist, int undiscoverd)
{
	printf("%d %d %d\n", id, dist, undiscoverd);
}

int main(int argc, char** argv)
{
	// my init
	my_init(argc, argv);

	// my solve
	for(MAIN_i=0; MAIN_i<TEST_NUM; MAIN_i++)
	{		
		// use a certain vertex whose id is MAIN_i to do the exploration	
		my_solve(argc, argv, MAIN_i);
	}

	printf("finished\n");
	

	return 0;
}
