#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubble_sort.c"
#include "selection_sort.c"
#include "test_sort.c"
#include "insertion_sort.c"

int main(int argc,const char *argv[])
{
//	test_sort(&bubble_sort);	
//	test_sort(&BubbleSort);
//	test_sort(&selection_sort);
	test_sort(&insertion_sort);	
	return 0;
}
