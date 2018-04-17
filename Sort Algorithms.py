# -*- coding:utf-8 -*-

def bubbleSort(input_list):
	'''
	函数说明:冒泡排序（升序）
	Website:
		http://cuijiahua.com
	Parameters:
		input_list - 待排序列表
	Returns:
		sorted_list - 升序排序好的列表
	'''
	if len(input_list) == 0:
		return []
	sorted_list = input_list
	for i in range(len(sorted_list) - 1):
		bChanged = False
		print('第%d趟排序:' % (i + 1))
		for j in range(len(sorted_list) - 1):
			if sorted_list[j + 1] < sorted_list[j]:
				sorted_list[j], sorted_list[j + 1] = sorted_list[j + 1], sorted_list[j]
				bChanged = True
			print(sorted_list)
		if not bChanged:
			break
	return sorted_list

def insertSort(input_list):
	'''
	函数说明:直接插入排序（升序）
	Website:
		http://cuijiahua.com
	Parameters:
		input_list - 待排序列表
	Returns:
		sorted_list - 升序排序好的列表
	'''
	if len(input_list) == 0:
		return []
	sorted_list = input_list

	for i in range(1, len(sorted_list)):
		temp = sorted_list[i]
		j = i - 1
		while j >=0 and temp < sorted_list[j]:
			sorted_list[j + 1] = sorted_list[j]
			j -= 1
		sorted_list[j + 1] = temp
	return sorted_list



def BinaryInsertSort(input_list):
	'''
	函数说明:二分查找插入排序（升序）
	Website:
		http://cuijiahua.com
	Parameters:
		input_list - 待排序列表
	Returns:
		sorted_list - 升序排序好的列表
	'''
	if len(input_list) == 0:
		return []

	def BinarySearch(input_list, end, value):
		'''
		函数说明:二分查找，查找第一个大于等于value的列表索引值，不存在返回-1
		Website:
			http://cuijiahua.com
		Parameters:
			input_list - 待查找列表
			end - 查找位置的尾部
			value - 
		Returns:
			left - 找到的列表索引值
		'''
		left = 0
		right = end - 1
		while left <= right:
			middle = left + (right - left) // 2
			if input_list[middle] >= value:
				right = middle - 1
			else:
				left = middle + 1

		return left if left < end else -1

	sorted_list = input_list
	for i in range(1, len(input_list)):
		j = i - 1
		temp = sorted_list[i]
		insert_index = BinarySearch(sorted_list, i, sorted_list[i])
		if insert_index != -1:
			while j >= insert_index:
				sorted_list[j + 1] = sorted_list[j]
				j -= 1
			sorted_list[j + 1] = temp
	return sorted_list

def ShellSort(input_list):
	'''
	函数说明:希尔排序（升序）
	Website:
		http://cuijiahua.com
	Parameters:
		input_list - 待排序列表
	Returns:
		sorted_list - 升序排序好的列表
	'''	
	if len(input_list) == 0:
		return []
	sorted_list = input_list
	n = len(sorted_list)
	gap = n // 2
	while gap > 0:
		for i in range(gap, len(sorted_list)):
			temp = sorted_list[i]
			j = i - gap
			while j >= 0 and temp < sorted_list[j]:
				sorted_list[j + gap] = sorted_list[j]
				j -= gap
			sorted_list[j + gap] = temp
		gap //= 2
	return sorted_list

def QuickSort(input_list, left, right):
	'''
	函数说明:快速排序（升序）
	Website:
		http://cuijiahua.com
	Parameters:
		input_list - 待排序列表
	Returns:
		无
	'''	
	def division(input_list, left, right):
		'''
		函数说明:根据left和right进行一次扫描，重新找到基准数
		Website:
			http://cuijiahua.com	
		Parameters:
			input_list - 待排序列表
			left - 左指针位置
			right - 右指针位置
		Returns:
			left - 新的基准数位置
		'''	
		base = input_list[left]
		while left < right:
			while left < right and input_list[right] >= base:
				right -= 1
			input_list[left] = input_list[right]
			while left < right and input_list[left] <= base:
				left += 1
			input_list[right] = input_list[left]
		input_list[left] = base
		return left

	if left < right:
		base_index = division(input_list, left, right)
		QuickSort(input_list, left, base_index - 1)
		QuickSort(input_list, base_index + 1, right)

def SelectSort(input_list):
	'''
	函数说明:简单选择排序（升序）
	Website:
		http://cuijiahua.com
	Parameters:
		input_list - 待排序列表
	Returns:
		sorted_list - 升序排序好的列表
	'''	
	if len(input_list) == 0:
		return []
	sorted_list = input_list
	length = len(sorted_list)
	for i in range(length):
		min_index = i
		for j in range(i + 1, length):
			if sorted_list[min_index] > sorted_list[j]:
				min_index = j
		temp = sorted_list[i]
		sorted_list[i] = sorted_list[min_index]
		sorted_list[min_index] = temp
	return sorted_list

