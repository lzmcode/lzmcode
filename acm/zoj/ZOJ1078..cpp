#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int n,i,j,k,now,sum;
	int m[20][20];
	bool bl,all;
	while (scanf("%d",&n)!=EOF && n!=0)
	{
		memset(m,0,sizeof(m));
		for (i=2;i<=16;i++)
		{
			now=n; j=0; 
			while (now)
			{
				m[i][j++]=now%i;
				now=now/i;
			}

			bl=true;
			for (k=0;k<j/2;k++)
			{
				if (m[i][k]!=m[i][j-k-1])
					bl=false;
			}
			
			if (bl)
				m[i][0]=1;
			else
				m[i][0]=0;
			/*
			for (k=0;k<=16;k++)
				printf("%2d",m[i][k]);
			printf("\n");
			*/
		}
		sum=0;
		for (i=2;i<=16;i++)
			sum+=m[i][0];
		if (sum!=0)
		{
			printf("Number %d is palindrom in basis",n);
			for (i=2;i<=16;i++)
				if (m[i][0]==1)
					printf(" %d",i);
		}
		else printf("Number %d is not a palindrom",n);
		printf("\n");
	}
	return 0;
}
