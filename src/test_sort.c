#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define arr_length(arr) sizeof(arr) / sizeof(arr[0])

void (*p_sort_func)(int* ,int) = NULL;
void test_sort(void (*p_sort_func)(int*,int));

int compare(const void* p1,const void* p2){
	return (*(int*)p1 - *(int*)p2);
}

void test_sort(void (*p_sort_func)(int*,int)){
	srand((unsigned)time(NULL));
	int arr[13];
	int arr_2[13];
	for(int i=0; i < arr_length(arr); ++i){
		arr[i] = rand()%100;	
		arr_2[i] = arr[i];
	}
	printf("Before sort:");
	for(int i=0;i < arr_length(arr); ++i){
		printf("%d ",arr[i]);
	}
	putchar('\n');

	(*p_sort_func)(arr,arr_length(arr));

	printf("After sort:");
	for(int i=0;i < arr_length(arr); ++i){
		printf("%d ",arr[i]);
	}	
	putchar('\n');

	qsort(arr_2,arr_length(arr_2),sizeof(arr[0]),compare);
	printf("After qsort:");
	for(int i=0;i < arr_length(arr_2); ++i){
		printf("%d ",arr_2[i]);
	}
	
	putchar('\n');
	putchar('\n');
}


