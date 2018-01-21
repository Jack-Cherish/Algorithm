#include <iostream>
#include <vector>
 
using namespace std;
 
// 基础冒泡排序
vector<int> bubbleSort_1(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}

	result = list;
	int temp;
	// 要遍历的次数
	for (int i = 0; i < result.size() - 1; ++i){
		cout << "第" << i + 1 << "趟排序:" << endl;;
		// 从后向前依次的比较相邻两个数的大小
		for (int j = 0; j < result.size() - 1; j++){
			// 如果后面的元素小，则交换它们的位置
			if (result[j + 1] < result[j]){
				temp = result[j + 1];
				result[j + 1] = result[j];
				result[j] = temp;
			}
			cout << "排序中:";
			for (int s = 0; s < result.size(); s++){
				cout << result[s] << " ";
			}
			cout << endl;
		}
		cout << "排序结果:";
		for (int s = 0; s < result.size(); s++){
			cout << result[s] << " ";
		}
		cout << endl;
	}

	return result;
}

// 优化冒泡排序
vector<int> bubbleSort_2(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}

	result = list;
	int temp;
	// 要遍历的次数
	for (int i = 0; i < result.size() - 1; ++i){
		cout << "第" << i + 1 << "趟排序:" << endl;;
		//交换标志位
		bool bChanged = false;
		// 从后向前依次的比较相邻两个数的大小
		for (int j = 0; j < result.size() - 1; j++){
			// 如果后面的元素小，则交换它们的位置
			if (result[j + 1] < result[j]){
				temp = result[j + 1];
				result[j + 1] = result[j];
				result[j] = temp;
				bChanged = true;
			}
			cout << "排序中:";
			for (int s = 0; s < result.size(); s++){
				cout << result[s] << " ";
			}
			cout << endl;
		}
		// 如果标志为false，说明本轮遍历没有交换，已经是有序数列，可以结束排序
		if (false == bChanged){
			break;
		}
		cout << "排序结果:";
		for (int s = 0; s < result.size(); s++){
			cout << result[s] << " ";
		}
		cout << endl;
	}

	return result;
}
 
// 直接插入排序
vector<int> insertSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}
	result = list;
	// 第1个数肯定是有序的，从第2个数开始遍历，依次插入有序序列
	for (int i = 1; i < result.size(); i++){
		// 取出第i个数，和前i-1个数比较后，插入合适位置
		int temp = result[i];
		// 因为前i-1个数都是从小到大的有序序列，所以只要当前比较的数(list[j])比temp大，就把这个数后移一位
		int j = i - 1;
		for (j; j >= 0 && result[j] > temp; j--){
			result[j + 1] = result[j];
		}
		result[j + 1] = temp;
	}
	return result;
}

