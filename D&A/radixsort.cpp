#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
//获取最大位数
int get_max_digit(int array[], int n)
{
	int digit, max;
	digit = 0;
	max = array[0];
	for (int i = 1; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	while (max)
	{
		digit++;
		max /= 10;
	}
	return digit;
}
//基数排序
void RadixSort(int array[], int n)
{
	//创建临时数组
	int *temp = new int[n];
	//位数：决定了排序趟数
	int digit = get_max_digit(array, n);
	//计数数组
	int count[10];
	//排序
	int r, i, d;
	for (r = 1; r <= digit; r++)
	{
		//重置计数数组
		memset(count, 0, 10 * sizeof(int));
		//把数据存储到临时数组
		memcpy(temp, array, n*sizeof(int));
		d = i = 1;
		while (i < r)
		{
			i++;
			d *= 10;
		}
		for (i = 0; i < n; i++)
			count[(array[i] / d) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		//数据回放
		for (i = n - 1; i >= 0; i--)
			array[--count[(temp[i] / d) % 10]] = temp[i];
	}
}
void print(int array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(6) << array[i];
	cout << endl;
}
int main()
{
	cout << "******基数排序***by David***" << endl;
	int array[] = { 123, 234, 45, 111, 6, 128 };
	int n = sizeof(array) / sizeof(int);
	cout << "原序列" << endl;
	print(array, n);
	cout << "基数排序" << endl;
	RadixSort(array, n);
	print(array, n);
	
	return 0;
}
