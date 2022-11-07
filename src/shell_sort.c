// 将要比较的元素分为几个区域进行插入排序 来提升性能
// 所有元素按步长进行分组
// 元素可以向前移动较大的步长
// 步长随迭代依次减小
// 最后一次步长为1,就是最普通的插入排序，不过此时表中元素已经基本有序了

void insertionSort(int *arr, int length, int step)
{
    // for(int i=)
}

void shell_sort(int *arr, int length)
{
    // 步长初始为数组长度的一般，逐次减半 其实就是很普通的步长序列 n/(2**i)
    for (int step_size = length >> 1; step_size != 0; step_size >>= 1)
    {
        // 组数是步长数-1 //比如说13个元素，现在步长是6 就从0到5
        for (int i = 0; i < step_size; ++i) {//这一层循环没必要写，多余的
            // printf("i=%d ",i);
            // start insertion sort
            for (int j = step_size + i; j < length; j += step_size){
                // printf(",j=%d ",j);
                int temp = arr[j];
                int k;
                for (k = j - step_size; k >= i; k -= step_size) {
                    // printf(",k=%d \n ",k);

                    if (arr[k] > temp){
                        arr[k + step_size] = arr[k];
                    }
                    else
                        break;
                }
                arr[k + step_size] = temp;
            }
        }
    }
}

void ShellSort(int *arr, int length)
{
    for(int gap = length>>1; gap != 0; gap >>= 1){
        //start insertion sort
        for(int i = gap; i < length; ++i) {//我上面那个实现的思路是一组一组的元素比较，这个实现是不同组的元素交替着比较，但是无所谓，反正按照步长最后是等价的，确实就是按照组进行了插入排序，只不过没按照人类脑子的顺序思维
            int temp = arr[i];
            int j;
            for(j = i-gap;j >=0; j-=gap){
                if(temp < arr[j]) {
                    arr[j+gap] = arr[j];//因为这个是j是代表的左边的那个元素所以判断条件大于等于0 ,j如果代表的是后一个元素那就是>=gap,不然排不对了(甚至可能越界--可能越界是推断不知道对不对
                }else
                    break;
            }
            arr[j+gap] = temp;
        }
    }
}

void ShellSort2(int *arr, int length)
{
    for(int gap = length>>1; gap != 0; gap >>= 1){
        //start insertion sort
        for(int i = gap; i < length; ++i) {//我上面那个实现的思路是一组一组的元素比较，这个实现是不同组的元素交替着比较，但是无所谓，反正按照步长最后是等价的，确实就是按照组进行了插入排序，只不过没按照人类脑子的顺序思维
            int temp = arr[i];
            int j;
            for(j = i;j >=gap; j-=gap){ //这样写的花这必须大于等于gap，不然就不对，神奇
                if(temp < arr[j-gap]) {
                    arr[j] = arr[j-gap];
                }else
                    break;
            }
            arr[j] = temp;
        }
    }
}

// void ShellSort(int *arr, int length)
// {
//     for(int gap = length>>1; gap != 0; gap >>= 1){
//         //start insertion sort
//         for(int i = gap; i < length; ++i) {//我上面那个实现的思路是一组一组的元素比较，这个实现是不同组的元素交替着比较，但是无所谓，反正按照步长最后是等价的，确实就是按照组进行了插入排序，只不过没按照人类脑子的顺序思维
//             int temp = arr[i];
//             int j;
//             // for(j = i-gap;j >=0; j-=gap){
//             //     if(temp < arr[j]) {
//             //         arr[j+gap] = arr[j];
//             //     }else
//             //         break;
//             // }
//             // arr[j+gap] = temp;

//              for(j = i;j >=0; j-=gap){
//                 if(temp < arr[j-gap]) {
//                     arr[j] = arr[j-gap];
//                 }else
//                     break;
//             }
//             arr[j] = temp;
//         }
//     }
// }