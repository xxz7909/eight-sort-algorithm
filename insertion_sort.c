
void insertion_sort(int *arr, int length)
{
	// 第一次比较，第二个和第一个元素
	// 第二次比较，将第三个元素和前两个元素依次比较
	// 如果左边的元素大于右边的，则将后面那个小的元素向插到前面，大的那个元素向后移动
	for (int i = 1; i < length; ++i)
	{
		int temp = arr[i];
		int j;
		for (j = i - 1; j >= 0; --j)
		{
			if(arr[j] > temp){
				arr[j+1] = arr[j];	
			}else
				break;//因为一旦左边的不比待插入的元素大，拿就没必要再去往前找了
		}
		arr[j+1] = temp;	
	}
}
