// 快速排序  也是使用 分治法的排序算法
// partition-exchange sort 分区交换排序
//快速排序的最坏运行情况是 O(n²)，比如说顺序数列的快排。但它的平摊期望时间是 O(nlogn)，且 O(nlogn) 记号中隐含的常数因子很小，比复杂度稳定等于 O(nlogn) 的归并排序要小很多。所以，对绝大多数顺序性较弱的随机数列而言，快速排序总是优于归并排序。

// 随机快排:随机一个数作为基准数pivot，将它和最左边的数交换，依次遍历比较
// 遍历完之后，把它和比基准数小的下标最大的数交换位置,这样 左边的数都比这个数小
// 右边的数都比这个数大，继续递归
//  从右边开始，然后和比它小的下标最小的数交换也行
#include <time.h>
#include <stdlib.h>

void _swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *arr, int l, int r)
{
	int piv_idx = l + rand() % (r-l+1);
	int pivot = arr[piv_idx];
	_swap(&arr[l],&arr[piv_idx]);
	int j = l+1;
	for(int i = j ; i <= r; ++i) {
		if(arr[i] < pivot) {//第一次如果判定不成功，它后面也会被挤到后面对于那些大于基准值的元素
			_swap(&arr[i],&arr[j]);	
			j++;
		}
	}
	_swap(&arr[l],&arr[--j]);//要把基准值元素换到这里，至于原来的元素，被挤到最左边了，最左边还是左边，是比基准值小的

	return j;
}

// 一种最普通最简单的随机快速排序实现
void _quick_sort(int *arr, int l, int r)
{
	if(l >= r) //如果子序列的长度为0或1,则数列已经有序
		return;
	int mid = partition(arr,l,r);
	_quick_sort(arr,l,mid-1);//以前的pivot就不动了
	_quick_sort(arr,mid+1,r);
}

void quick_sort(int *arr, int length)
{
	srand((unsigned)time(NULL));
	_quick_sort(arr,0,length-1);
}



