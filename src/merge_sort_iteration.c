//迭代 iteration MergeSort  感觉递归 是  深度优先    迭代 是 广度优先
//Bottom-up  
//直接进行归并 ，从2个一组开始排序，然后4个一组8个一组这样子 
//图解的话过程其实是一层一层从左往右遍历，这一层排好了，进下一层所以是广度优先
//迭代实现的循环条件就是数组长度，不过要注意，mid 和 high不能超过数组长度，所以在计算时要和length比较取最小值，
#include <malloc.h>

int min(int x, int y)
{
	return x < y ? x : y;
}

void merge_sort_iteration(int *arr, int length)
{
	int *temp_arr = (int*)malloc(sizeof(arr[0]) * length);
	int *temp_ptr = NULL; // 辅助进行数组交换的指针
	int low,mid,high;
	for(int seg = 1; seg < length; seg <<= 1) { //子序列逐步归并
		for(int start=0; start < length; start += seg*2) {
			low = start;
			mid = min(start+seg, length);//数组下标最多取到len-1
			high= min(start + 2*seg, length);//所以后面条件不用加等号
			// 然后又因为没加后面没加等号，mid那里的条件也不用加等号
			int i = low, j=mid;
			int idx = 0;
			while(i < mid && j < high) {
				if(arr[i] < arr[j]) {
					temp_arr[idx++] = arr[i++];	
				} else {
					temp_arr[idx++] = arr[j++];
				}
			}
			while(i < mid) {
				temp_arr[idx++] = arr[i++];
			}
			while(j < high) {
				temp_arr[idx++] = arr[j++];
			}
			idx = 0;
		}
		temp_ptr = arr;
		arr = temp_arr;	
		temp_arr = arr;

	}
	
	free(temp_arr);
}


