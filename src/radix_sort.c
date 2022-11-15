//Radix sort基数排序  -- Bucket sort桶排序  -- distribution sort分配式排序  稳定
//O(k·n) k数字位数，进行k轮处理 n排序元素个数，每轮处理n个
//整数也可以表达字符串(名字或者日期)和特定格式的浮点数(这个就不知道了),所以基数排序不仅仅可以用来 进行整数排序
#include <string.h>
#include <stdbool.h>

#define BASE 10

void radix_sort(int *arr, int length)
{
	bool flag = true;
	int bit_power = 1; // 位权 个、十、百、千 等
	int bucket[BASE][length];
	int cnt[BASE];
	size_t size = sizeof(cnt);
	int radix = 0;
	do {
		memset(cnt,0,size);
		for(int i=0; i<length; ++i) {
			radix = arr[i] / bit_power % BASE;
			bucket[radix][cnt[radix]++] = arr[i];
		}
		int arr_idx = 0;
		for(int i=0; i<BASE; ++i) {
			for(int j=0; j < cnt[i]; ++j) {
				arr[arr_idx++] = bucket[i][j];	
			}
		}
		arr_idx = 0;
		
		bit_power *= 10;
		if(cnt[0] == length)
			flag = false;
	} while(flag);
}

void radix_sort_16(int *arr, int length)
{
	// & 0x0000000f
}
