#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	int sum1,sum2,flag;
	int i,j;
	int s1[110],s2[110];
	while (scanf("%d%d",&n,&m)!=EOF && (m!=0) && (n!=0))
	{
		sum1=0; sum2=0; flag=-1;
		for (i=0;i<n;i++)
		{ 
			scanf("%d",&s1[i]);
			sum1+=s1[i];
		} 
		for (i=0;i<m;i++)
		{
			scanf("%d",&s2[i]);
			sum2+=s2[i];
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if ((s1[i]-s2[j])*2==sum1-sum2)
				{
					printf("%d %d\n",s1[i],s2[j]);
					flag=0;
					goto end;
				}
			} 
		}
		end:
		if (flag==-1) printf("-1\n");
	}
	return 0;
}
