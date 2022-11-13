// 归并排序   基于比较的   O(nlogN) 1945年冯诺依曼提出的
// 采用分治法Divide and Conquer 
// 各层分治递归可以同时进行--这个不太懂哎


// 分的时候是递推的过程,逐个对半分
// 治的时候是回溯的过程,两个合成4个，4个合成八个
// Top-down
#include <malloc.h>

void _mergeSort(int *arr, int left, int right)
{
	if(left >= right)
		return;

	int *temp = malloc( (right-left+1) * sizeof(arr[0]));
	// divide
	int mid = (left + right) >> 1;
	_mergeSort(arr,left,mid);
	_mergeSort(arr,mid+1,right);
	
	// conquer
	int idx = 0;
	int lp = left, rp = mid + 1;
	while(lp <= mid || rp <= right){
		if(lp > mid)
			temp[idx++] = arr[rp++];
		else if(rp > right)
			temp[idx++] = arr[lp++];
		else {
			if(arr[lp] < arr[rp])
				temp[idx++] = arr[lp++];
			else
				temp[idx++] = arr[rp++];
		}
	}

	for(int i=0; i< right-left+1; ++i)
		arr[left+i] = temp[i];
	free(temp);
}

void merge_sort(int *arr,int length)
{
	int left = 0, right = length-1;
	_mergeSort(arr,left,right);
}
