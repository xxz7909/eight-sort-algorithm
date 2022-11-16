#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubble_sort.c"
#include "selection_sort.c"
#include "test_sort.c"
#include "insertion_sort.c"
#include "shell_sort.c"
#include "mergeSort_recursion.c"
#include "MergeSort.c"
#include "quick_sort.c"
#include "counting_sort.c"
#include "radix_sort.c"
#include "merge_sort_iteration.c"

int main(int argc,const char *argv[])
{
//	test_sort(&bubble_sort);	
//	test_sort(&BubbleSort);
//	test_sort(&selection_sort);
	// test_sort(&insertion_sort);	
	// test_sort(&shell_sort);
	// test_sort(&ShellSort);
	//test_sort(&ShellSort2);
//	test_sort(&merge_sort);
//	test_sort(&MergeSort);
//	test_sort(&quick_sort);
//	test_sort(&counting_sort);

//	test_sort(&radix_sort);

	test_sort(&merge_sort);
	
	return 0;
}
