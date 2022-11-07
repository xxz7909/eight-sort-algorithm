#include <stdbool.h>
#define swap(a,b) a^=b^=a^=b

void bubble_sort(int* arr,int length)
{
	// 第i轮比较，最大的那个元素会浮到倒数第i个
	// 每一轮都是相邻元素依次两两比较，直到比无可比
	// 第一个for length-1: 剩下最后一个元素自然是最小的
	for(int iterator = 0;iterator < length-1; ++iterator){
		for(int j=0;j < length-iterator-1; ++j){//下面有j+1
			if(arr[j] > arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

void BubbleSort(int *arr,int length){
	// 用一个开关变量来控制，如果比完一轮发现不用交换任何元素，那自然就结束了
	bool swapped;
	int last=length;
	// 而冒泡排序的时间复杂度最好是O(n),do...while循环恰好和这个很契合
	do {
		swapped = false;
		for(int i=0; i<last-1; ++i){
			if(arr[i] > arr[i+1]){
				swap(arr[i],arr[i+1]);
				swapped = true;
			}
		}
		--last;		
	}while(swapped);


}
