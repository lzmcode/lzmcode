#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
//��ȡ���λ��
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
//��������
void RadixSort(int array[], int n)
{
	//������ʱ����
	int *temp = new int[n];
	//λ������������������
	int digit = get_max_digit(array, n);
	//��������
	int count[10];
	//����
	int r, i, d;
	for (r = 1; r <= digit; r++)
	{
		//���ü�������
		memset(count, 0, 10 * sizeof(int));
		//�����ݴ洢����ʱ����
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
		//���ݻط�
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
	cout << "******��������***by David***" << endl;
	int array[] = { 123, 234, 45, 111, 6, 128 };
	int n = sizeof(array) / sizeof(int);
	cout << "ԭ����" << endl;
	print(array, n);
	cout << "��������" << endl;
	RadixSort(array, n);
	print(array, n);
	
	return 0;
}
