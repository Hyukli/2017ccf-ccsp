#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "solve.h"

// your code
// you can add variables and functions as you need

void my_init(int argc, char** argv)
{
	// your code
	// you should delete next 2 lines
	MAIN_output(1,1,1);
	printf("This is my_init()\n");
}

void my_solve(int argc, char** argv, int begin_vertex)
{
	// your code
	// please use MAIN_output() to output your result	
	// you should delete next 2 lines
	MAIN_output(2,2,2);
	printf("This is my_solve( %d )\n", begin_vertex);
}
