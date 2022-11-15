#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *arr, int l, int r)
{
	int piv_idx = l + rand() % (r-l+1);
	int pivot = arr[piv_idx];
	swap(&arr[l],&arr[piv_idx]);
	int j = l+1;
	for(int i=j; i <= r; ++i) {
		if(arr[i] < pivot) {
			swap(&arr[i],&arr[j]);
			j++;
		}
	}
	swap(&arr[l],&arr[--j]);

	return j;
}

void quick_sort(int* arr, int l, int r)
{
	if(l >= r)
		return ;

	int mid = partition(arr,l,r);
	quick_sort(arr,l,mid-1);
	quick_sort(arr,mid+1,r);
}

int main(void)
{
	srand((unsigned)time(NULL));
	int arr[13];
	int length = sizeof(arr) / sizeof(arr[0]);
	for(int i=0; i<length; ++i){
		arr[i] = rand() % 20;
		printf("%d ",arr[i]);
	}
	putchar('\n');
	quick_sort(arr,0,length-1);
	for(int i=0; i<length; ++i){
		printf("%d ",arr[i]);
	}
	putchar('\n');

	return 0;
}
