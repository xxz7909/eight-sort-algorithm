#define swap(a,b) a^=b^=a^=b
// 在都是升序排列的情况下
// 冒泡排序是第i个元素和第i+1个元素以此比较
// 每n轮比较把当前第n大的元素放在倒数第n个位置上(放在最后)

// 选择排序是每i轮遍历选出一个最小的元素和第i个元素交换
// 不是依次比较，而是先选出来一个最小的然后放到前面，再选一个次小的放到第二个，依此类推

void selection_sort(int *arr,int length)
{
	int temp=0x7fffffff;
	// 只需比较length-1轮,最后一个元素一定是最大的
	for(int iterator=0; iterator < length-1; ++iterator){
		int index = 0;
		// 每一轮要比较到最后，选出最小的
		for(int j = iterator; j < length; ++j){
			if(arr[j] < temp){
				temp = arr[j];
				index = j;
			}
		}
		temp = 0x7fffffff;//要重置temp的值，第一个找出来的是最小的，不重置后面不可能比它小
		if(arr[iterator]!=arr[index])
			swap(arr[iterator],arr[index]);//用异或XOR 的性质实现的swap，如果两个变量值相同就会运算出0
		// 666 竟然是这一点
	}

}
