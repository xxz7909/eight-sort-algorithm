#include <malloc.h>

void _merge_sort(int *arr, int left, int right, int *temp)
{
	if(left >= right)
		return;

	// divede
	int mid = (left + right) >> 1;
	_merge_sort(arr,left,mid,temp);
	_merge_sort(arr,mid+1,right,temp);

	// conquer
	int idx = 0;
	int lp = left, rp = mid + 1;
	while(lp <= mid || rp <= right) {
		if(lp > mid)
			temp[idx++] = arr[rp++];
		else if (rp > right)
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
}

void MergeSort(int *arr, int length)
{
	int *temp = malloc(length * sizeof(arr[0]));
	_merge_sort(arr,0,length-1,temp);
	free(temp);
}
