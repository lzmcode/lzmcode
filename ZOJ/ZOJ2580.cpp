#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdio>
#include<limits.h>
using namespace std;
struct point
{
	int x;
	int y;
};
 
vector <point> V;
int flag;
int sudo [9][9];
void Print();
void Search(int now);
 
int main()
{
	int T;
	int i,i2;
	point temp;
	char temp2;
	scanf ("%d%*c",&T);
	while (T--)
	{
		V.clear();
 
		for(i=0;i<9;i++)
		{
			for (i2=0;i2<9;i2++)
			{
				temp2=getchar();
				sudo[i][i2]=temp2-48;
				if (sudo[i][i2]==0)
				{
					temp.x=i;temp.y=i2;
					V.push_back(temp);
				}
			}
			getchar();
		}
 
		flag=0;
		Search(0);
		Print();	
 
	}
	return 0;
}
 
void Search(int now)
{
	if (now==V.size())   //�ܹ��������һ��˵���������������Ѿ��ҵ��� 
	{
		flag=1;  //��־�Ѿ��ҵ��� 
		return;
	}
 
	int used[10]={0};
	int i;
	int i2;
	for (i=0;i<9;i++)   //ȥ�����������Ѿ�ʹ�ù������� 
	{
		used[sudo[V[now].x][i]]=1;
		used[sudo[i][V[now].y]]=1;
	}
 
	int sx=(V[now].x)/3*3;  //��������С������ʹ�õ����� 
	int sy=(V[now].y)/3*3;  //�õ����ڷ������ʵС�������� 
 
	for (i=sx;i<sx+3;i++)
		for (i2=sy;i2<sy+3;i2++)
			used[sudo[i][i2]]=1;
 
	for (i=1;i<=9&&!flag;i++)
	{
		if (used[i])
			continue;
 
		sudo[V[now].x][V[now].y]=i;
		Search(now+1);		
	}
	if (flag)
		return;
	sudo[V[now].x][V[now].y]=0;
 
}
 
void Print()
{
	int i,i2;
	for (i=0;i<9;i++)
	{
		for (i2=0;i2<9;i2++)
			printf("%d",sudo[i][i2]);
		printf("\n");
	}
}
