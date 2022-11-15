#include <stdio.h>

int main(void)
{
	int *p = NULL;
	{
		int a = 12345;
		p = &a;
	}
	printf("%d",*p);
	return 0;
}
