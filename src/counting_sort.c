// counting sort   O(n)
#include <string.h>

void counting_sort(int *arr, int length)
{
	int cnt[100];
	memset(cnt,0,sizeof(cnt));

	for(int i = 0; i < length; ++i) {
		cnt[arr[i]]++;	
	}
	int idx = 0;
	for(int i = 0; i < sizeof(cnt)/sizeof(cnt[0]); ++i) {
		while(cnt[i]--) {
			arr[idx++] = i;
		}
	}
}
