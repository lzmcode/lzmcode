#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#define EASY 0

int mul[13];
char map[][10] = {" /\\ " ,"/__\\"};

void get_pow()
{
	int i ,r;
	mul[0] = 1;
	for(r = 1 ,i = 1 ; i < 13 ;i ++)
	{
		r *= 2;
		mul[i] = r;
	}
}

inline
int mpow(int a ,int b)
{
	return mul[b];
}

char get_out(int size ,int i, int j)
{
	char r = ' ';
	int m = mul[size-1];
	if(size == 1)
	{
		return map[i][j];
	}

#if 0 == EASY
	//Î´»¯¼ò°æ
	if(i < mpow(2 ,size-1) && j >= 4*mpow(2 ,size-2)/2 && j < 4*mpow(2 ,size-2)/2*3)
		r = get_out(size-1 ,i ,j - 4*mpow(2 ,size-2)/2);
	else if(i >= mpow(2 ,size-1) && j < 4*mpow(2 ,size-2))
		r = get_out(size-1 ,i - mpow(2 ,size-1) ,j );
	else if(i >= mpow(2 ,size-1) && j >= 4*mpow(2 ,size-2))
		r = get_out(size-1 ,i - mpow(2 ,size-1) ,j - 4*mpow(2 ,size-2));
#else
	//»¯¼ò°æ
	if(i < m && j >= m && j < (m<<1)+m)
		r = get_out(size-1 ,i ,j - m);
	else if(i >= m && j < m*2)
		r = get_out(size-1 ,i - m ,j );
	else if(i >=m && j >= 2*m)
		r = get_out(size-1 ,i - m ,j - 2*m);
#endif

	return r;
}

int main()
{
	int i ,j ,size ,k;

	get_pow();
	while(cin>>size && 0 != size)
	{
		for(i = 0 ;i < mul[size] ;i ++)
		{
			for(j = 0 ; j < mul[size] + i + 1 ;j ++)
				printf("%c",get_out(size ,i ,j));
			printf("\n");
		}
		cout<<endl;
	}
	
	return 0;
}
