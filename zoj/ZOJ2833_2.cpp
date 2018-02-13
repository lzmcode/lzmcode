/*
zoj2833�򵥲��鼯
����Ŀ���⡿
	���ѵ�����Ҳ������ ��n������,mΪ����(M��Q)������ 
	1.M a b��a��b�����ѡ� 
	2.Q a:��a�������� ��
	��ʼʱ��ÿ���˶������ˣ�������Ϊ1�� 
*/
#include <stdio.h>
#define NUM 100005
int set[NUM];
int friends[NUM];

int find(int x)
{
	int i,j,r;
	r=x;
	while(r!=set[r])
		r=set[r];
	i=x;
	while(i!=set[i])
	{
		j=set[i];
		set[i]=r;
		i=j;
	}
	return r;
}

void join(int a,int b)
{
	int af=find(a);
	int bf=find(b);
	if(af!=bf)
	{
		friends[af]+=friends[bf];
		friends[bf]=friends[af];
		set[af]=bf;
	}
}

int main()
{
	int n,m,i,j,a,b;
	int iCase=1,line=0;
	char c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(line)printf("\n");
		line=1;
		printf("Case %d:\n",iCase++);
		for(i=0;i<=n;++i)
		{
			set[i]=i;
			friends[i]=1;
		}
		
		for(i=0;i<m;++i)
		{
			getchar();
			scanf("%c",&c);
			if(c=='M')
			{
				scanf("%d%d",&a,&b);
				join(a,b);
			}
			else
			{
				int x;
				scanf("%d",&x);
				printf("%d\n",friends[find(x)]);
			}
			
		}
	}
	return 0;
}