def HeadSort(input_list):
	'''
	函数说明:堆排序（升序）
	Website:
		http://cuijiahua.com
	Parameters:
		input_list - 待排序列表
	Returns:
		sorted_list - 升序排序好的列表
	'''
	def HeadAdjust(input_list, parent, length):
		'''
		函数说明:堆调整，调整为最大堆
		Website:
			http://cuijiahua.com
		Parameters:
			input_list - 待排序列表
			parent - 堆的父结点
			length - 数组长度
		Returns:
			无
		'''	
		temp = input_list[parent]
		child = 2 * parent + 1

		while child < length:
			if child + 1 < length and input_list[child] < input_list[child+1]:
				child += 1
			if temp >= input_list[child]:
				break

			input_list[parent] = input_list[child]

			parent = child
			child = 2 * parent + 1
		input_list[parent] = temp

	if len(input_list) == 0:
		return []
	sorted_list = input_list
	length = len(sorted_list)

	for i in range(0, length // 2 + 1)[::-1]:
		HeadAdjust(sorted_list, i, length)

	for j in range(1, length)[::-1]:
		temp = sorted_list[j]
		sorted_list[j] = sorted_list[0]
		sorted_list[0] = temp

		HeadAdjust(sorted_list, 0, j)
		print('第%d趟排序:' % (length - j), end = '')
		print(sorted_list)

	return sorted_list

def MergeSort(input_list):
	'''
	函数说明:归并排序（升序）
	Website:
		http://cuijiahua.com
	Parameters:
		input_list - 待排序列表
	Returns:
		sorted_list - 升序排序好的列表
	'''
	def merge(input_list, left, mid, right, temp):
		'''
		函数说明:合并函数
		Website:
			http://cuijiahua.com
		Parameters:
			input_list - 待合并列表
			left - 左指针
			right - 右指针
			temp - 临时列表
		Returns:
			无
		'''	
		i = left
		j = mid + 1
		k = 0

		while i <= mid and j <= right:
			if input_list[i] <= input_list[j]:
				temp[k] = input_list[i]
				i += 1
			else:
				temp[k] = input_list[j]
				j += 1
			k += 1

		while i <= mid:
			temp[k] = input_list[i]
			i += 1
			k += 1
		while j <= right:
			temp[k] = input_list[j]
			j += 1
			k += 1

		k = 0
		while left <= right:
			input_list[left] = temp[k]
			left += 1
			k += 1

	def merge_sort(input_list, left, right, temp):
		if left >= right:
			return;
		mid = (right + left) // 2
		merge_sort(input_list, left, mid, temp)
		merge_sort(input_list, mid + 1, right, temp)

		merge(input_list, left, mid, right, temp)

	if len(input_list) == 0:
		return []
	sorted_list = input_list
	temp = [0] * len(sorted_list)
	merge_sort(sorted_list, 0, len(sorted_list) - 1, temp)
	return sorted_list

def RadixSort(input_list):
	'''
	函数说明:基数排序（升序）
	Website:
		http://cuijiahua.com
	Parameters:
		input_list - 待排序列表
	Returns:
		sorted_list - 升序排序好的列表
	'''
	def MaxBit(input_list):
		'''
		函数说明:求出数组中最大数的位数的函数
		Author:
			www.cuijiahua.com
		Parameters:
			input_list - 待排序列表
		Returns:
			bits-num - 位数
		'''
		max_data = max(input_list)
		bits_num = 0
		while max_data:
			bits_num += 1
			max_data //= 10
		return bits_num

	def digit(num, d):
		'''
		函数说明:取数xxx上的第d位数字
		Website:
			http://cuijiahua.com
		Parameters:
			num - 待操作的数
			d - 第d位的数
		Returns:
			取数结果
		'''	
		p = 1
		while d > 1:
			d -= 1
			p *= 10
		return num // p % 10


	if len(input_list) == 0:
		return []
	sorted_list = input_list
	length = len(sorted_list)
	bucket = [0] * length
	
	for d in range(1, MaxBit(sorted_list) + 1):
		count = [0] * 10

		for i in range(0, length):
			count[digit(sorted_list[i], d)] += 1

		for i in range(1, 10):
			count[i] += count[i - 1]

		for i in range(0, length)[::-1]:
			k = digit(sorted_list[i], d)
			bucket[count[k] - 1] = sorted_list[i]
			count[k] -= 1
		for i in range(0, length):
			sorted_list[i] = bucket[i]

	return sorted_list

if __name__ == '__main__':
	input_list = [50, 123, 543, 187, 49, 30, 0, 2, 11, 100]
	print('排序前:', input_list)
	sorted_list = RadixSort(input_list)
	print('排序后:', sorted_list)
