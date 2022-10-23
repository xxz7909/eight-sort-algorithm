#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubble_sort.c"
#include "test_sort.c"

int main(int argc,const char *argv[])
{
	test_sort(&bubble_sort);	
	test_sort(&BubbleSort);

	return 0;
}
