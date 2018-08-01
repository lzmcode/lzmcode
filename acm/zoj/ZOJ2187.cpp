#include <iostream>
#include <cstdio>
#include <cstring>
int x[100][100];
int main()
{
	char str[256],ch;
	int m,n,i,j,num;
	while (scanf("%s",&str)!=EOF
		&& strcmp("ENDOFINPUT",str)!=0)
	{
		scanf("%d%d",&m,&n);
		for (i=0;i<m;i++)
		{
			getchar();
			for (j=0;j<n;j++)
			{
				scanf("%c",&ch);
				x[i][j]=ch-'0';
			}
		}
		for (i=0;i<m-1;i++)
		{
			for (j=0;j<n-1;j++)
			{
				num=x[i][j]+x[i+1][j]+x[i][j+1]+x[i+1][j+1];
				printf("%d",num/4); 
			}
			printf("\n");
		}
		scanf("%s",&str);
	}
	return 0;
}
