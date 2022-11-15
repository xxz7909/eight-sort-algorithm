#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int arr[2] = {222,333};
	int a =444;
	int idx=0;
	swap(&a,&arr[idx++]);
	printf("%d %d\n",arr[0],arr[idx]);

	return 0;
}