// 希尔排序
vector<int> ShellSort(vector<int> list){
	vector<int> result = list;
	int n = result.size();
	for (int gap = n >> 1; gap > 0; gap >>= 1){
		for (int i = gap; i < n; i++){
			int temp = result[i];
			int j = i - gap;
			while (j >= 0 && result[j] > temp){
				result[j + gap] = result[j];
				j -= gap;
			}
			result[j + gap] = temp;
		}
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}

// 快速排序的division函数
int division(vector<int> &list, int left, int right){
	// 以最左边的数(left)为基准
	int base = list[left];
	while (left < right) {
		// 从序列右端开始，向左遍历，直到找到小于base的数
		while (left < right && list[right] >= base)
			right--;
		// 找到了比base小的元素，将这个元素放到最左边的位置
		list[left] = list[right];
 
		// 从序列左端开始，向右遍历，直到找到大于base的数
		while (left < right && list[left] <= base)
			left++;
		// 找到了比base大的元素，将这个元素放到最右边的位置
		list[right] = list[left];
	}
 
	// 最后将base放到left位置。此时，left位置的左侧数值应该都比left小；
	// 而left位置的右侧数值应该都比left大。
	list[left] = base;
	return left;
}
 
// 快速排序
void QuickSort(vector<int> &list, int left, int right){
	// 左下标一定小于右下标，否则就越界了
	if (left < right) {
		// 对数组进行分割，取出下次分割的基准标号
		int base = division(list, left, right);
 
		// 对“基准标号“左侧的一组数值进行递归的切割，以至于将这些数值完整的排序
		QuickSort(list, left, base - 1);
 
		// 对“基准标号“右侧的一组数值进行递归的切割，以至于将这些数值完整的排序
		QuickSort(list, base + 1, right);
	}
}

// 简单选择排序
vector<int> SelectSort(vector<int> list){
	// 需要遍历获得最小值的次数
	// 要注意一点，当要排序 N 个数，已经经过 N-1 次遍历后，已经是有序数列
	vector<int> result = list;
	for (int i = 0; i < result.size(); i++){
		// 用来保存最小值得索引
		int index = i;
		// 用来保存最小值得索引
		for (int j = i + 1; j < result.size(); j++){
			if (result[index] > result[j]){
				index = j;
			}
		}
		// 将找到的第i个小的数值放在第i个位置上
		swap(result[i], result[index]);
		cout << "第" << i + 1<< "趟:\t";
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}

// 堆排序的初始化函数
void HeapAdjust(vector<int> &list, int parent, int length){
	int temp = list[parent];					// temp保存当前父节点
	int child = 2 * parent + 1;					// 先获得左孩子
 
	while (child < length){
		// 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
		if (child + 1 < length && list[child] < list[child + 1]){
			child++;
		}
 
		// 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
		if (temp >= list[child]){
			break;
		}
 
		// 把孩子结点的值赋给父结点
		list[parent] = list[child];
 
		// 选取孩子结点的左孩子结点,继续向下筛选
		parent = child;
		child = 2 * parent + 1;
	}
	list[parent] = temp;
}
 
// 堆排序
vector<int> HeadSort(vector<int> list){
	int length = list.size();
	// 循环建立初始堆
	for (int i = length / 2; i >= 0; i--){
		HeapAdjust(list, i, length);
	}
 
	// 进行n-1次循环，完成排序
	for (int i = length - 1; i > 0; i--){
		// 最后一个元素和第一元素进行交换
		int temp = list[i];
		list[i] = list[0];
		list[0] = temp;
 
		// 筛选 R[0] 结点，得到i-1个结点的堆
		HeapAdjust(list, 0, i);
		cout << "第" << length - i << "趟排序:";
		for (int i = 0; i < list.size(); i++){
			cout << list[i] << " ";
		}
		cout << endl;
	}
	return list;
}

// 归并排序的合并函数
void Merge(vector<int> &input, int left, int mid, int right, vector<int> temp){
	int i = left;				// i是第一段序列的下标
	int j = mid + 1;			// j是第二段序列的下标
	int k = 0;					// k是临时存放合并序列的下标
	
	// 扫描第一段和第二段序列，直到有一个扫描结束
	while (i <= mid && j <= right){
		// 判断第一段和第二段取出的数哪个更小，将其存入合并序列，并继续向下扫描
		if (input[i] <= input[j]){
			temp[k++] = input[i++];
		}
		else{
			temp[k++] = input[j++];
		}
	}
	// 若第一段序列还没扫描完，将其全部复制到合并序列
	while (i <= mid){
		temp[k++] = input[i++];
	}
 
	// 若第二段序列还没扫描完，将其全部复制到合并序列
	while (j <= right){
		temp[k++] = input[j++];
	}
 
	k = 0;
	// 将合并序列复制到原始序列中
	while (left <= right){
		input[left++] = temp[k++];
	}
}

// 归并排序
void MergeSort(vector<int> &input, int left, int right, vector<int> temp){
	if (left < right){
		int mid = (right + left) >> 1;
		MergeSort(input, left, mid, temp);
		MergeSort(input, mid + 1, right, temp);
		Merge(input, left, mid, right, temp);
	}
}
 
// 归并排序
void mergesort(vector<int> &input){
	// 在排序前，先建好一个长度等于原数组长度的临时数组，避免递归中频繁开辟空间
	vector<int> temp(input.size());				
	MergeSort(input, 0, input.size() - 1, temp);
}

// 基数排序的求出数组中最大数的位数的函数
int MaxBit(vector<int> input){
	// 数组最大值
	int max_data = input[0];
	for (int i = 1; i < input.size(); i++){
		if (input[i] > max_data){
			max_data = input[i];
		}
	}
 
	// 数组最大值的位数
	int bits_num = 0;
	while (max_data){
		bits_num++;
		max_data /= 10;
	}
 
	return bits_num;
}
 
// 基数排序的取数xxx上的第d位数字
int digit(int num, int d){
	int pow = 1;
	while (--d > 0){
		pow *= 10;
	}
	return num / pow % 10;
}
 
// 基数排序
vector<int> RadixSort(vector<int> input, int n){
	// 临时数组，用来存放排序过程中的数据
	vector<int> bucket(n);					
	// 位记数器，从第0个元素到第9个元素依次用来记录当前比较位是0的有多少个...是9的有多少个数
	vector<int> count(10);				
	// 从低位往高位循环
	for (int d = 1; d <= MaxBit(input); d++){
		// 计数器清0
		for (int i = 0; i < 10; i++){
			count[i] = 0;
		}
 
		// 统计各个桶中的个数
		for (int i = 0; i < n; i++){
			count[digit(input[i],d)]++;
		}
 
		/*
		* 比如某次经过上面统计后结果为：[0, 2, 3, 3, 0, 0, 0, 0, 0, 0]则经过下面计算后 结果为： [0, 2,
		* 5, 8, 8, 8, 8, 8, 8, 8]但实质上只有如下[0, 2, 5, 8, 0, 0, 0, 0, 0, 0]中
		* 非零数才用到，因为其他位不存在，它们分别表示如下：2表示比较位为1的元素可以存放在索引为1、0的
		* 位置，5表示比较位为2的元素可以存放在4、3、2三个(5-2=3)位置，8表示比较位为3的元素可以存放在
		* 7、6、5三个(8-5=3)位置
		*/
		for (int i = 1; i < 10; i++){
			count[i] += count[i - 1];
		}
 
		/*
		* 注，这里只能从数组后往前循环，因为排序时还需保持以前的已排序好的顺序，不应该打
		* 乱原来已排好的序，如果从前往后处理，则会把原来在前面会摆到后面去，因为在处理某个
		* 元素的位置时，位记数器是从大到到小（count[digit(arr[i], d)]--）的方式来处
		* 理的，即先存放索引大的元素，再存放索引小的元素，所以需从最后一个元素开始处理。
		* 如有这样的一个序列[212,213,312]，如果按照从第一个元素开始循环的话，经过第一轮
		* 后（个位）排序后，得到这样一个序列[312,212,213]，第一次好像没什么问题，但问题会
		* 从第二轮开始出现，第二轮排序后，会得到[213,212,312]，这样个位为3的元素本应该
		* 放在最后，但经过第二轮后却排在了前面了，所以出现了问题
		*/
		for (int i = n - 1; i >= 0; i--){
			int k = digit(input[i], d);
			bucket[count[k] - 1] = input[i];
			count[k]--;
		}
 
		// 临时数组复制到 input 中
		for (int i = 0; i < n; i++){
			input[i] = bucket[i];
		}
	}
 
	return input;
}
